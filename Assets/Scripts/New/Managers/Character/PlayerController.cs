using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using SpineControllerVersion;
using Spine;
using UnityEngine.EventSystems;
using UnityEngine.UI;
using Spine.Unity;

public class PlayerController : UnitController, IPointerDownHandler, IPointerUpHandler, IDragHandler
{
    /*
     * ************************************************************ Movement Control Settings
    */
    [SerializeField] private RectTransform joystickTransform;

    private Vector3 joystickDefaultPositionScreen;
    [SerializeField] private int joystickDragOffsetDistance;

    public GameObject ArrowControls;
    public GameObject JoystickControls;
    /*
     * ************************************************************ 
    */
    bool attackTrigger = false;
    bool stunTrigger = false;
    Coroutine triggerCoroutine = null;

    public bool canThrow = true;

    public delegate void OnBossTrigger(string BossTag);
    public static OnBossTrigger BossTrigger;

    public static bool hasPlayerReachedEndOfLevel;

    [SerializeField] SpeedDependantAnimation ResurrectAnimation;

    void OnValidate()
    {
        /*if (LeftWallPosition == null || RightWallPosition == null)
        {
            GameObject go = GameObject.FindGameObjectWithTag("LevelBorders");
            if(go != null)
            {
                LeftWallPosition = go.transform.GetChild(0);
                RightWallPosition = go.transform.GetChild(1);
            }
        }*/
    }

    // Start is called before the first frame update
    protected override void Start()
    {
        base.Start();

        GameManager.Instance.Player = unit;

        StartCoroutine(CheckDirection());

        if (LeftWallPosition == null || RightWallPosition == null)
            Debug.LogError("Failed to find level borders, make sure they are in scene");

        joystickDefaultPositionScreen =  joystickTransform.position;

        // TODO: Same S1
        canThrow = GameManager.Instance.IsSpearmasterDead;

        LoadControls();
    }

    public void LoadControls()
    {
        switch (GameManager.Instance.PlayerControls)
        {
            case PlayerControls.JoystickControls:
                ArrowControls.SetActive(false);
                JoystickControls.SetActive(true);
                break;
            case PlayerControls.ArrowControls:
                JoystickControls.SetActive(false);
                ArrowControls.SetActive(true);
                break;
            case PlayerControls.Keyboard:
                ArrowControls.SetActive(false);
                JoystickControls.SetActive(false);
                break;
            default:
                break;
        }
    }

    protected override void CharacterControls()
    {
        KeyboardControls();

        if(!SpawnManager.isBossSpawned)
        {
            if(gameObject.transform.position.x <= LeftWallPosition.position.x)
            {
                if (direction == MoveDirection.left)
                    direction = MoveDirection.waiting;
            }
            if(gameObject.transform.position.x >= RightWallPosition.position.x + 3)
            {
                if (direction == MoveDirection.right)
                    direction = MoveDirection.waiting;
            }
        }
    }
    
