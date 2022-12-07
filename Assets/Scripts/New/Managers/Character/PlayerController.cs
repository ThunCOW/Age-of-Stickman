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
    [Header("_____________Distance Bar Variables____________")]
    [SerializeField] private GameObject DistanceBar;
    /*
     * ************************************************************ Movement Control Settings
    */
    [Header("_____________Player Control Variables____________")]
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

    [HideInInspector] public bool canThrow = true;

    public delegate void OnBossTrigger(string BossTag);
    public OnBossTrigger BossTrigger;

    private bool _hasPlayerReachedEndOfLevel;
    public bool hasPlayerReachedEndOfLevel
    {
        get
        {
            return _hasPlayerReachedEndOfLevel;
        }
        set
        {
            _hasPlayerReachedEndOfLevel = value;

            if(_hasPlayerReachedEndOfLevel)
            {
                GameManager.Instance.ContinueToMainMenuTextSpawn();
            }
            else
            {
                GameManager.Instance.ContinueToMainMenuTextDisappear();
            }
        }
    }

    [Space]
    [SerializeField] SpeedDependantAnimation ResurrectAnimation;
    public static bool isWaitingForRes;

    protected override void OnValidate()
    {
        base.OnValidate();
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

        StartCoroutine(CheckDirectionCoroutine());

        if (LeftWallPosition == null || RightWallPosition == null)
            Debug.LogError("Failed to find level borders, make sure they are in scene");

        distanceBarStart = transform.position.x;

        joystickDefaultPositionScreen =  joystickTransform.position;

        // TODO: Same S1
        canThrow = GameManager.Instance.IsSpearmasterDead;

        LoadControls();

        StartCoroutine(InitializeDistanceBar(transform.position.x));

        //SetMixBetweenAnimation(unit.activeAnimations.idle.SpineAnimationReference, unit.activeAnimations.MovementBackward.SpineAnimationReference, 0);
        SetMixBetweenAnimation(unit.activeAnimations.MovementBackward.SpineAnimationReference, unit.activeAnimations.idle.SpineAnimationReference, 0);

        for (int i = 0; i < unit.activeAnimations.BreakStance.Count; i++)
        {
            SetMixBetweenAnimation(unit.activeAnimations.MovementBackward.SpineAnimationReference, unit.activeAnimations.BreakStance[i].SpineAnimationReference, 0);
        }
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

        // Animation Conditions
        if (attackTrigger)
        {
            if (!isAnimationStarted && !blockTrigger)
            {
                // Stationary Attack
                if (direction == MoveDirection.waiting)
                {
                    // There isn't an animation already playing
                    List<BasicAnimation> tempStationaryAttack = unit.activeAnimations.Attack;

                    int randomAttack = UnityEngine.Random.Range(0, tempStationaryAttack.Count);
                    currentAttack = tempStationaryAttack[randomAttack] as CloseCombatAnimation;


                    //spineSkeletonAnimation.AnimationState.Data.SetMix(unit.activeAnimations.idle.SpineAnimationReference.Animation.Name, currentAttack.SpineAnimationReference.Animation.Name, 0.15f);
                    TrackEntry trackEntry = spineSkeletonAnimation.state.SetAnimation(1, currentAttack.SpineAnimationReference, false);

                    AttackAction(trackEntry);

                    if (currentAttack.ShadowAnimation != null)
                        ShadowAnimator.Play(currentAttack.ShadowAnimation.name);
                }
                // NonStationary Attack
                else
                {
                    // There isn't an animation already playing
                    List<BasicAnimation> tempWalkAttack = unit.activeAnimations.WalkAttack;

                    int randomAttack = UnityEngine.Random.Range(0, tempWalkAttack.Count);
                    currentAttack = tempWalkAttack[randomAttack] as CloseCombatAnimation;

                    //spineSkeletonAnimation.AnimationState.Data.SetMix(unit.activeAnimations.Movement.SpineAnimationReference.Animation.Name, unit.activeAnimations.WalkAttack[0].SpineAnimationReference.Animation.Name, 0.15f);
                    TrackEntry trackEntry = spineSkeletonAnimation.state.SetAnimation(1, currentAttack.SpineAnimationReference, false);

                    AttackAction(trackEntry);

                    if (currentAttack.ShadowAnimation != null)
                        ShadowAnimator.Play(currentAttack.ShadowAnimation.name);
                }
            }
        }

        if (stunTrigger)
        {
            if (!isAnimationStarted && !blockTrigger)
            {
                List<BasicAnimation> tempStationaryStun = unit.activeAnimations.BreakStance;

                int randomAttack = UnityEngine.Random.Range(0, tempStationaryStun.Count);
                BasicAnimation t = tempStationaryStun[randomAttack];
                currentAttack = (CloseCombatAnimation)t;

                TrackEntry trackEntry = spineSkeletonAnimation.state.SetAnimation(1, currentAttack.SpineAnimationReference, false);

                AttackAction(trackEntry);

                if (currentAttack.ShadowAnimation != null)
                    ShadowAnimator.Play(currentAttack.ShadowAnimation.name);
            }
        }

        // When there is no boss player movement restricted with walls
        if (!SpawnManager.isBossSpawned)
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
            if (!isAnimationStarted) unit.TurnTowardsTarget();

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
    protected void AttackAction(TrackEntry trackEntry)
    {
        if (unit.target != null)
        {
            unit.TurnTowardsTarget();
        }

        
        AnimationSpeedCurveKeyframeSetup(currentAttack.speedCurve, currentAttack.Keys, currentAttack.Values);
        StartCoroutine(SpeedDuringAnimation(trackEntry, currentAttack.speedCurve));
        //StartCoroutine(WaitForEndOfAnimation(currentAttack.SpineAnimationReference.Animation.Duration));
        //StartCoroutine(WaitForEndOfAnimation(trackEntry));
    }

    protected override void UnitDead(CloseCombatAnimation attack, int attackDirection = 0)
    {
        // Player has no lives ( DEAD )
        if (GameManager.Instance.PlayerLives == 0)
        {
            // Player Dies bring up you are dead screen

            boxCollider2.enabled = false;

            canMove = false;

            int randomDeath = 0;
            List<DeathAnimation> deathAnimation = null;
            DeathAnimation tempDeathAnim = null;
            switch (attack.attackRegion)
            {
                case HitRegion.High:
                    deathAnimation = unit.activeAnimations.DeathAnimationByDamageRegion.highRegion;
                    break;
                case HitRegion.Mid:
                    deathAnimation = unit.activeAnimations.DeathAnimationByDamageRegion.midRegion;
                    break;
                case HitRegion.Low:
                    deathAnimation = unit.activeAnimations.DeathAnimationByDamageRegion.lowRegion;
                    break;
                default:
                    break;
            }
            randomDeath = Random.Range(0, deathAnimation.Count);
            tempDeathAnim = deathAnimation[randomDeath];
            TrackEntry trackEntry = spineSkeletonAnimation.state.SetAnimation(1, tempDeathAnim.SpineAnimationReference, false);

            // Dismember body part
            if (tempDeathAnim is DeathByDismemberAnimation)
                DismemberBody(tempDeathAnim as DeathByDismemberAnimation);
            // Play shadow animation
            if (tempDeathAnim.ShadowAnimation != null)
                ShadowAnimator.Play(tempDeathAnim.ShadowAnimation.name);

            // Play bleeding animation after death animation completes
            StartCoroutine(BloodAnimationAfterDeath(trackEntry, tempDeathAnim));

            /*
             * *
            */


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
        // Player is going to resurrect
        else
        {
            // Player Lives Decreases
            GameManager.Instance.PlayerLivesChange(-1);

            unit.SetUnitDirection(attackDirection * -1);

            StopAllCoroutines();

            StartCoroutine(PlayerDown());
            //return;
        }
    }

    private IEnumerator PlayerDown()
    {
        // Play down animation
        spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.DeathAnimationByDamageRegion.midRegion[0].SpineAnimationReference, false);
        
        boxCollider2.enabled = false;

        canMove = false;

        isWaitingForRes = true;

        isAnimationStarted = true;

        GameManager.Instance.AllyUnits.Remove(unit);

        yield return new WaitForSeconds(3);

        // Resurrect Animation
        TrackEntry trackEntry = spineSkeletonAnimation.state.SetAnimation(1, ResurrectAnimation.SpineAnimationReference, false);
        StartCoroutine(SpeedDuringAnimation(trackEntry, ResurrectAnimation.speedCurve));

        yield return new WaitForSpineAnimationEnd(trackEntry);
        // Wait until resurrection animation ends

        isWaitingForRes = false;

        unit.Health = 1;
        // Player regains control
        boxCollider2.enabled = true;

        isAnimationStarted = false;

        ReStartCoroutines();
        StartCoroutine(unit.GetClosestUnitSearchCycle());
        StartCoroutine(HealthResurrection());
        
        GameManager.Instance.AllyUnits.Add(unit);
        
        canMove = true;

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

            if (unit.Health <= 0)
                unit.Health = 1;

            yield return new WaitForEndOfFrame();
        }
        unit.Health = unit.HealthMax;
    }

    protected override void EndOfAnimation()
    {
        base.EndOfAnimation();

        if (!isAnimationStarted)
        {
            if (!blockTrigger)
            {
                if (moveButton.Hold)
                {
                    direction = moveButton.direction;
                    if (unit.target == null)
                    {
                        transform.localScale = new Vector3((int)direction, transform.localScale.y, transform.localScale.z);
                    }
                    else
                    {
                        unit.TurnTowardsTarget();
                    }
                }

                if (!attackTrigger)
                {
                    // Set new movement direction and look direction
                    if (moveButton.Hold)
                    {
                        SetWalkingAnimation((int)direction);
                    }
                    else
                    {
                        direction = MoveDirection.waiting;

                        spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true).TimeScale = 1f;
                    }
                }
            }
        }
    }

    protected override void StopRoutine()
    {
        base.StopRoutine();

        triggerCoroutine = null;
        DefendButtonCoroutine = null;
        isWeaponSwapOrThrowButtonDown = false;
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

        StartCoroutine(CheckDirectionCoroutine());

        StartCoroutine(InitializeDistanceBar());
        //StartCoroutine(GetClosestUnitSearchCycle());
    }
    private IEnumerator CheckDirectionCoroutine()
    {
        yield return new WaitForSeconds(UnityEngine.Random.Range(0.1f, 0.25f));

        if (!isAnimationStarted && GameManager.Instance.DisableControls == false && !blockTrigger)
        {
            if(moveButton.Hold)
            {
                direction = moveButton.direction;

                SetWalkingAnimation((int)direction);
            }
        }
        StartCoroutine(CheckDirectionCoroutine());
    }

    private float distanceBarStart;
    IEnumerator InitializeDistanceBar(float beginningPoint = 0)
    {
        float endPoint = RightWallPosition.transform.position.x - distanceBarStart;

        while(true)
        {
            DistanceBar.transform.localScale = transform.position.x <= distanceBarStart ? 
                new Vector3(0, 1, 1) : new Vector3((transform.position.x - distanceBarStart) / endPoint, 1, 1);

            yield return new WaitForFixedUpdate();
        }
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
            //Debug.Log(trigger.gameObject.tag);
            if(trigger.gameObject.tag == GameManager.FINISH_LEVEL_TAG)
            {
                if (GameManager.Instance.EnemyUnits.Count != 0)
                {
                    Debug.Log("Defeat All Enemies First");
                    GameManager.Instance.ContinueAfterEnemyDeadTextSpawn();
                }
                else
                {
                    StartCoroutine(EndLevelInTime());
                }
            }
            if(trigger.gameObject.tag == GameManager.SPEARMASTER_SPAWN_TAG)
            {
                trigger.gameObject.SetActive(false);

                BossTrigger(GameManager.SPEARMASTER_SPAWN_TAG);
            }
            else if(trigger.gameObject.tag == GameManager.SCYTHEMASTER_SPAWN_TAG)
            {

                trigger.gameObject.SetActive(false);

                BossTrigger(GameManager.SCYTHEMASTER_SPAWN_TAG);
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

        GameManager.Instance.DisableControls = false;

        GameManager.Instance.SceneLoader.FinishLevel();
    }

    public void DestroySecondaryCanvas()
    {
        Destroy(GameManager.Instance.transform.GetChild(0).gameObject); ;
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

            if (spineSkeletonAnimation.state.GetCurrent(1).Animation != unit.activeAnimations.idle.SpineAnimationReference.Animation && canMove)
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

        if(distance.x / joystickDragOffsetDistance >= 0.8f)
        {
            moveButton.Hold = true;
            moveButton.direction = MoveDirection.right;
        }
        else if(distance.x / joystickDragOffsetDistance <= -0.8f)
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

                if(spineSkeletonAnimation.state.GetCurrent(1).Animation != unit.activeAnimations.idle.SpineAnimationReference.Animation && canMove) 
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

        if (distance.x / joystickDragOffsetDistance >= 0.8f)
        {
            moveButton.Hold = true;
            moveButton.direction = MoveDirection.right;
        }
        else if (distance.x / joystickDragOffsetDistance <= -0.8f)
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

                if (spineSkeletonAnimation.state.GetCurrent(1).Animation != unit.activeAnimations.idle.SpineAnimationReference.Animation && canMove)
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

        if (!isAnimationStarted && !blockTrigger)
        {
            direction = Direction == 1 ? MoveDirection.right : MoveDirection.left;
        
            SetWalkingAnimation((int)direction);
        }
    }
    public void MoveButtonUp()
    {
        moveButton.Hold = false;
        moveButton.direction = MoveDirection.waiting;

        if (!isAnimationStarted)
        {
            direction = MoveDirection.waiting;

            if (!blockTrigger)
            {
                spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true).TimeScale = 1f;
            }
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
    bool DefendButtonCoroutineStarted = false;  // i could not get it to return coroutine on startcoroutine function for some reason
    Coroutine DefendButtonCoroutine;
    public void DefendButtonDown()
    {
        if (DefendButtonCoroutineStarted == false)
        {
            DefendButtonCoroutine = StartCoroutine(DefendButtonHoldDetection());
        }
    }
    IEnumerator DefendButtonHoldDetection()
    {
        DefendButtonCoroutineStarted = true;
        while (isAnimationStarted || GameManager.Instance.DisableControls)
        {
            yield return new WaitForEndOfFrame();
        }
        canMove = false;
        blockTrigger = true;

        BasicAnimation blockAnimation = unit.activeAnimations.BlockAttack;

        spineSkeletonAnimation.state.SetAnimation(1, blockAnimation.SpineAnimationReference, false).TimeScale = 1f;
    }
    public void DefendButtonUp()
    {
        if(blockTrigger)
        {
            canMove = true;
            blockTrigger = false;

            spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true).TimeScale = 1f;
            spineSkeletonAnimation.state.SetAnimation(2, unit.activeAnimations.ResetSlots.SpineAnimationReference, false).TimeScale = 1f;
        }
        else
            StopCoroutine(DefendButtonCoroutine);

        DefendButtonCoroutineStarted = false;
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
    /// ////////////////////////////////// SWAP WEAPON AND THROW SPEAR
    /// </summary>
    private bool isWeaponSwapOrThrowButtonDown = false;                                     // Short click = throw / Long click = swap
    private Coroutine CoroutineWeaponSwapOrThrown;
    public void WeaponSwapOrThrowButtonDown()
    {
        if (!isWeaponSwapOrThrowButtonDown)
            CoroutineWeaponSwapOrThrown = StartCoroutine(WeaponSwapOrThrown());
    }
    public IEnumerator WeaponSwapOrThrown()
    {
        isWeaponSwapOrThrowButtonDown = true;
        
        float timePassed = 0f;
        while (timePassed < 0.3f)
        {
            timePassed += Time.deltaTime;
            yield return new WaitForFixedUpdate();
        }

        WeaponSwapButtonDown();
        StopCoroutine(CoroutineWeaponSwapOrThrown);
        isWeaponSwapOrThrowButtonDown = false;
        CoroutineWeaponSwapOrThrown = null;
    }
    public void WeaponSwapOrThrowButtonUp()
    {
        if (isWeaponSwapOrThrowButtonDown)
        {
            ThrowButtonDown();
            StopCoroutine(CoroutineWeaponSwapOrThrown);
            isWeaponSwapOrThrowButtonDown = false;
            CoroutineWeaponSwapOrThrown = null;
        }
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
                TrackEntry trackEntry = spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.SwapWeapon.SpineAnimationReference, false);

                changeStance = true;

                StartCoroutine(EndOfAnimation(trackEntry));
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
                TrackEntry trackEntry = spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.ChangeStance.Animation.SpineAnimationReference, false);

                changeStance = true;

                StartCoroutine(EndOfAnimation(trackEntry));

                //if (currentAttack.ShadowAnimation != null)
                //    ShadowAnimator.Play(currentAttack.ShadowAnimation.name);
            }
        }
    }











    protected override void DisableControls()
    {
        if (GetComponent<Unit>().Health > 0)
            unit.HealthBar.transform.parent.gameObject.SetActive(false);

        moveButton.Hold = false;
        moveButton.direction = MoveDirection.waiting;
        direction = MoveDirection.waiting;
        triggerCoroutine = null;
        DefendButtonCoroutine = null;

        idleing = false;

        isAnimationStarted = true;                                     // direction released (for player)

        spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true);
    }

    protected override void EnableControls()
    {
        if (GetComponent<Unit>().Health > 0)
            unit.HealthBar.transform.parent.gameObject.SetActive(true);

        idleing = true;

        isAnimationStarted = false;                                     // direction released (for player)
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

            case "Game Event/Spearmaster_Dead":
                GameManager.Instance.IsSpearmasterDead = true;
                GameManager.Instance.Player.GetComponent<EquipmentManager>().ShowSecondaryWeapon();
                GameManager.Instance.Player.currentStance = StanceList.Stand_B;
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