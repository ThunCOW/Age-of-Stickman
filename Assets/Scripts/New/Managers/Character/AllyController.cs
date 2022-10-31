using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using SpineControllerVersion;
using static UnityEngine.GraphicsBuffer;

public class AllyController : UnitController
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

    public float DistanceToPlayer;
    MoveDirection directionToPlayer;

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

        StartCoroutine(AIActionDecision());
    }

    protected override void CharacterControls()
    {
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

    private IEnumerator AIActionDecision(float waitTime = 0)
    {
        while (GameManager.Instance.DisableControls)
            yield return null;

        yield return new WaitForSeconds(waitTime);

        while (GameManager.Instance.DisableControls)
            yield return null;

        if (unit.target != null)
        {
            int rand = 0;

            rand = 0;

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

                    if (spineSkeletonAnimation.AnimationName != unit.activeAnimations.Movement.SpineAnimationReference.name)
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
            while(unit.target == null)
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

                transform.position = new Vector3(transform.position.x + ((int)directionToPlayer * speed ) * Time.deltaTime, transform.position.y, transform.position.z);
                if(directionToPlayer == MoveDirection.right)
                {
                    if (transform.position.x > GameManager.Instance.Player.transform.position.x - DistanceToPlayer)
                        transform.position = new Vector2(GameManager.Instance.Player.transform.position.x - DistanceToPlayer + 0.05f, transform.position.y);
                }
                else if(directionToPlayer == MoveDirection.left)
                {
                    if (transform.position.x < GameManager.Instance.Player.transform.position.x + DistanceToPlayer)
                        transform.position = new Vector2(GameManager.Instance.Player.transform.position.x + DistanceToPlayer - 0.05f, transform.position.y);
                }

                CheckUnitDirection();

                yield return new WaitForFixedUpdate();
            }
            waitTime = Random.Range(0, aiVariable.maxWaitAfterMovement / 2);
            waitTime += Random.Range(0, aiVariable.maxWaitAfterMovement / 2);
            StartCoroutine(AIActionDecision(waitTime));
        }
    }

    public void CheckUnitDirection()
    {
        // i.e if target is more on the right but unit is looking left, turn it right
        int lookDir = transform.position.x > GameManager.Instance.Player.transform.position.x ? -1 : 1;

        transform.localScale = new Vector3(lookDir, transform.localScale.y, transform.localScale.z);
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

        if (!changeStance)
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
                for (int i = 0; i < tempAttackAnimation.Count; i++)
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
        }
        else
        {
            // if it is not close enough to attack
            StartCoroutine(MoveAndAttack(currentAttack));
        }
    }

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
        while (wait)
        {
            waitMax -= Time.deltaTime;

            if (direction == MoveDirection.waiting)
                wait = false;
            else if (unit.target == null)
                wait = false;
            else if (waitMax <= 0)
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



    protected override void ReStartCoroutines()
    {
        StartCoroutine(AIActionDecision());
    }
}
