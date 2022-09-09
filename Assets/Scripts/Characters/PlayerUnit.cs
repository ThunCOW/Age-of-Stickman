using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace StickmanChampion
{
    public class PlayerUnit : Unit
    {
        private List<Action> stationaryAttack;
        private List<Action> nonStationaryAttack;
        private List<Action> stationaryStun;
        private List<Action> nonStationaryStun;

        // Start is called before the first frame update
        protected override void Start()
        {
            base.Start();

            if (stationaryAttack == null)
                stationaryAttack = new List<Action>();

            if (nonStationaryAttack == null)
                nonStationaryAttack = new List<Action>();

            if (stationaryStun == null)
                stationaryStun = new List<Action>();

            if (nonStationaryStun == null)
                nonStationaryStun = new List<Action>();

            GameManager.Instance.Player = this;

            foreach(Action action in attackList)
            {
                if(action.attackType == AttackType.Normal)
                { 
                    if(action.animationMovementType == AnimationMovementType.Stationary)
                    {
                        stationaryAttack.Add(action);
                    }
                    else
                    {
                        nonStationaryAttack.Add(action);
                    }
                }
                else
                {
                    if (action.animationMovementType == AnimationMovementType.Stationary)
                    {
                        stationaryStun.Add(action);
                    }
                    else
                    {
                        nonStationaryStun.Add(action);
                    }
                }
            }
        }

        protected override void CharacterControls()
        {
            KeyboardControls();
        }

        // Walking animation depends on the direction unit is facing
        void SetWalkingAnimation(int dir)
        {
            if (target == null)
            {
                if (!isAnimationStarted) transform.localScale = new Vector3(dir, transform.localScale.y, transform.localScale.z);

                unitAnimator.SetBool("Walk", true);
            }
            else
            {
                if (!isAnimationStarted) CheckUnitDirection();

                if (dir == (int)MoveDirection.right)
                {
                    if (transform.position.x > target.transform.position.x)
                    {
                        unitAnimator.SetBool("WalkBehind", true);
                        unitAnimator.SetBool("Walk", false);
                    }
                    else
                    {
                        unitAnimator.SetBool("Walk", true);
                        unitAnimator.SetBool("WalkBehind", false);
                    }
                }
                else
                {
                    if (transform.position.x > target.transform.position.x)
                    {
                        unitAnimator.SetBool("Walk", true);
                        unitAnimator.SetBool("WalkBehind", false);
                    }
                    else
                    {
                        unitAnimator.SetBool("WalkBehind", true);
                        unitAnimator.SetBool("Walk", false);
                    }
                }
            }
        }

        bool attackTrigger = false;
        bool stunTrigger = false;
        Coroutine triggerCoroutine = null;
        void KeyboardControls()
        {
            // Space Pressed
            if(Input.GetKeyDown(KeyCode.Space))
            {
                attackTrigger = true;
                stunTrigger = false;

                if(triggerCoroutine != null) StopCoroutine(triggerCoroutine);
            }
            // Space Released
            if(Input.GetKeyUp(KeyCode.Space))
            {
                triggerCoroutine = StartCoroutine(ResetAttackTrigger(KeyCode.Space));
            }

            // R pressed
            if(Input.GetKeyDown(KeyCode.R))
            {
                stunTrigger = true;
                attackTrigger = false;

                if (triggerCoroutine != null) StopCoroutine(triggerCoroutine);
            }
            if(Input.GetKeyUp(KeyCode.R))
            {
                triggerCoroutine = StartCoroutine(ResetAttackTrigger(KeyCode.R));
            }

            // Movement Conditions

            // A D Release
            if(Input.GetKeyUp(KeyCode.D) || Input.GetKeyUp(KeyCode.A))
            {
                if (!isAnimationStarted) direction = MoveDirection.waiting;
                unitAnimator.SetBool("Walk", false);
                unitAnimator.SetBool("WalkBehind", false);
            }

            // A D Pressed
            if(Input.GetKeyDown(KeyCode.D))
            {

                if (!isAnimationStarted) direction = MoveDirection.right;

                SetWalkingAnimation((int)direction);

                if (transform.localScale.x > 0)
                    movingForward = true;
                else
                    movingForward = false;
            }
            if (Input.GetKeyDown(KeyCode.A))
            {
                if (!isAnimationStarted) direction = MoveDirection.left;

                SetWalkingAnimation((int)direction);

                if (transform.localScale.x < 0)
                    movingForward = true;
                else
                    movingForward = false;
            }

            // Animation Conditions

            // A D Hold
            // NonStationary Attack
            if (Input.GetKey(KeyCode.A) || Input.GetKey(KeyCode.D))
            {
                // There isn't an animation already playing
                if(!isAnimationStarted)
                {
                    if (attackTrigger)
                    {
                        int randomAttack = Random.Range(0, nonStationaryAttack.Count);
                        currentAttack = nonStationaryAttack[randomAttack];

                        unitAnimator.SetBool(nonStationaryAttack[randomAttack].AnimationClip.name, true);

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
                        int randomAttack = Random.Range(0, stationaryAttack.Count);
                        currentAttack = stationaryAttack[randomAttack];

                        unitAnimator.SetBool(stationaryAttack[randomAttack].AnimationClip.name, true);

                        AttackAction();
                    }

                    if (stunTrigger)
                    {
                        int randomAttack = Random.Range(0, stationaryStun.Count);
                        currentAttack = stationaryStun[randomAttack];

                        unitAnimator.SetBool(stationaryStun[randomAttack].AnimationClip.name, true);

                        AttackAction();
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
            if(target != null)
            {
                CheckUnitDirection();
            }

            StartCoroutine(SpeedDuringAnimation(currentAttack));
            StartCoroutine(WaitForEndOfAnimation(currentAttack.AnimationClip));
        }

        protected IEnumerator WaitForEndOfAnimation(AnimationClip animationClip)
        {
            speed = 0f;                                                     // speed is now controlled by speed curve
            isAnimationStarted = true;                                      // prevents direction to become 0 and stop movement

            yield return new WaitForSeconds(animationClip.length + 0.05f);  // (not sure) possibly so direction below works

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

        protected override IEnumerator StunnedFor(float stunDuration, Action attack)
        {
            idleing = false;

            if (transform.position.x < target.transform.position.x)  // if target is more on the right, unit direction is right
                direction = MoveDirection.left;
            else
                direction = MoveDirection.right;

            List<BaseAction> stunActionList = null;
            switch (attack.attackType)
            {
                case AttackType.Normal:
                    stunActionList = stunType[AttackType.Normal];
                    transform.position = new Vector2(transform.position.x + attack.PushDistance * (int)direction, transform.position.y);
                    break;
                case AttackType.Kick:
                    stunActionList = stunType[AttackType.Kick];
                    break;
                case AttackType.Shield:
                    stunActionList = stunType[AttackType.Shield];
                    break;
                default:
                    break;
            }
            unitAnimator.SetTrigger(stunActionList[0].AnimationClip.name);
            StartCoroutine(WaitForEndOfAnimation(stunActionList[0].AnimationClip));

            float animationLength = stunActionList[0].AnimationClip.length;
            float animationCurrentTime = 0;
            while (animationLength > animationCurrentTime)
            {
                animationCurrentTime += Time.deltaTime;
                speedRelativeToAnimation = stunActionList[0].speedCurve.Evaluate(animationCurrentTime);
                yield return null;
            }

            speedRelativeToAnimation = 0;

            direction = MoveDirection.waiting;

            // Means unit was about to attack
            if (meleeHitTrigger == true)
            {
                meleeHitTrigger = false;
                currentAttack = null;
            }

            ReStartCoroutines();
        }

        protected override void ReStartCoroutines()
        {
            attackTrigger = false;
            stunTrigger = false;

            StartCoroutine(GetClosestUnitSearchCycle());
        }

        protected override void FindClosestUnit()
        {
            base.FindClosestUnit();

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
        }
    }
}