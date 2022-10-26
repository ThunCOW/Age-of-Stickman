using Newtonsoft.Json.Linq;
using SpineControllerVersion;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AIController : UnitController
{
    /// <summary>
    /// Holds the predetermined distance to target after making the decision in AIActionDecision or MoveAndAttack,
    /// gets resetted to 0 in AIMovement after closing the distance or passing it.
    /// </summary>
    private float newDistanceToTarget;

    private float hitDistanceToTarget = 2f;

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

    private Transform ScreenLeftBorder;
    private Transform ScreenRightBorder;

    void Awake()
    {
        foreach (AIVariables variables in aiAgressivenessLevel.aiVariableList)
        {
            aiVariables.Add(variables.aIAgressivenesses, variables);
        }
    }

    protected override void Start()
    {
        base.Start();

        ScreenLeftBorder = GameManager.Instance.SceneViewBordersParent.transform.GetChild(0);
        ScreenRightBorder = GameManager.Instance.SceneViewBordersParent.transform.GetChild(1);

        if (isBoss)
        {
            if(gameObject.CompareTag(GameManager.SPEARMASTER_TAG))
                StartCoroutine(SpearmasterEntrance());
        }
        else
        {

            if (PlayerController.hasPlayerReachedEndOfLevel)
                StartCoroutine(MoveInsideCameraView());
            else
                StartCoroutine(AIActionDecision());
        }
    }

    protected override void CharacterControls()
    {
        /*if (GameManager.Instance.hasPlayerReachedEndOfLevel)
        {
            if (gameObject.transform.position.x >= unit.target.transform.position.x)
            {
                if (gameObject.transform.position.x > RightWallPosition.transform.position.x)
                {
                    AIMovementPlayerAtLevelBorders();
                }
                else
                {
                    AIMovement();
                }
            }
            else
            {
                if (gameObject.transform.position.x < LeftWallPosition.transform.position.x || Mathf.Abs(transform.position.x - unit.target.transform.position.x) <= 3)
                {
                    AIMovementPlayerAtLevelBorders();
                }
                else
                {
                    AIMovement();
                }
            }
        }
        else*/
            AIMovement();

        if (idleing == true) // if in idle - animation ended / movement ended / attack ended - check for unit direction relative to target position
        {
            if (unit.target != null)
            {
                //CheckUnitDirection();
            }
        }
    }

    private IEnumerator MoveInsideCameraView(float waitTime = 0)
    {
        while (GameManager.Instance.DisableControls)
            yield return null;

        yield return new WaitForSeconds(waitTime);

        if (unit.target != null)
        {
            idleing = false;

            if (transform.position.x < unit.target.transform.position.x)  // if target is more on the right, unit direction is right
                direction = MoveDirection.right;
            else
                direction = MoveDirection.left;

            spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.Movement.SpineAnimationReference, true).TimeScale = 1f;

            // unit spawned on right
            if (gameObject.transform.position.x > unit.target.transform.position.x)
            {
                while (gameObject.transform.position.x > ScreenRightBorder.transform.position.x)
                {
                    yield return new WaitForFixedUpdate();
                }
            }
            else if (gameObject.transform.position.x < unit.target.transform.position.x)
            {
                while (gameObject.transform.position.x < ScreenLeftBorder.transform.position.x)
                {
                    yield return new WaitForFixedUpdate();
                }
            }

            newDistanceToTarget = 32;
        }
        else
        {
            waitTime = 0.3f;
            StartCoroutine(MoveInsideCameraView(waitTime));
        }
    }

    // Gets initiated at the start of the game and makes random decisions for the unit, repeats itself until it dies
    private IEnumerator AIActionDecision(float waitTime = 0)
    {
        while(GameManager.Instance.DisableControls)
            yield return null;

        yield return new WaitForSeconds(waitTime);

        while (GameManager.Instance.DisableControls)
            yield return null;

        if (unit.target != null)
        {
            int rand = 0;
            if (PlayerController.hasPlayerReachedEndOfLevel)
            {
                // new spawned units must walk within arbitary level borders, if player is close to borders (excluding right border rn) and so to enemy ( precisely 3 ) then dont move anymore
                /*if (gameObject.transform.position.x >= unit.target.transform.position.x)
                {
                    if (gameObject.transform.position.x > RightWallPosition.transform.position.x)
                    {
                        idleing = false;

                        if (transform.position.x < unit.target.transform.position.x)  // if target is more on the right, unit direction is right
                            direction = MoveDirection.right;
                        else
                            direction = MoveDirection.left;

                        spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.Movement.SpineAnimationReference, true).TimeScale = 1f;

                        yield break;
                    }
                }
                else if(gameObject.transform.position.x < unit.target.transform.position.x)
                {
                    if (gameObject.transform.position.x < LeftWallPosition.transform.position.x || Mathf.Abs(transform.position.x - unit.target.transform.position.x) <= 3)
                    {
                        idleing = false;

                        if (transform.position.x < unit.target.transform.position.x)  // if target is more on the right, unit direction is right
                            direction = MoveDirection.right;
                        else
                            direction = MoveDirection.left;

                        spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.Movement.SpineAnimationReference, true).TimeScale = 1f;

                        yield break;
                    }
                }*/
            }

            rand = Random.Range(1, 101);

            if (rand <= aiVariable.AttackChance) // is going to attack
            {
                AttackDecision();
            }
            else
            {
                // If a unit is very close to target unit, it does not move closer anymore
                if (Mathf.Abs(transform.position.x - unit.target.transform.position.x) < hitDistanceToTarget)
                {
                    idleing = true;

                    waitTime = Random.Range(0, aiVariable.maxWaitAfterMovement / 2);
                    waitTime += Random.Range(0, aiVariable.maxWaitAfterMovement / 2);
                    StartCoroutine(AIActionDecision(waitTime));
                }
                else
                {
                    idleing = false;

                    if (transform.position.x < unit.target.transform.position.x)  // if target is more on the right, unit direction is right
                        direction = MoveDirection.right;
                    else
                        direction = MoveDirection.left;

                    if(spineSkeletonAnimation.AnimationName != unit.activeAnimations.Movement.SpineAnimationReference.name)
                        spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.Movement.SpineAnimationReference, true).TimeScale = 1f;

                    newDistanceToTarget = Random.Range(0, Mathf.Abs(transform.position.x - unit.target.transform.position.x));
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

    private void AttackDecision()
    {
        float waitTime = 0;

        idleing = false;

        // if in kick distance, there is a chance to kick
        float kickDistance = 2f;
        if (Mathf.Abs(transform.position.x - unit.target.transform.position.x) < kickDistance)
        {
            // X % chance to kick
            bool kick = Random.Range(0, 5) == 0;
            if (kick == true)
            {
                List<BasicAnimation> tempBreakAnimation = unit.activeAnimations.BreakStance;

                int randomAttack2 = Random.Range(0, tempBreakAnimation.Count);
                BasicAnimation selectedAnim = tempBreakAnimation[randomAttack2];

                currentAttack = selectedAnim as CloseCombatAnimation;

                spineSkeletonAnimation.state.SetAnimation(1, selectedAnim.SpineAnimationReference, false).TimeScale = 1f;
                float animationLength = selectedAnim.SpineAnimationReference.Animation.Duration;
                waitTime = Random.Range(animationLength / 2, (animationLength + aiVariable.maxWaitAfterAttack) / 2);
                waitTime += Random.Range(animationLength / 2, (animationLength + aiVariable.maxWaitAfterAttack) / 2);

                StartCoroutine(AIActionDecision(waitTime));

                if (selectedAnim is CloseCombatAnimation)
                    StartCoroutine(SpeedDuringAnimation(selectedAnim as CloseCombatAnimation));
                else if (selectedAnim is SpeedDependantAnimation)
                    StartCoroutine(SpeedDuringAnimation(selectedAnim as SpeedDependantAnimation));

                return;
            }
        }
        // if there are multiple stances, we can change stance
        // TODO handle stance changes later
        if (unit.activeAnimations.ChangeStance.Animation != null)
        {
            int rand = Random.Range(0, 100);
            bool tempChangeStance = rand < unit.activeAnimations.ChangeStance.chance ? true : false;
            if (tempChangeStance == true)
            {
                currentAttack = unit.activeAnimations.ChangeStance.Animation as CloseCombatAnimation;

                changeStance = true;
            }
        }

        if(!changeStance)
        {
            List<BasicAnimation> tempAttackAnimation = new List<BasicAnimation>();
            foreach (BasicAnimation standAttack in unit.activeAnimations.Attack)
                tempAttackAnimation.Add(standAttack);
            foreach (BasicAnimation walkAttack in unit.activeAnimations.WalkAttack)
                tempAttackAnimation.Add(walkAttack);

            // select a random attack
            int randomAttack = Random.Range(0, tempAttackAnimation.Count);
            currentAttack = tempAttackAnimation[randomAttack] as CloseCombatAnimation;

            if (unit.target != null)
            {
                float dist = Mathf.Abs(unit.transform.position.x - unit.target.transform.position.x);
                //foreach (BasicAnimation action in tempAttackAnimation)
                for(int i = 0; i < tempAttackAnimation.Count; i++)
                {
                    if (dist < currentAttack.MinDistanceLimit)
                    {
                        // current unit is too close to make this action, like jump attack etc
                        currentAttack = tempAttackAnimation[i] as CloseCombatAnimation;
                    }
                    else break;
                }
            }
        }

        if (Mathf.Abs(transform.position.x - unit.target.transform.position.x) < currentAttack.Reach)
        {
            // if it is close enough to attack, attack and start next courutine for decision
            spineSkeletonAnimation.state.SetAnimation(1, currentAttack.SpineAnimationReference, false).TimeScale = 1f;
            float animationLength = currentAttack.SpineAnimationReference.Animation.Duration;
            waitTime = Random.Range(animationLength / 2, (animationLength + aiVariable.maxWaitAfterAttack) / 2);
            waitTime += Random.Range(animationLength / 2, (animationLength + aiVariable.maxWaitAfterAttack) / 2);

            StartCoroutine(AIActionDecision(waitTime));

            StartCoroutine(SpeedDuringAnimation(currentAttack));

            // TODO RANGED ATTACK
            // only works if there is an object to spawn, still needs to wait for animation event to fire/throw/use it
            //if (currentAttack.rangedSpawnPrefab != null)
            //    StartCoroutine(UseRangedWeapon(currentAttack));

            /*if (changeStance == true)
            {
                if (currentStance == StanceList.Stand_A_transition_B)
                    currentStance = StanceList.Stand_B;
                if (currentStance == StanceList.Stand_B_transition_A)
                    currentStance = StanceList.Stand_A;
            }*/
        }
        else
        {
            // if it is not close enough to attack
            //if(MoveAndAttackCoroutine != null) StopCoroutine(MoveAndAttackCoroutine);
            StartCoroutine(MoveAndAttack(currentAttack));
        }
    }

    //Coroutine MoveAndAttackCoroutine = null;
    // Activates movement and waits until in reach distance, and attacks
    private IEnumerator MoveAndAttack(CloseCombatAnimation attack)
    {
        direction = unit.GetDirectionRelativeToTarget();

        spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.Movement.SpineAnimationReference, true).TimeScale = 1f;

        newDistanceToTarget = attack.Reach - 0.2f;

        preparingAttack = true;

        // wait until we reach to hit distance or target is dead
        bool wait = true;
        float waitMax = Random.Range(2, 3.5f);
        while(wait)
        {
            waitMax -= Time.deltaTime;
            
            if (direction == MoveDirection.waiting)
                wait = false;
            else if (unit.target == null)
                wait = false;
            else if(waitMax <= 0)
            {
                // Enough waited, think for different action
                if (changeStance == true) changeStance = false;
                AttackDecision();
                yield break;
            }
            yield return null;
        }
        yield return new WaitUntil(() => direction == MoveDirection.waiting || unit.target == null);
        // target died, if there is no target stop moving forward
        if (unit.target == null)
        {
            newDistanceToTarget = 0;
            direction = MoveDirection.waiting;
            spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true).TimeScale = 1f;
            preparingAttack = false;
            idleing = true;
            yield break;
        }

        spineSkeletonAnimation.state.SetAnimation(1, attack.SpineAnimationReference, false).TimeScale = 1f;
        float animationLength = attack.SpineAnimationReference.Animation.Duration;
        float waitTime = Random.Range(animationLength / 2, (animationLength + aiVariable.maxWaitAfterAttack) / 2);
        waitTime += Random.Range(animationLength / 2, (animationLength + aiVariable.maxWaitAfterAttack) / 2);
        preparingAttack = false;

        StartCoroutine(AIActionDecision(waitTime)); // waits until animation ends, so does not make decisions during animation

        StartCoroutine(SpeedDuringAnimation(attack));

        // only works if there is an object to spawn, still needs to wait for animation event to fire/throw/use it
        //if (attack.rangedSpawnPrefab != null)
        //    StartCoroutine(UseRangedWeapon(attack));

        /*if (currentStance == StanceList.Stand_A_transition_B)
            currentStance = StanceList.Stand_B;
        if (currentStance == StanceList.Stand_B_transition_A)
            currentStance = StanceList.Stand_A;*/
    }

    // runs all the time
    private void AIMovement()
    {
        if (unit.target != null)
        {
            if (speed != 0)                                                                  // speed equals to zero means speed is controlled by speed curve for animation
            {
                float dist = Mathf.Abs(transform.position.x - GameManager.Instance.Player.transform.position.x);
                float maxVision = 8.65f;                                                    // maxVision for player
                if (dist > maxVision)                                                       //  if AIUnit is outside of cam, it will move faster to catch up and then slow down to normal speed level
                {
                    if (unit.target.unitController.speed != 0) speed = unit.target.unitController.speed * 2;
                }
                else
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

    private void AIMovementPlayerAtLevelBorders()
    {
        if(unit.target != null)
        {
            if (speed != 0)                                                                  // speed equals to zero means speed is controlled by speed curve for animation
            {
                float dist = Mathf.Abs(transform.position.x - GameManager.Instance.Player.transform.position.x);
                float maxVision = 8.65f;                                                    // maxVision for player
                if (dist > maxVision)                                                       //  if AIUnit is outside of cam, it will move faster to catch up and then slow down to normal speed level
                {
                    if (unit.target.unitController.speed != 0) speed = unit.target.unitController.speed * 2;
                }
                else
                    speed = defaultSpeed;
            }

            if (gameObject.transform.position.x >= unit.target.transform.position.x)
            {
                if (gameObject.transform.position.x <= RightWallPosition.transform.position.x)
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
            else
            {
                if(gameObject.transform.position.x >= LeftWallPosition.transform.position.x || Mathf.Abs(transform.position.x - unit.target.transform.position.x) <= 3)
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
    }

    protected override void ReStartCoroutines()
    {
        StartCoroutine(AIActionDecision());
    }

    IEnumerator SpearmasterEntrance()
    {
        gameObject.transform.localScale = new Vector3(-1, 1, 1);
        spineSkeletonAnimation.state.SetAnimation(1, "Cinematic/Spearmaster_Entrance_Part 1", false).TimeScale = 1f;
        
        yield return new WaitForSeconds(0.25f);
        
        gameObject.transform.position = new Vector3(gameObject.transform.position.x - 10, gameObject.transform.position.y, 0);       // cuz it flickers and shows up in screen before transitioning to entance anim

        yield return new WaitForSeconds(3);

        spineSkeletonAnimation.state.SetAnimation(1, "Cinematic/Spearmaster_Entrance_Part 2", false).TimeScale = 1f;
        spineSkeletonAnimation.state.AddAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true, 5);

        yield return new WaitForSeconds(6);

        GameManager.Instance.DisableControls = false;

        StartCoroutine(AIActionDecision());
    }
}

public enum AIAgressiveness
{
    low,
    medium,
    high,
    boss
}

[System.Serializable]
public class AIVariables
{
    public AIAgressiveness aIAgressivenesses;                                   // Agressiveness Level
    public float AttackChance;                                                  // Attack chance out of 100
    public float maxWaitAfterAttack;                                            // Max wait chance calculated by summary of two random number
    public float maxWaitAfterMovement;                                          // Same as above
}