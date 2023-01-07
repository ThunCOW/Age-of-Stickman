using SpineControllerVersion;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AllyController : AIController
{
    public float DistanceToPlayer;
    MoveDirection directionToPlayer;

    // Delegate
    public delegate void OnMercenaryDead(MercenaryUnit mercenaryUnit, AllyController allyController);
    public OnMercenaryDead MercenaryDead;

    public MercenaryUnit mercenaryUnit;

    protected override void Start()
    {
        base.Start();

    }
    protected override void AIStart()
    {
        ScreenLeftBorder = GameManager.Instance.SceneViewBordersParent.transform.GetChild(0);
        ScreenRightBorder = GameManager.Instance.SceneViewBordersParent.transform.GetChild(1);

        StartCoroutine(AIActionDecision());

        StartCoroutine(SuperDumbStopMovementWhenPlayerDiesCheck());
    }

    protected override void CharacterControls()
    {
        // If out of screen view and controlled by animation, we want to increase speed
        if (speed != 0)
        {
            if (transform.position.x < GameManager.Instance.Player.transform.position.x)
            {
                if (transform.position.x < GameManager.Instance.SceneViewBordersParent.transform.GetChild(0).transform.position.x)
                {
                    speed = 5;
                    return;
                }
                else
                {
                    speed = defaultSpeed;
                }
            }
            else if (transform.position.x > GameManager.Instance.Player.transform.position.x)
            {
                if (transform.position.x > GameManager.Instance.SceneViewBordersParent.transform.GetChild(1).transform.position.x)
                {
                    speed = 5;
                    return;
                }
                else
                {
                    speed = defaultSpeed;
                }
            }
        }
        AIMovement();
    }

    // runs all the time
    private void AIMovement()
    {
        if (unit.target != null)
        {
            if (speed != 0)                                                                  // speed equals to zero means speed is controlled by speed curve for animation
            {
                speed = defaultSpeed;
            }

            // if a unit has gotten enough close or extra closer to target than it was determinted to, ready for next action ( Basically idleing )
            if (Mathf.Abs(transform.position.x - unit.target.transform.position.x) <= newDistanceToTarget)
            {
                float waitTime = Random.Range(0, aiVariable.maxWaitAfterMovement / 2);
                waitTime += Random.Range(0, aiVariable.maxWaitAfterMovement / 2);

                // activated during MoveAndAttack session, walking happens here so it does not trigger twice
                if (preparingAttack == false)
                {
                    StartCoroutine(AIActionDecision(waitTime));
                    idleing = true;
                }

                direction = MoveDirection.waiting;
                spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true).TimeScale = 1f;

                newDistanceToTarget = 0;
            }
        }
    }

    protected override IEnumerator AIActionDecision(float waitTime = 0)
    {
        while (GameManager.Instance.DisableControls)
            yield return null;

        yield return new WaitForSeconds(waitTime);

        while (GameManager.Instance.DisableControls)
            yield return null;

        // Ally units are constantly attacking, if there is no target they will move to their determined position behind player
        if (unit.target != null)
        {
            AttackDecision();
        }
        else
        {
            while (unit.target == null)
            {
                if (Mathf.Abs(transform.position.x - GameManager.Instance.Player.transform.position.x) <= DistanceToPlayer)
                {
                    if (spineSkeletonAnimation.state.GetCurrent(1).Animation == unit.activeAnimations.Movement.SpineAnimationReference.Animation)
                        spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true);

                    if (spineSkeletonAnimation.state.GetCurrent(1).Animation != unit.activeAnimations.idle.SpineAnimationReference.Animation)
                        spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true);

                    yield return new WaitForSeconds(Random.Range(0, 0.5f));

                    continue;
                }

                if (spineSkeletonAnimation.state.GetCurrent(1).Animation != unit.activeAnimations.Movement.SpineAnimationReference.Animation)
                    spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.Movement.SpineAnimationReference, true).TimeScale = 1f;

                directionToPlayer = transform.position.x > GameManager.Instance.Player.transform.position.x ? MoveDirection.left : MoveDirection.right;

                transform.position = new Vector3(transform.position.x + ((int)directionToPlayer * speed) * Time.deltaTime, transform.position.y, transform.position.z);
                if (directionToPlayer == MoveDirection.right)
                {
                    if (transform.position.x > GameManager.Instance.Player.transform.position.x - DistanceToPlayer)
                        transform.position = new Vector2(GameManager.Instance.Player.transform.position.x - DistanceToPlayer + 0.05f, transform.position.y);
                }
                else if (directionToPlayer == MoveDirection.left)
                {
                    if (transform.position.x < GameManager.Instance.Player.transform.position.x + DistanceToPlayer)
                        transform.position = new Vector2(GameManager.Instance.Player.transform.position.x + DistanceToPlayer - 0.05f, transform.position.y);
                }

                GetUnitDirectionTowardsPlayer();

                yield return new WaitForFixedUpdate();
            }
            waitTime = Random.Range(0, aiVariable.maxWaitAfterMovement / 2);
            waitTime += Random.Range(0, aiVariable.maxWaitAfterMovement / 2);
            StartCoroutine(AIActionDecision(waitTime));
        }
    }

    public void GetUnitDirectionTowardsPlayer()
    {
        // i.e if target is more on the right but unit is looking left, turn it right
        int lookDir = transform.position.x > GameManager.Instance.Player.transform.position.x ? -1 : 1;

        transform.localScale = new Vector3(lookDir, transform.localScale.y, transform.localScale.z);
    }

    public override bool TakeDamage(CloseCombatAnimation attack, int DamageTaken, Unit attacker, int attackDirection = 0, bool isProjectile = false, SpineAttachment projectileAttachment = null)
    {
        unit.Health -= DamageTaken;

        if (unit.Health <= 0)
        {
            MercenaryDead(mercenaryUnit, this);

            MercenaryDead -= MercenaryManager.Instance.MercenaryDead;
        }
        
        return base.TakeDamage(attack, 0, attacker, attackDirection, isProjectile, projectileAttachment);
    }
}
