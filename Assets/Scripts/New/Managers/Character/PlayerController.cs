using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using SpineControllerVersion;
using Spine;
using System;
using UnityEngine.EventSystems;
using UnityEngine.UI;

public class PlayerController : UnitController//, IPointerDownHandler, IPointerUpHandler, IDragHandler
{
    [SerializeField] private RectTransform joystickTransform;

    [SerializeField] private float dragThreshold = 0.6f;
    [SerializeField] private int dragMovementDistance = 85;
    [SerializeField] private int dragOffsetDistance = 100;

    public event Action<Vector2> OnMove;

    public Button button;
    /// <summary>
    /// ////////////////////////////////////////////////////////////////////////////
    /// </summary>
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
            // Stationary Attack
            if (direction == MoveDirection.waiting)
            {
                // There isn't an animation already playing
                if (!isAnimationStarted)
                {
                    List<BasicAnimation> tempStationaryAttack = unit.activeAnimations.Attack;

                    int randomAttack = UnityEngine.Random.Range(0, tempStationaryAttack.Count);
                    currentAttack = tempStationaryAttack[randomAttack] as CloseCombatAnimation;

                    spineSkeletonAnimation.state.SetAnimation(1, currentAttack.SpineAnimationReference, false).TimeScale = 1f;

                    AttackAction();
                }
            }
            // NonStationary Attack
            else
            {
                // There isn't an animation already playing
                if (!isAnimationStarted)
                {
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
    }

    public void OnDrag(PointerEventData eventData)
    {
        Vector2 offset;
        RectTransformUtility.ScreenPointToLocalPointInRectangle(joystickTransform, eventData.position, null, out offset);

        offset = Vector2.ClampMagnitude(offset, dragOffsetDistance);
        joystickTransform.anchoredPosition = offset;
    }

    public void OnPointerDown(PointerEventData eventData)
    {

    }















    /// <summary>
    /// /////////////////////////////////// Buttons - Movement
    /// </summary>
    class MoveButton
    {
        public bool Hold;
        public MoveDirection direction;
    }
    MoveButton moveButton = new MoveButton();
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
    public void DefendButtonDown()
    {
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