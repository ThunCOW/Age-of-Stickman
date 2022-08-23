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

            gameManager.Player = this;

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


        void KeyboardControls()
        {
            // Release
            if(Input.GetKeyUp(KeyCode.D) || Input.GetKeyUp(KeyCode.A))
            {
                if (!isAnimationDirectionLocked) direction = MoveDirection.waiting;
                unitAnimator.SetBool("Walk", false);
                unitAnimator.SetBool("WalkBehind", false);

                isMoving = false;
            }

            // Pressed
            if(Input.GetKeyDown(KeyCode.D))
            {
                
                direction = MoveDirection.right;

                if (target == null)
                {
                    transform.localScale = new Vector3(1, transform.localScale.y, transform.localScale.z);

                    unitAnimator.SetBool("Walk", true);
                }
                else
                {
                    int dir = transform.position.x > target.transform.position.x ? -1 : 1;

                    transform.localScale = new Vector3(dir, transform.localScale.y, transform.localScale.z);

                    if (transform.position.x > target.transform.position.x)
                    {
                        unitAnimator.SetBool("WalkBehind", true);
                    }
                    else
                    {
                        unitAnimator.SetBool("Walk", true);
                    }
                }

                

                isMoving = true;

                if (transform.localScale.x > 0)
                    movingForward = true;
                else
                    movingForward = false;
            }
            if (Input.GetKeyDown(KeyCode.A))
            {
                
                direction = MoveDirection.left;

                if (target == null)
                {
                    transform.localScale = new Vector3(-1, transform.localScale.y, transform.localScale.z);

                    unitAnimator.SetBool("Walk", true);
                }
                else
                {
                    int dir = transform.position.x > target.transform.position.x ? -1 : 1;

                    transform.localScale = new Vector3(dir, transform.localScale.y, transform.localScale.z);

                    if (transform.position.x > target.transform.position.x)
                    {
                        unitAnimator.SetBool("Walk", true);
                    }
                    else
                    {
                        unitAnimator.SetBool("WalkBehind", true);
                    }
                }

                isMoving = true;

                if (transform.localScale.x < 0)
                    movingForward = true;
                else
                    movingForward = false;
            }



            // Hold
            if (Input.GetKey(KeyCode.A) || Input.GetKey(KeyCode.D))
            {
                if(Input.GetKeyDown(KeyCode.Space))
                {
                    // NonStationary Attack
                    if (Input.GetKeyDown(KeyCode.Space))
                    {
                        int randomAttack = Random.Range(0, nonStationaryAttack.Count);
                        currentAttack = nonStationaryAttack[randomAttack];

                        unitAnimator.SetBool(nonStationaryAttack[randomAttack].AnimationClip.name, true);

                        StartCoroutine(DealDamage());
                    }
                }
            }
            else
            {
                // Stationary Attack
                if (Input.GetKeyDown(KeyCode.Space))
                {
                    int randomAttack = Random.Range(0, stationaryAttack.Count);
                    currentAttack = stationaryAttack[randomAttack];

                    unitAnimator.SetBool(stationaryAttack[randomAttack].AnimationClip.name, true);

                    StartCoroutine(DealDamage());
                }

                // Stationary Stun
                if (Input.GetKeyDown(KeyCode.R))
                {
                    int randomAttack = Random.Range(0, stationaryStun.Count);
                    currentAttack = stationaryStun[randomAttack];

                    unitAnimator.SetBool(stationaryStun[randomAttack].AnimationClip.name, true);

                    StartCoroutine(DealDamage());
                }
            }


            if (Input.GetKey(KeyCode.D))
            {
                
            }
            else if (Input.GetKey(KeyCode.A))
            {
                
            }
            else
            {
                
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
                    unitAnimator.SetTrigger(stunActionList[0].AnimationClip.name);
                    transform.position = new Vector2(transform.position.x + attack.PushDistance * (int)direction, transform.position.y);
                    break;
                case AttackType.Kick:
                    stunActionList = stunType[AttackType.Kick];
                    unitAnimator.SetTrigger(stunActionList[0].AnimationClip.name);
                    break;
                case AttackType.Shield:
                    stunActionList = stunType[AttackType.Shield];
                    unitAnimator.SetTrigger(stunActionList[0].AnimationClip.name);
                    break;
                default:
                    break;
            }

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
            StartCoroutine(GetClosestUnitCycle());
        }
    }
}