    void KeyboardControls()
    {
        // Space Pressed
        if (Input.GetKeyDown(KeyCode.Space))
        {
            AttackButtonDown();
        }
        // Space Released
        if (Input.GetKeyUp(KeyCode.Space))
        {
            AttackButtonUp();
        }

        // R pressed
        if (Input.GetKeyDown(KeyCode.R))
        {
            StunButtonDown();
        }
        if (Input.GetKeyUp(KeyCode.R))
        {
            StunButtonUp();
        }

        // Movement Conditions

        // A D Release
        if (Input.GetKeyUp(KeyCode.D) || Input.GetKeyUp(KeyCode.A))
        {
            MoveButtonUp();
        }

        // A D Pressed
        if (Input.GetKeyDown(KeyCode.D))
        {
            MoveButtonDown(((int)MoveDirection.right));
        }
        if (Input.GetKeyDown(KeyCode.A))
        {
            MoveButtonDown(((int)MoveDirection.left));
        }

        // Animation Conditions
        if (attackTrigger)
        {
            if (!isAnimationStarted)
            {
                // Stationary Attack
                if (direction == MoveDirection.waiting)
                {
                // There isn't an animation already playing
                    List<BasicAnimation> tempStationaryAttack = unit.activeAnimations.Attack;

                    int randomAttack = UnityEngine.Random.Range(0, tempStationaryAttack.Count);
                    currentAttack = tempStationaryAttack[randomAttack] as CloseCombatAnimation;

                    spineSkeletonAnimation.state.SetAnimation(1, currentAttack.SpineAnimationReference, false).TimeScale = 1f;

                    AttackAction();
                }
                // NonStationary Attack
                else
                {
                    // There isn't an animation already playing
                    List<BasicAnimation> tempWalkAttack = unit.activeAnimations.WalkAttack;

                    int randomAttack = UnityEngine.Random.Range(0, tempWalkAttack.Count);
                    currentAttack = tempWalkAttack[randomAttack] as CloseCombatAnimation;

                    spineSkeletonAnimation.state.SetAnimation(1, currentAttack.SpineAnimationReference, false).TimeScale = 1f;

                    AttackAction();
                }
            }
        }

        if (stunTrigger)
        {
            if (!isAnimationStarted)
            {
                List<BasicAnimation> tempStationaryStun = unit.activeAnimations.BreakStance;

                int randomAttack = UnityEngine.Random.Range(0, tempStationaryStun.Count);
                BasicAnimation t = tempStationaryStun[randomAttack];
                currentAttack = (CloseCombatAnimation)t;

                spineSkeletonAnimation.state.SetAnimation(1, currentAttack.SpineAnimationReference, false).TimeScale = 1f;

                AttackAction();
            }
        }
        


        // Block Button Action
        if (Input.GetKey(KeyCode.S))
        {
            DefendButtonDown();
        }
        // S Released
        if (blockTrigger && Input.GetKeyUp(KeyCode.S))
        {
            DefendButtonUp();
        }

        // Weapon Swap Animation

        if(Input.GetKey(KeyCode.Q))
        {
            WeaponSwapButtonDown();
        }

        if(Input.GetKey(KeyCode.E))
        {
            ThrowButtonDown();
        }
    }

