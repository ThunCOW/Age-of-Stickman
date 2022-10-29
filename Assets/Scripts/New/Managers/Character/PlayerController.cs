using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using SpineControllerVersion;
using Spine.Unity;
using Spine;

public class PlayerController : UnitController
{
    bool attackTrigger = false;
    bool stunTrigger = false;
    Coroutine triggerCoroutine = null;

    public bool canThrow = true;

    public delegate void OnBossTrigger(string BossTag);
    public static OnBossTrigger BossTrigger;

    public static bool hasPlayerReachedEndOfLevel;

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

        // TODO: Same S1
        canThrow = GameManager.Instance.IsSpearmasterDead;
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

    void MobileController()
    {

    }

    void KeyboardControls()
    {
        // Space Pressed
        if (Input.GetKeyDown(KeyCode.Space))
        {
            attackTrigger = true;
            stunTrigger = false;

            if (triggerCoroutine != null) StopCoroutine(triggerCoroutine);
        }
        // Space Released
        if (Input.GetKeyUp(KeyCode.Space))
        {
            triggerCoroutine = StartCoroutine(ResetAttackTrigger(KeyCode.Space));
        }

        // R pressed
        if (Input.GetKeyDown(KeyCode.R))
        {
            stunTrigger = true;
            attackTrigger = false;

            if (triggerCoroutine != null) StopCoroutine(triggerCoroutine);
        }
        if (Input.GetKeyUp(KeyCode.R))
        {
            triggerCoroutine = StartCoroutine(ResetAttackTrigger(KeyCode.R));
        }

        // Movement Conditions

        // A D Release
        if (Input.GetKeyUp(KeyCode.D) || Input.GetKeyUp(KeyCode.A))
        {
            if (!isAnimationStarted)
            {
                direction = MoveDirection.waiting;

                spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true).TimeScale = 1f;
            }
        }

        // A D Pressed
        if (Input.GetKeyDown(KeyCode.D))
        {
            if (!isAnimationStarted)
            {
                direction = MoveDirection.right;

                SetWalkingAnimation((int)direction);
            }
        }
        if (Input.GetKeyDown(KeyCode.A))
        {
            if (!isAnimationStarted)
            {
                direction = MoveDirection.left;

                SetWalkingAnimation((int)direction);
            }
        }

        // Animation Conditions

        // A D Hold
        // NonStationary Attack
        if (Input.GetKey(KeyCode.A) || Input.GetKey(KeyCode.D))
        {
            // There isn't an animation already playing
            if (!isAnimationStarted)
            {
                if (attackTrigger)
                {
                    List<BasicAnimation> tempWalkAttack = unit.activeAnimations.WalkAttack;

                    int randomAttack = Random.Range(0, tempWalkAttack.Count);
                    currentAttack = tempWalkAttack[randomAttack] as CloseCombatAnimation;

                    spineSkeletonAnimation.state.SetAnimation(1, currentAttack.SpineAnimationReference, false).TimeScale = 1f;

                    AttackAction();
                }
            }
        }
        // Stationary Attack
        else
        {
            // There isn't an animation already playing
            if (!isAnimationStarted)
            {
                if (attackTrigger)
                {
                    List<BasicAnimation> tempStationaryAttack = unit.activeAnimations.Attack;

                    int randomAttack = Random.Range(0, tempStationaryAttack.Count);
                    currentAttack = tempStationaryAttack[randomAttack] as CloseCombatAnimation;

                    spineSkeletonAnimation.state.SetAnimation(1, currentAttack.SpineAnimationReference, false).TimeScale = 1f;

                    AttackAction();
                }
            }
        }

        if (!isAnimationStarted)
        {
            if (stunTrigger)
            {
                List<BasicAnimation> tempStationaryStun = unit.activeAnimations.BreakStance;

                int randomAttack = Random.Range(0, tempStationaryStun.Count);
                BasicAnimation t = tempStationaryStun[randomAttack];
                currentAttack = (CloseCombatAnimation)t;

                spineSkeletonAnimation.state.SetAnimation(1, currentAttack.SpineAnimationReference, false).TimeScale = 1f;

                AttackAction();
            }
        }
        
        // Block Button Action

        if (!isAnimationStarted)
        {
            if (Input.GetKey(KeyCode.S))
            {
                canMove = false;
                blockTrigger = true;

                BasicAnimation blockAnimation = unit.activeAnimations.BlockAttack;

                isAnimationStarted = true;

                spineSkeletonAnimation.state.SetAnimation(1, blockAnimation.SpineAnimationReference, false).TimeScale = 1f;
            }
        }
        // S Released
        if (blockTrigger && Input.GetKeyUp(KeyCode.S))
        {
            canMove = true;
            blockTrigger = false;

            isAnimationStarted = false;

            spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true).TimeScale = 1f;
            spineSkeletonAnimation.state.SetAnimation(2, unit.activeAnimations.ResetSlots.SpineAnimationReference, false).TimeScale = 1f;
        }

        // Weapon Swap Animation

        if (!isAnimationStarted)
        {
            if(Input.GetKey(KeyCode.Q))
            {
                if(unit.activeAnimations.SwapWeapon != null && canThrow)
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

        if(!isAnimationStarted)
        {
            if(Input.GetKey(KeyCode.E))
            {
                if(unit.activeAnimations.ChangeStance.Animation != null && canThrow)
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
    protected IEnumerator WaitForEndOfAnimation(float animationDuration)
    {
        speed = 0f;                                                     // speed is now controlled by speed curve
        isAnimationStarted = true;                                      // prevents direction to become 0 and stop movement

        yield return new WaitForSeconds(animationDuration + 0.05f);  // (not sure) possibly so direction below works

        direction = MoveDirection.waiting;

        speed = defaultSpeed;                                                 // speed is now set to default speed level
        isAnimationStarted = false;                                     // direction released

        // Set new movement direction and look direction
        if (Input.GetKey(KeyCode.A))
        {
            direction = MoveDirection.left;

            SetWalkingAnimation((int)direction);
        }
        else if (Input.GetKey(KeyCode.D))
        {
            direction = MoveDirection.right;

            SetWalkingAnimation((int)direction);
        }

        spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true).TimeScale = 1f;
    }

    //private IEnumerator WaitFor
    protected override void ReStartCoroutines()
    {
        attackTrigger = false;
        stunTrigger = false;

        // Set new movement direction and look direction
        if (Input.GetKey(KeyCode.A))
        {
            direction = MoveDirection.left;

            SetWalkingAnimation((int)direction);
        }
        else if (Input.GetKey(KeyCode.D))
        {
            direction = MoveDirection.right;

            SetWalkingAnimation((int)direction);
        }

        StartCoroutine(CheckDirection());
        //StartCoroutine(GetClosestUnitSearchCycle());
    }
    private IEnumerator CheckDirection()
    {
        yield return new WaitForSeconds(Random.Range(0.1f, 0.25f));

        if (!isAnimationStarted && GameManager.Instance.DisableControls == false)
        {
            // Set new movement direction and look direction
            if (Input.GetKey(KeyCode.A))
            {
                direction = MoveDirection.left;

                SetWalkingAnimation((int)direction);
            }
            else if (Input.GetKey(KeyCode.D))
            {
                direction = MoveDirection.right;

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
                GameManager.Instance.GoldChange(+1);
                Destroy(collision.gameObject);
                SoundManager.Instance.PlayEffect(GameManager.Instance.
                    CoinPickupSound[Random.Range(0, GameManager.Instance.CoinPickupSound.Count)]);
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