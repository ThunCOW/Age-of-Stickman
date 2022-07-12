using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace StickmanChampion
{
    public class AIUnit : Unit
    {
        private float newDistanceToTarget;

        private AIAgressiveness aiAgressiveness = AIAgressiveness.low;

        [SerializeField] protected float maxReach;

        private float hitDistanceToTarget = 0.7f;

        private bool isAttacking = false;   // prevents decision making during movement attack
        protected override void Start()
        {
            base.Start();
            
            if (gameObject.CompareTag(gameManager.ENEMY_TAG))
                gameManager.EnemyUnits.Add(this);
            else
                gameManager.PlayerUnits.Add(this);
            
            foreach(OffensiveSkills attack in attackList)
            {
                if(attack.Reach > hitDistanceToTarget)
                    hitDistanceToTarget = attack.Reach;
            }
            StartCoroutine(AIActionDecision());
        }

        void FixedUpdate()
        {
            if (canMove)
                transform.position = new Vector3(transform.position.x + ((int)direction * speed * multiplier) * Time.deltaTime, transform.position.y, transform.position.z);
        }
        protected override void CharacterControls()
        {
            AIMovement();
        }

        // Gets initiated at the start of the game and makes random decisions for the unit, repeats itself until it dies
        private IEnumerator AIActionDecision(float waitTime = 0)
        {
            yield return new WaitForSeconds(waitTime);
            
            
            switch (aiAgressiveness)
            {
                case AIAgressiveness.low:
                    int rand = 4;
                    if (rand == 4) // is going to attack
                    {
                        bool changeStance = Random.Range(0, 10) == 0;
                        if(changeStance == true)
                        {
                            if(currentStance == StanceList.Stand_A)
                                currentStance = StanceList.Stand_A_transition_B;
                            if (currentStance == StanceList.Stand_B)
                                currentStance = StanceList.Stand_B_transition_A;
                        }
                        // select a random attack
                        int randomAttack = Random.Range(0, attackList.Count);
                        if (Mathf.Abs(transform.position.x - target.transform.position.x) < attackList[randomAttack].Reach)
                        {
                            // if it is close enough to attack, attack and start next courutine for decision
                            charAnimator.SetBool(attackList[randomAttack].Animation.name, true);
                            float animationLength = attackList[randomAttack].Animation.length;
                            waitTime = Random.Range(animationLength, animationLength + 0.8f);
                            StartCoroutine(AIActionDecision(waitTime));
                            if(changeStance == true)
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
                            direction = Directions.right;

                            charAnimator.SetBool("Walk", true);

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

        // Activates movement and waits until in reach distance, and attacks
        private IEnumerator MoveAndAttack(OffensiveSkills attack, bool changeStance = false)
        {
            aiAgressiveness = AIAgressiveness.low;

            direction = Directions.right;

            charAnimator.SetBool("Walk", true);

            newDistanceToTarget = attack.Reach - 0.2f;
            
            isAttacking = true;

            yield return new WaitUntil(() => direction == Directions.waiting);
            
            charAnimator.SetBool(attackList[0].Animation.name, true);
            float animationLength = attackList[0].Animation.length;
            float waitTime = Random.Range(animationLength, animationLength + 0.8f);
            Debug.Log("Move And Attack");
            isAttacking = false;
            StartCoroutine(AIActionDecision(waitTime));

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

                            if (isAttacking == false)
                            {
                                Debug.Log("Move");
                                StartCoroutine(AIActionDecision(waitTime));
                            }

                            direction = Directions.waiting;
                            charAnimator.SetBool("Walk", false);

                            newDistanceToTarget = 0;
                        }
                        break;
                    case AIAgressiveness.medium:
                        if (Mathf.Abs(transform.position.x - target.transform.position.x) <= newDistanceToTarget)
                        {
                            float waitTime = Random.Range(0.2f, 1.5f);

                            StartCoroutine(AIActionDecision(waitTime));
                            direction = Directions.waiting;
                            charAnimator.SetBool("Walk", false);

                            newDistanceToTarget = 0;
                        }
                        break;
                    case AIAgressiveness.high:
                        if (Mathf.Abs(transform.position.x - target.transform.position.x) <= newDistanceToTarget)
                        {
                            float waitTime = Random.Range(0.2f, 1f);

                            StartCoroutine(AIActionDecision(waitTime));
                            direction = Directions.waiting;
                            charAnimator.SetBool("Walk", false);

                            newDistanceToTarget = 0;
                        }
                        break;
                    default:
                        break;
                }
            }
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