    // Walking animation depends on the direction unit is facing
    void SetWalkingAnimation(int dir)
    {
        if (unit.target == null)
        {
            if (!isAnimationStarted) transform.localScale = new Vector3(dir, transform.localScale.y, transform.localScale.z);

            if (spineSkeletonAnimation.state.GetCurrent(1).Animation != unit.activeAnimations.Movement.SpineAnimationReference.Animation)
                spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.Movement.SpineAnimationReference, true).TimeScale = 1f;
        }
        else
        {
            if (!isAnimationStarted) unit.CheckUnitDirection();

            if (dir == (int)MoveDirection.right)
            {
                if (transform.position.x > unit.target.transform.position.x)
                {
                    if (spineSkeletonAnimation.state.GetCurrent(1).Animation != unit.activeAnimations.MovementBackward.SpineAnimationReference.Animation)
                        spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.MovementBackward.SpineAnimationReference, true).TimeScale = 1f;
                }
                else
                {
                    if (spineSkeletonAnimation.state.GetCurrent(1).Animation != unit.activeAnimations.Movement.SpineAnimationReference.Animation)
                        spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.Movement.SpineAnimationReference, true).TimeScale = 1f;
                }
            }
            else
            {
                if (transform.position.x > unit.target.transform.position.x)
                {
                    if (spineSkeletonAnimation.state.GetCurrent(1).Animation != unit.activeAnimations.Movement.SpineAnimationReference.Animation)
                        spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.Movement.SpineAnimationReference, true).TimeScale = 1f;
                }
                else
                {
                    if (spineSkeletonAnimation.state.GetCurrent(1).Animation != unit.activeAnimations.MovementBackward.SpineAnimationReference.Animation)
                        spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.MovementBackward.SpineAnimationReference, true).TimeScale = 1f;
                }
            }
        }
    }
    private IEnumerator ResetAttackTrigger(KeyCode keyCode)
    {
        yield return new WaitForSeconds(0.25f);

        switch (keyCode)
        {
            case KeyCode.Space:
                attackTrigger = false;
                break;
            case KeyCode.R:
                stunTrigger = false;
                break;
        }
    }
    protected void AttackAction()
    {
        //
        if (unit.target != null)
        {
            unit.CheckUnitDirection();
        }

        StartCoroutine(SpeedDuringAnimation(currentAttack));
        StartCoroutine(WaitForEndOfAnimation(currentAttack.SpineAnimationReference.Animation.Duration));
    }

    public override void TakeDamage(CloseCombatAnimation attack, int DamageTaken, int attackDirection = 0)
    {
        if (blockTrigger)
        {
            SoundManager.Instance.PlayEffect(SoundManager.Instance.ShieldHitSound[Random.Range(0, SoundManager.Instance.ShieldHitSound.Count)]);

            return;
        }
        if (resurrectionState)
        {
            attack.SoundObject.hitSoundEffect.PlayRandomSoundEffect();

            return;
        }

        attack.SoundObject.hitSoundEffect.PlayRandomSoundEffect();

        unit.Health -= DamageTaken;
        if (unit.Health <= 0)
        {
            if (GameManager.Instance.PlayerLives == 0)
            {
                // Player Dies bring up you are dead screen
                
                boxCollider2.enabled = false;
                
                canMove = false;

                int randomDeath = 0;
                List<DeathAnimation> deathAnimation;
                DeathAnimation tempDeathAnim = null;
                switch (attack.attackRegion)
                {
                    case HitRegion.High:
                        deathAnimation = unit.activeAnimations.DeathAnimationByDamageRegion.highRegion;
                        randomDeath = Random.Range(0, deathAnimation.Count);
                        tempDeathAnim = deathAnimation[randomDeath];
                        spineSkeletonAnimation.state.SetAnimation(1, tempDeathAnim.SpineAnimationReference, false).TimeScale = 1f;
                        break;
                    case HitRegion.Mid:
                        deathAnimation = unit.activeAnimations.DeathAnimationByDamageRegion.midRegion;
                        randomDeath = Random.Range(0, deathAnimation.Count);
                        tempDeathAnim = deathAnimation[randomDeath];
                        spineSkeletonAnimation.state.SetAnimation(1, tempDeathAnim.SpineAnimationReference, false).TimeScale = 1f;
                        break;
                    case HitRegion.Low:
                        deathAnimation = unit.activeAnimations.DeathAnimationByDamageRegion.lowRegion;
                        randomDeath = Random.Range(0, deathAnimation.Count);
                        tempDeathAnim = deathAnimation[randomDeath];
                        spineSkeletonAnimation.state.SetAnimation(1, tempDeathAnim.SpineAnimationReference, false).TimeScale = 1f;
                        break;
                    default:
                        break;
                }
                if (tempDeathAnim is DeathByDismemberAnimation)
                    DismemberBody(tempDeathAnim as DeathByDismemberAnimation);


                if (Unit.CompareTags(gameObject, GameManager.ENEMY_TAGS))
                {
                    GameManager.Instance.EnemyUnits.Remove(unit);
                    // TODO LeftSpawnLazy Count leftspawns, if they enter combat remove from list, max 2 leftspawn, add to list in SpawnManager
                    GameManager.Instance.LeftSpawn.Remove(gameObject);
                }
                else
                    GameManager.Instance.AllyUnits.Remove(unit);

                GameManager.Instance.sortManager.RemoveFromOrder(unit);
            }
            else
            {
                // Player Lives Decreases
                GameManager.Instance.PlayerLivesChange(-1);

                unit.CheckUnitDirection();
                StopAllCoroutines();

                StartCoroutine(PlayerDown());
                return;
            }
        }
        else if (unit.activeAnimations.Hurt == null)
        {
            if (attack.attackType == AttackType.Casual)
            {
                // boss dont stop movement in hits
            }
            else
            {
                unit.CheckUnitDirection();

                StopAllCoroutines();
                StartCoroutine(StunnedFor(attack));
            }
        }
        else
        {
            unit.CheckUnitDirection();

            StopAllCoroutines();
            StartCoroutine(StunnedFor(attack));
        }

        if (attack.attackType != AttackType.Kick && attack.attackType != AttackType.Shield)
        {
            GameObject blood_go = Instantiate(unit.bloodObject);
            blood_go.transform.position = new Vector3(transform.position.x, attack.hitHeightPosiiton, unit.bloodObject.transform.position.z);
        }

        // TODO LeftSpawnLazy Count leftspawns, if they enter combat remove from list, max 2 leftspawn, add to list in SpawnManager
        if (CompareTag(GameManager.ENEMY_TAG))
            GameManager.Instance.LeftSpawn.Remove(gameObject);
    }

    private IEnumerator PlayerDown()
    {
        // Play down animation
        spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.DeathAnimationByDamageRegion.midRegion[0].SpineAnimationReference, false);
        
        boxCollider2.enabled = false;

        canMove = false;

        GameManager.Instance.AllyUnits.Remove(unit);

        yield return new WaitForSeconds(3);

        // Resurrect Animation
        TrackEntry track = spineSkeletonAnimation.state.SetAnimation(1, ResurrectAnimation.SpineAnimationReference, false);
        StartCoroutine(SpeedDuringAnimation(ResurrectAnimation));
        
        yield return new WaitForSpineAnimationEnd(track);
        // Wait until resurrection animation ends

        unit.Health = 1;
        // Player regains control
        boxCollider2.enabled = true;

        ReStartCoroutines();
        StartCoroutine(unit.GetClosestUnitSearchCycle());
        StartCoroutine(HealthResurrection());
        canMove = true;

        GameManager.Instance.AllyUnits.Add(unit);

        resurrectionState = true;

        // Play untouchble animation
        yield return new WaitForSeconds(6);
        resurrectionState = false;
    }

    private IEnumerator HealthResurrection()
    {
        // 0.5 seconds to get health back to 100% 
        // 0.5 * 1000/5 ___ 200 * time
        float countdown = 0;
        yield return new WaitForEndOfFrame();
        while(unit.Health < unit.HealthMax || countdown < 0.5f)
        {
            countdown += Time.deltaTime;
            
            float percentage = countdown / 0.5f;
            
            unit.Health = ((int)(unit.HealthMax * percentage));
            
            yield return new WaitForEndOfFrame();
        }
        unit.Health = unit.HealthMax;
    }

    

    protected IEnumerator WaitForEndOfAnimation(float animationDuration)
    {
        speed = 0f;                                                     // speed is now controlled by speed curve
        isAnimationStarted = true;                                      // prevents direction to become 0 and stop movement

        yield return new WaitForSeconds(animationDuration + 0.05f);  // (not sure) possibly so direction below works

        direction = MoveDirection.waiting;

        speed = defaultSpeed;                                                 // speed is now set to default speed level
        isAnimationStarted = false;                                     // direction released

        // Set new movement direction and look direction
        if (moveButton.Hold)
        {
            direction = moveButton.direction;

            SetWalkingAnimation((int)direction);
        }
        else
        {
            spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true).TimeScale = 1f;
        }
    }

    protected override void ReStartCoroutines()
    {
        attackTrigger = false;
        stunTrigger = false;

        // Set new movement direction and look direction
        if (moveButton.Hold)
        {
            direction = moveButton.direction;

            SetWalkingAnimation((int)direction);
        }

        StartCoroutine(CheckDirection());
        //StartCoroutine(GetClosestUnitSearchCycle());
    }
    private IEnumerator CheckDirection()
    {
        yield return new WaitForSeconds(UnityEngine.Random.Range(0.1f, 0.25f));

        if (!isAnimationStarted && GameManager.Instance.DisableControls == false)
        {
            if(moveButton.Hold)
            {
                direction = moveButton.direction;

                SetWalkingAnimation((int)direction);
            }
        }

        StartCoroutine(CheckDirection());
    }


    void OnCollisionEnter2D(Collision2D collision)
    {
        if (gameObject.tag == GameManager.PLAYER_TAG)
        {
            if (collision.gameObject.tag == GameManager.GOLD_TAG)
            {
                GameManager.Instance.GoldGained++;
                Destroy(collision.gameObject);
                SoundManager.Instance.PlayEffect(GameManager.Instance.
                    CoinPickupSound[UnityEngine.Random.Range(0, GameManager.Instance.CoinPickupSound.Count)]);
            }
        }
    }

    void OnTriggerEnter2D(Collider2D trigger)
    {
        if(gameObject.tag == GameManager.PLAYER_TAG)
        {
            if(trigger.gameObject.tag == GameManager.FINISH_LEVEL_TAG)
            {
                if (GameManager.Instance.EnemyUnits.Count != 0)
                {
                    Debug.Log("Defeat All Enemies First");
                }
                else
                {
                    StartCoroutine(EndLevelInTime());
                }
            }
            if(trigger.gameObject.tag == GameManager.SPEARMASTER_SPAWN_TAG)
            {
                trigger.gameObject.SetActive(false);

                BossTrigger(GameManager.SPEARMASTER_TAG);
            }
        }
    }

    IEnumerator EndLevelInTime()
    {
        GameManager.Instance.DisableControls = true;

        speed = defaultSpeed;

        direction = MoveDirection.right;

        spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.Movement.SpineAnimationReference, true);

        yield return new WaitForSeconds(2.5f);
        
        GameManager.Instance.SceneLoader.FinishLevel();
    }













    /// <summary>
    /// /////////////////////////////////////// Joystick
    /// </summary>
    public void OnPointerUp(PointerEventData eventData)
    {
        joystickTransform.anchoredPosition = Vector2.zero;

        moveButton.Hold = false;

        if (!isAnimationStarted)
        {
            direction = MoveDirection.waiting;

            if (spineSkeletonAnimation.AnimationName != unit.activeAnimations.idle.SpineAnimationReference.name) 
                spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true).TimeScale = 1f;
        }
    }

    public void OnDrag(PointerEventData eventData)
    {
        // eventData.position gives click(pointer) screen position, joystickDefaultPositionScreen is UI joystick screen position, take the difference to calculate distance from center
        Vector3 screenPos = new Vector3(eventData.position.x - joystickDefaultPositionScreen.x, eventData.position.y - joystickDefaultPositionScreen.y, 0);

        // clamp it to desired offset if bigger than it is
        Vector3 distance = Vector3.ClampMagnitude(screenPos, joystickDragOffsetDistance);

        // new position is default position(center of circle) + calculated distance
        Vector3 newPos = joystickDefaultPositionScreen + distance;

        // Limit Y increase to 0.6 out of 1 for look
        if(distance.y / joystickDragOffsetDistance > 0)
            newPos = new Vector3(newPos.x, joystickDefaultPositionScreen.y + distance.y * 0.25f, newPos.z);
        else if(distance.y / joystickDragOffsetDistance < 0)
            newPos = new Vector3(newPos.x, joystickDefaultPositionScreen.y + distance.y * 0.25f, newPos.z);

        // set Joystick position 
        joystickTransform.position = newPos;

        if(distance.x / joystickDragOffsetDistance >= 0.3f)
        {
            moveButton.Hold = true;
            moveButton.direction = MoveDirection.right;
        }
        else if(distance.x / joystickDragOffsetDistance <= -0.3f)
        {
            moveButton.Hold = true;
            moveButton.direction = MoveDirection.left;
        }
        else
        {
            moveButton.Hold = false;

            if (!isAnimationStarted)
            {
                direction = MoveDirection.waiting;

                if(spineSkeletonAnimation.AnimationName != unit.activeAnimations.idle.SpineAnimationReference.name) 
                    spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true).TimeScale = 1f;
            }
        }
    }

    public void OnPointerDown(PointerEventData eventData)
    {
        // eventData.position gives click(pointer) screen position, joystickDefaultPositionScreen is UI joystick screen position, take the difference to calculate distance from center
        Vector3 screenPos = new Vector3(eventData.position.x - joystickDefaultPositionScreen.x, eventData.position.y - joystickDefaultPositionScreen.y, 0);

        // clamp it to desired offset if bigger than it is
        Vector3 distance = Vector3.ClampMagnitude(screenPos, joystickDragOffsetDistance);

        // new position is default position(center of circle) + calculated distance
        Vector3 newPos = joystickDefaultPositionScreen + distance;

        // Limit Y increase to 0.6 out of 1 for look
        if (distance.y / joystickDragOffsetDistance > 0)
            newPos = new Vector3(newPos.x, joystickDefaultPositionScreen.y + distance.y * 0.25f, newPos.z);
        else if (distance.y / joystickDragOffsetDistance < 0)
            newPos = new Vector3(newPos.x, joystickDefaultPositionScreen.y + distance.y * 0.25f, newPos.z);

        // set Joystick position 
        joystickTransform.position = newPos;

        if (distance.x / joystickDragOffsetDistance >= 0.3f)
        {
            moveButton.Hold = true;
            moveButton.direction = MoveDirection.right;
        }
        else if (distance.x / joystickDragOffsetDistance <= -0.3f)
        {
            moveButton.Hold = true;
            moveButton.direction = MoveDirection.left;
        }
        else
        {
            moveButton.Hold = false;

            if (!isAnimationStarted)
            {
                direction = MoveDirection.waiting;

                if (spineSkeletonAnimation.AnimationName != unit.activeAnimations.idle.SpineAnimationReference.name)
                    spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true).TimeScale = 1f;
            }
        }
    }















    /// <summary>
    /// /////////////////////////////////// Buttons - Movement
    /// </summary>
    class ButtonHold
    {
        public bool Hold;
    }
    class MovementButtonHold : ButtonHold
    {
        public MoveDirection direction;
    }
    MovementButtonHold moveButton = new MovementButtonHold();
    public void MoveButtonDown(int Direction)
    {
        moveButton.Hold = true;
        moveButton.direction = Direction == 1 ? MoveDirection.right : MoveDirection.left;

        if (!isAnimationStarted)
        {
            direction = Direction == 1 ? MoveDirection.right : MoveDirection.left;
        
            SetWalkingAnimation((int)direction);
        }
    }
    public void MoveButtonUp()
    {
        moveButton.Hold = false;

        if (!isAnimationStarted)
        {
            direction = MoveDirection.waiting;
        
            spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true).TimeScale = 1f;
        }
    }


    /// <summary>
    /// /////////////////////////////////// Attack
    /// </summary>
    public void AttackButtonDown()
    {
        attackTrigger = true;
        stunTrigger = false;

        if (triggerCoroutine != null) StopCoroutine(triggerCoroutine);
    }
    public void AttackButtonUp()
    {
        triggerCoroutine = StartCoroutine(ResetAttackTrigger(KeyCode.Space));
    }

    /// <summary>
    /// //////////////////////////////////// Defend
    /// </summary>
    Coroutine DefendButtonCoroutine;
    public void DefendButtonDown()
    {
        DefendButtonCoroutine = StartCoroutine(DefendButtonHoldDetection());
        if (!isAnimationStarted)
        {
            canMove = false;
            blockTrigger = true;

            BasicAnimation blockAnimation = unit.activeAnimations.BlockAttack;

            isAnimationStarted = true;

            spineSkeletonAnimation.state.SetAnimation(1, blockAnimation.SpineAnimationReference, false).TimeScale = 1f;
        }
    }
    public void DefendButtonUp()
    {
        if(blockTrigger)
        {
            canMove = true;
            blockTrigger = false;

            isAnimationStarted = false;

            spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true).TimeScale = 1f;
            spineSkeletonAnimation.state.SetAnimation(2, unit.activeAnimations.ResetSlots.SpineAnimationReference, false).TimeScale = 1f;
        }
        else
            StopCoroutine(DefendButtonCoroutine);
    }

    IEnumerator DefendButtonHoldDetection()
    {
        while(isAnimationStarted)
        {
            yield return new WaitForEndOfFrame();
        }
        canMove = false;
        blockTrigger = true;

        BasicAnimation blockAnimation = unit.activeAnimations.BlockAttack;

        isAnimationStarted = true;

        spineSkeletonAnimation.state.SetAnimation(1, blockAnimation.SpineAnimationReference, false).TimeScale = 1f;
    }

    /// <summary>
    /// ///////////////////////////////////// Kick
    /// </summary>
    public void StunButtonDown()
    {
        stunTrigger = true;
        attackTrigger = false;

        if (triggerCoroutine != null) StopCoroutine(triggerCoroutine);
    }
    public void StunButtonUp()
    {
        triggerCoroutine = StartCoroutine(ResetAttackTrigger(KeyCode.R));
    }

    /// <summary>
    /// /////////////////////////////////// SWAP WEAPON
    /// </summary>
    public void WeaponSwapButtonDown()
    {
        if (!isAnimationStarted)
        {
            if (unit.activeAnimations.SwapWeapon != null && canThrow)
            {
                spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.SwapWeapon.SpineAnimationReference, false).TimeScale = 1f;

                StartCoroutine(WaitForEndOfAnimation(unit.activeAnimations.SwapWeapon.SpineAnimationReference.Animation.Duration));

                if (unit.currentStance == StanceList.Stand_A)
                    unit.currentStance = StanceList.Stand_B;
                else if (unit.currentStance == StanceList.Stand_B)
                    unit.currentStance = StanceList.Stand_A;
            }
        }
    }

    /// <summary>
    /// ///////////////////////////////////// THROW WEAPON
    /// </summary>
    public void ThrowButtonDown()
    {
        if (!isAnimationStarted)
        {
            if (unit.activeAnimations.ChangeStance.Animation != null && canThrow)
            {
                spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.ChangeStance.Animation.SpineAnimationReference, false).TimeScale = 1f;

                StartCoroutine(WaitForEndOfAnimation(unit.activeAnimations.ChangeStance.Animation.SpineAnimationReference.Animation.Duration));

                if (unit.currentStance == StanceList.Stand_A)
                    unit.currentStance = StanceList.Stand_B;
                else if (unit.currentStance == StanceList.Stand_B)
                    unit.currentStance = StanceList.Stand_A;
            }
        }
    }












    protected override void HandleAnimationStateEvent(TrackEntry trackEntry, Spine.Event e)
    {
        base.HandleAnimationStateEvent(trackEntry, e);

        switch (e.Data.Name)
        {
            case "Weapon Triggers/WeaponSecondary_Hide_Front":
                canThrow = false;
                break;
            case "Weapon Triggers/WeaponSecondary_CanThrow":
                canThrow = true;
                break;
            default:
                break;
        }
    }
}

public enum PlayerControls
{
    JoystickControls,
    ArrowControls,
    Keyboard
}