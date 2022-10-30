using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace StickmanChampion
{
    public class AIUnit : Unit_Old
    {
        /// <summary>
        /// Holds the predetermined distance to target after making the decision in AIActionDecision or MoveAndAttack,
        /// gets resetted to 0 in AIMovement after closing the distance or passing it.
        /// </summary>
        private float newDistanceToTarget;

        private float hitDistanceToTarget = 0.7f;

        private bool preparingAttack = false;   // prevents decision making during movement attack

        [SerializeField] private AIAgressiveness _aiAgressiveness;
        public AIAgressiveness aiAgressiveness
        {
            get { return _aiAgressiveness; }
            set
            {
                _aiAgressiveness = value;

                switch (value)
                {
                    case AIAgressiveness.low:
                        aiVariable = aiVariables[AIAgressiveness.low];
                        break;
                    case AIAgressiveness.medium:
                        aiVariable = aiVariables[AIAgressiveness.medium];
                        break;
                    case AIAgressiveness.high:
                        aiVariable = aiVariables[AIAgressiveness.high];
                        break;
                    case AIAgressiveness.boss:
                        aiVariable = aiVariables[AIAgressiveness.boss];
                        //attacks
                        break;
                    default:
                        break;
                }
            }
        }
        public AIAgressivenessLevel aiAgressivenessLevel;
        private AIVariables aiVariable;
        private Dictionary<AIAgressiveness, AIVariables> aiVariables = new Dictionary<AIAgressiveness, AIVariables>();
        
        protected override void Start()
        {
            base.Start();
            
            foreach(Action attack in attackList)
            {
                if(attack.Reach > hitDistanceToTarget)
                    hitDistanceToTarget = attack.Reach;
            }

            foreach(AIVariables variables in aiAgressivenessLevel.aiVariableList)
            {
                aiVariables.Add(variables.aIAgressivenesses, variables);
            }

            aiAgressiveness = _aiAgressiveness;

            StartCoroutine(AIActionDecision());
        }

        protected override void CharacterControls()
        {
            AIMovement();

            if(idleing == true) // if in idle - animation ended / movement ended / attack ended - check for unit direction relative to target position
            {
                if (target != null)
                {
                    //CheckUnitDirection();
                }
            }
        }

        // Gets initiated at the start of the game and makes random decisions for the unit, repeats itself until it dies
        private IEnumerator AIActionDecision(float waitTime = 0)
        {
            yield return new WaitForSeconds(waitTime);
            
            if(target != null)
            {
                int rand = Random.Range(1, 101);

                if (rand <= aiVariable.AttackChance) // is going to attack
                {
                    idleing = false;

                    // if in kick distance, there is a chance to kick
                    float kickDistance = 0.7f;
                    if (Mathf.Abs(transform.position.x - target.transform.position.x) < kickDistance)
                    {
                        // X % chance to kick
                        bool kick = Random.Range(0, 5) == 0;
                        if (kick == true)
                        {

                        }
                    }

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
                        waitTime = Random.Range(animationLength / 2, (animationLength + aiVariable.maxWaitAfterAttack) / 2);
                        waitTime += Random.Range(animationLength / 2, (animationLength + aiVariable.maxWaitAfterAttack) / 2);

                        StartCoroutine(AIActionDecision(waitTime));

                        StartCoroutine(SpeedDuringAnimation(attackList[randomAttack]));

                        // only works if there is an object to spawn, still needs to wait for animation event to fire/throw/use it
                        if (currentAttack.rangedSpawnPrefab != null)
                            StartCoroutine(UseRangedWeapon(currentAttack));

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
                        idleing = true;

                        waitTime = Random.Range(0, aiVariable.maxWaitAfterMovement / 2);
                        waitTime += Random.Range(0, aiVariable.maxWaitAfterMovement / 2);
                        StartCoroutine(AIActionDecision(waitTime));
                    }
                    else
                    {
                        idleing = false;

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
            }
            else
            {
                waitTime = Random.Range(0, aiVariable.maxWaitAfterMovement / 2);
                waitTime += Random.Range(0, aiVariable.maxWaitAfterMovement / 2);
                StartCoroutine(AIActionDecision(waitTime));
            }
        }

        // Activates movement and waits until in reach distance, and attacks
        private IEnumerator MoveAndAttack(Action attack, bool changeStance = false)
        {
            if (transform.position.x < target.transform.position.x)  // if target is more on the right, unit direction is right
                direction = MoveDirection.right;
            else
                direction = MoveDirection.left;

            unitAnimator.SetBool("Walk", true);

            newDistanceToTarget = attack.Reach - 0.2f;
            
            preparingAttack = true;

            // wait until we reach to hit distance or target is dead
            yield return new WaitUntil(() => direction == MoveDirection.waiting || target == null);
            // target died, if there is no target stop moving forward
            if (target == null)
            {
                newDistanceToTarget = 0;
                direction = MoveDirection.waiting;
                unitAnimator.SetBool("Walk", false);
                preparingAttack = false;
                idleing = true;
                yield break;
            }

            unitAnimator.SetBool(attack.AnimationClip.name, true);
            float animationLength = attack.AnimationClip.length;
            float waitTime = Random.Range(animationLength / 2, (animationLength + aiVariable.maxWaitAfterAttack) / 2);
            waitTime += Random.Range(animationLength / 2, (animationLength + aiVariable.maxWaitAfterAttack) / 2);
            preparingAttack = false;
            
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
                if(speed != 0)                                                                  // speed equals to zero means speed is controlled by speed curve for animation
                {
                    float dist = Mathf.Abs(transform.position.x - GameManager.Instance.transform.position.x);
                    float maxVision = 8.65f;                                                    // maxVision for player
                    if (dist > maxVision)                                                       //  if AIUnit is outside of cam, it will move faster to catch up and then slow down to normal speed level
                    {
                        if (target.speed != 0)  speed = target.speed * 1.5f;
                    }
                    else
                        speed = speed_;
                }

                // if a unit has gotten enough close or extra closer to target than it was determinted to, ready for next action ( Basically idleing )
                if (Mathf.Abs(transform.position.x - target.transform.position.x) <= newDistanceToTarget)
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
                    unitAnimator.SetBool("Walk", false);

                    newDistanceToTarget = 0;
                }
            }
        }

        protected override IEnumerator StunnedFor(float stunDuration, Action attack)
        {
            unitAnimator.SetBool("Walk", false);
            idleing = false;

            speed = 0f;                                                     // speed is now controlled by speed curve

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

            //yield return new WaitForSeconds(stunActionList[0].AnimationClip.length);

            idleing = true;

            speed = speed_;                                                 // speed is now set to default speed level

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
            StartCoroutine(AIActionDecision());
            StartCoroutine(GetClosestUnitSearchCycle());
        }
    }
}