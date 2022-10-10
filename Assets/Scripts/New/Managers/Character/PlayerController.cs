using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using SpineControllerVersion;

public class PlayerController : UnitController
{
    public Transform LeftWallPosition;
    public Transform RightWallPosition;

    void OnValidate()
    {
        if (LeftWallPosition == null || RightWallPosition == null)
        {
            GameObject go = GameObject.FindGameObjectWithTag("LevelBorders");
            if(go != null)
            {
                LeftWallPosition = go.transform.GetChild(0);
                RightWallPosition = go.transform.GetChild(1);
            }
        }
    }

    // Start is called before the first frame update
    protected override void Start()
    {
        base.Start();

        GameManager.Instance.Player = unit;

        StartCoroutine(CheckDirection());

        if (LeftWallPosition == null || RightWallPosition == null)
            Debug.LogError("Failed to find level borders, make sure they are in scene");
    }

    protected override void CharacterControls()
    {
        KeyboardControls();

        if(gameObject.transform.position.x <= LeftWallPosition.position.x)
        {
            if (direction == MoveDirection.left)
                direction = MoveDirection.waiting;
        }
        if(gameObject.transform.position.x >= RightWallPosition.position.x)
        {
            if (direction == MoveDirection.right)
                direction = MoveDirection.waiting;
        }
    }

    void MobileController()
    {

    }

    bool attackTrigger = false;
    bool stunTrigger = false;
    bool blockTrigger = false;
    Coroutine triggerCoroutine = null;
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

        // F pressed
        if(Input.GetKeyDown(KeyCode.F))
        {
            blockTrigger = true;

            //if(triggerCoroutine != null) StopCoroutine()
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

        if (!isAnimationStarted)
        {
            if (Input.GetKey(KeyCode.F))
            {
                BasicAnimation blockAnimation = unit.activeAnimations.BlockAttack;

                isAnimationStarted = true;

                spineSkeletonAnimation.state.SetAnimation(1, blockAnimation.SpineAnimationReference, false).TimeScale = 1f;
            }
        }
        // Space Released
        if (Input.GetKeyUp(KeyCode.F))
        {
            isAnimationStarted = false;

            spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, false).TimeScale = 1f;
            spineSkeletonAnimation.state.SetAnimation(2, unit.activeAnimations.ResetSlots.SpineAnimationReference, false).TimeScale = 1f;
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

        speed = speed_;                                                 // speed is now set to default speed level
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

        if (!isAnimationStarted)
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
        if(collision.gameObject.tag == GameManager.Instance.GOLD_TAG)
        {
            if (gameObject.tag == GameManager.Instance.PLAYER_TAG)
            {
                GameManager.Instance.GoldChange(+1);
                Destroy(collision.gameObject);
                SoundManager.Instance.PlayEffect(GameManager.Instance.
                    CoinPickupSound[Random.Range(0, GameManager.Instance.CoinPickupSound.Count)]);
            }
        }
    }
}