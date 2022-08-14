using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace StickmanChampion
{
    public class AIUnit : Unit
    {
        /// <summary>
        /// Holds the predetermined distance to target after making the decision in AIActionDecision or MoveAndAttack,
        /// gets resetted to 0 in AIMovement after closing the distance or passing it.
        /// </summary>
        private float newDistanceToTarget;

        private AIAgressiveness aiAgressiveness = AIAgressiveness.low;

        private float hitDistanceToTarget = 0.7f;

        private bool preparingAttack = false;   // prevents decision making during movement attack
        protected override void Start()
        {
            base.Start();
            
            foreach(Action attack in attackList)
            {
                if(attack.Reach > hitDistanceToTarget)
                    hitDistanceToTarget = attack.Reach;
            }
            
            StartCoroutine(AIActionDecision());
        }

        protected override void CharacterControls()
        {
            AIMovement();

            if(idleing == true) // if in idle - animation ended / movement ended / attack ended - check for unit direction relative to target position
            {
                if (target != null)
                {

                    // i.e if target is more on the right but unit is looking left, turn it right
                    if (transform.position.x < target.transform.position.x && transform.localScale.x < 0)
                        transform.localScale = new Vector3(Mathf.Abs(transform.localScale.x), transform.localScale.y, transform.localScale.z);
                    else if (transform.position.x > target.transform.position.x && transform.localScale.x > 0)
                    {
                        transform.localScale = new Vector3(-transform.localScale.x, transform.localScale.y, transform.localScale.z);
                    }
                }
            }
        }

        // Gets initiated at the start of the game and makes random decisions for the unit, repeats itself until it dies
        private IEnumerator AIActionDecision(float waitTime = 0)
        {
            yield return new WaitForSeconds(waitTime);
            
            idleing = false;
            
            if(target != null)
            {
                switch (aiAgressiveness)
                {
                    case AIAgressiveness.low:
                        int rand = 4;
                        if (rand == 4) // is going to attack
                        {
                            bool changeStance = false;
                            // if there are multiple stances, we can change stance
                            if (stanceList.Count > 1)
                            {
                                changeStance = Random.Range(0, 10) == 0;
                                if (changeStance == true)
                                {
                                    if (currentStance == StanceList.Stand_A)
                                        currentStance = StanceList.Stand_A_transition_B;
                                    if (currentStance == StanceList.Stand_B)
                                        currentStance = StanceList.Stand_B_transition_A;
                                }
                            }
                            // select a random attack
                            int randomAttack = Random.Range(0, attackList.Count);
                            currentAttack = attackList[randomAttack];
                            if (Mathf.Abs(transform.position.x - target.transform.position.x) < attackList[randomAttack].Reach)
                            {
                                // if it is close enough to attack, attack and start next courutine for decision
                                unitAnimator.SetBool(attackList[randomAttack].AnimationClip.name, true);
                                float animationLength = attackList[randomAttack].AnimationClip.length;
                                waitTime = Random.Range(animationLength, animationLength + 0.8f);

                                StartCoroutine(DealDamage());

                                StartCoroutine(AIActionDecision(waitTime));

                                StartCoroutine(SpeedDuringAnimation(attackList[randomAttack]));

                                // only works if there is an object to spawn, still needs to wait for animation event to fire/throw/use it
                                if (attackList[randomAttack].rangedSpawnPrefab != null)
                                    StartCoroutine(UseRangedWeapon(attackList[randomAttack]));

                                if (changeStance == true)
                                {
                                    if (currentStance == StanceList.Stand_A_transition_B)
                                        currentStance = StanceList.Stand_B;
                                    if (currentStance == StanceList.Stand_B_transition_A)
                                        currentStance = StanceList.Stand_A;
                                }
                            }
                            else
                            {
                                // if it is not close enough to attack
                                StartCoroutine(MoveAndAttack(attackList[randomAttack], changeStance));
                            }
                        }
                        else
                        {
                            // If a unit is very close to target unit, it does not move closer anymore
                            if (Mathf.Abs(transform.position.x - target.transform.position.x) < hitDistanceToTarget)
                            {
                                waitTime = Random.Range(0.2f, 1f);
                                StartCoroutine(AIActionDecision(waitTime));
                            }
                            else
                            {
                                aiAgressiveness = AIAgressiveness.low;

                                if (transform.position.x < target.transform.position.x)  // if target is more on the right, unit direction is right
                                    direction = MoveDirection.right;
                                else
                                    direction = MoveDirection.left;

                                unitAnimator.SetBool("Walk", true);

                                newDistanceToTarget = Random.Range(0, Mathf.Abs(transform.position.x - target.transform.position.x));
                                // if too close to player ( within hit distance ) set new movement position to hit distance
                                if (newDistanceToTarget <= hitDistanceToTarget)
                                    newDistanceToTarget = hitDistanceToTarget - 0.3f;
                            }
                        }
                        break;
                    case AIAgressiveness.medium:
                        break;
                    case AIAgressiveness.high:
                        break;
                    case AIAgressiveness.boss:
                        //attacks
                        break;
                    default:
                        break;
                } 
            }
            else
            {
                waitTime = Random.Range(0.2f, 1f);
                StartCoroutine(AIActionDecision(waitTime));
            }
        }

        // Activates movement and waits until in reach distance, and attacks
        private IEnumerator MoveAndAttack(Action attack, bool changeStance = false)
        {
            Debug.Log("Walk Attack");

            aiAgressiveness = AIAgressiveness.low;

            if (transform.position.x < target.transform.position.x)  // if target is more on the right, unit direction is right
                direction = MoveDirection.right;
            else
                direction = MoveDirection.left;

            unitAnimator.SetBool("Walk", true);

            newDistanceToTarget = attack.Reach - 0.2f;
            
            preparingAttack = true;

            idleing = false;

            yield return new WaitUntil(() => direction == MoveDirection.waiting);
            
            unitAnimator.SetBool(attack.AnimationClip.name, true);
            float animationLength = attack.AnimationClip.length;
            float waitTime = Random.Range(animationLength, animationLength + 0.8f);
            preparingAttack = false;

            StartCoroutine(DealDamage());
            
            StartCoroutine(AIActionDecision(waitTime)); // waits until animation ends, so does not make decisions during animation

            StartCoroutine(SpeedDuringAnimation(attack));

            // only works if there is an object to spawn, still needs to wait for animation event to fire/throw/use it
            if (attack.rangedSpawnPrefab != null)
                StartCoroutine(UseRangedWeapon(attack));

            if (currentStance == StanceList.Stand_A_transition_B)
                currentStance = StanceList.Stand_B;
            if (currentStance == StanceList.Stand_B_transition_A)
                currentStance = StanceList.Stand_A;
        }

        // runs all the time
        private void AIMovement()
        {
            if (target != null)
            {
                switch (aiAgressiveness)
                {
                    case AIAgressiveness.low:
                        // if a unit has gotten enough close or extra closer to target than it was determinted to, ready for next action
                        if (Mathf.Abs(transform.position.x - target.transform.position.x) <= newDistanceToTarget)
                        {
                            float waitTime = Random.Range(0.2f, 1f);

                            // activated during MoveAndAttack session, walking happens here so it does not trigger twice
                            if (preparingAttack == false)
                            {
                                StartCoroutine(AIActionDecision(waitTime));
                                idleing = true;
                            }

                            direction = MoveDirection.waiting;
                            unitAnimator.SetBool("Walk", false);

                            newDistanceToTarget = 0;
                        }
                        break;
                    case AIAgressiveness.medium:
                        if (Mathf.Abs(transform.position.x - target.transform.position.x) <= newDistanceToTarget)
                        {
                            float waitTime = Random.Range(0.2f, 1.5f);

                            StartCoroutine(AIActionDecision(waitTime));
                            direction = MoveDirection.waiting;
                            unitAnimator.SetBool("Walk", false);

                            newDistanceToTarget = 0;
                        }
                        break;
                    case AIAgressiveness.high:
                        if (Mathf.Abs(transform.position.x - target.transform.position.x) <= newDistanceToTarget)
                        {
                            float waitTime = Random.Range(0.2f, 1f);

                            StartCoroutine(AIActionDecision(waitTime));
                            direction = MoveDirection.waiting;
                            unitAnimator.SetBool("Walk", false);

                            newDistanceToTarget = 0;
                        }
                        break;
                    default:
                        break;
                }
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
            Debug.Log(stunActionList[0].speedCurve.Evaluate(animationCurrentTime));
            while (animationLength > animationCurrentTime)
            {
                animationCurrentTime += Time.deltaTime;
                speedRelativeToAnimation = stunActionList[0].speedCurve.Evaluate(animationCurrentTime);
                yield return null;
            }

            //yield return new WaitForSeconds(stunActionList[0].AnimationClip.length);

            idleing = true;

            speedRelativeToAnimation = 0;
            
            direction = MoveDirection.waiting;

            // Means unit was about to attack
            if (meleeHitTrigger == true)
            {
                meleeHitTrigger = false;
                currentAttack = null;
            }
            StartCoroutine(AIActionDecision());
            StartCoroutine(GetClosestUnitCycle());
            /*Debug.Log("stunned");
            idleing = false;

            // Resets all boolean and triggers
            foreach(AnimatorControllerParameter parameter in unitAnimator.parameters)
            {
                if(parameter.type == AnimatorControllerParameterType.Bool)
                    unitAnimator.SetBool(parameter.name, false);
                else if(parameter.type == AnimatorControllerParameterType.Trigger)
                    unitAnimator.ResetTrigger(parameter.name);
            }
            unitAnimator.Play("Idle_A", 0, 0);

            direction = MoveDirection.waiting;
            speedRelativeToAnimation = 0;

            newDistanceToTarget = 0;
            
            yield return new WaitForSeconds(stunDuration);
            
            idleing = true;
            
            // Means unit was about to attack
            if(meleeHitTrigger == true)
            {
                meleeHitTrigger = false;
                currentAttack = null;
            }
            StartCoroutine(AIActionDecision());
            StartCoroutine(GetClosestUnitCycle());*/
        }
    }

    public enum AIAgressiveness
    {
        low,
        medium,
        high,
        boss
    }
}
