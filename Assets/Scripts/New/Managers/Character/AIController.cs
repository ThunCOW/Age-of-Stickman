using Newtonsoft.Json.Linq;
using Spine;
using Spine.Unity;
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
    protected float newDistanceToTarget;

    protected float hitDistanceToTarget = 2f;

    protected bool preparingAttack = false;   // prevents decision making during movement attack

    [SerializeField] protected AIAgressiveness _aiAgressiveness;
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
    protected AIVariables aiVariable;
    protected Dictionary<AIAgressiveness, AIVariables> aiVariables = new Dictionary<AIAgressiveness, AIVariables>();

    protected Transform ScreenLeftBorder;
    protected Transform ScreenRightBorder;

    protected void Awake()
    {
        foreach (AIVariables variables in aiAgressivenessLevel.aiVariableList)
        {
            aiVariables.Add(variables.aIAgressivenesses, variables);
        }
    }

    protected override void Start()
    {
        base.Start();

        AIStart();
    }

    // Because ALLYController inherits from AIcontroller and has different start ( and i dont want to make another one for enemyAI), implementing this to get around
    protected virtual void AIStart()
    {
        ScreenLeftBorder = GameManager.Instance.SceneViewBordersParent.transform.GetChild(0);
        ScreenRightBorder = GameManager.Instance.SceneViewBordersParent.transform.GetChild(1);

        if (isBoss)
        {
            //if (gameObject.CompareTag(GameManager.SPEARMASTER_TAG))
            switch (gameObject.tag)
            {
                case GameManager.SPEARMASTER_TAG:
                    StartCoroutine(SpearmasterEntrance());
                    break;
                case GameManager.SCYTHEMASTER_TAG:
                    StartCoroutine(SycthemasterEntrance());
                    break;
                case GameManager.BIG_DEMON_TAG:
                    StartCoroutine(BigDemonEntrance());
                    break;
                case GameManager.DOUBLEAXEDEMON_TAG:
                    foreach(CloseCombatAnimation closeCombatAnimation in unit.activeAnimations.WalkAttack)
                    {
                        SetMixBetweenAnimation(closeCombatAnimation.SpineAnimationReference, unit.activeAnimations.idle.SpineAnimationReference, 0);
                    }
                    StartCoroutine(DoubleAxeDemonEntrance());
                    break;
                case GameManager.DEMON_SUMMONER_FIRST_APPEARANCE_TAG:
                    StartCoroutine(DemonSummonerFirstAppeareance());
                    break;
                case GameManager.DEMON_SUMMONER_TAG:
                    StartCoroutine(DemonSummonerEntrance());
                    break;
                case GameManager.DEMON_SUMMONER_END_TAG:
                    StartCoroutine(DemonSummonerEnd());
                    break;
                default:
                    break;
            }
        }
        else
        {
            if (unit.Projectile != null || (GameManager.Instance.Player.unitController as PlayerController).hasPlayerReachedEndOfLevel)
                StartCoroutine(MoveInsideCameraView());
            else
                StartCoroutine(AIActionDecision());
        }

        StartCoroutine(SuperDumbStopMovementWhenPlayerDiesCheck());
    }

    protected override void CharacterControls()
    {
        AIMovement();

        if (idleing == true) // if in idle - animation ended / movement ended / attack ended - check for unit direction relative to target position
        {
            if (unit.target != null)
            {
                //CheckUnitDirection();
            }
        }
    }

    public override bool TakeDamage(CloseCombatAnimation attack, int DamageTaken, int attackDirection = 0, bool isProjectile = false, SpineAttachment projectileAttachment = null)
    {
        // TODO LeftSpawnLazy Count leftspawns, if they enter combat remove from list, max 2 leftspawn, add to list in SpawnManager
        if (CompareTag(GameManager.ENEMY_TAG))
            GameManager.Instance.LeftSpawn.Remove(gameObject);

        return base.TakeDamage(attack, DamageTaken, attackDirection, isProjectile, projectileAttachment);
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

                // true during MoveAndAttack session, walking happens here but aiActionDecision triggers in MoveAndAttack too, so made a boolean to check it does not trigger twice
                //if (preparingAttack == false)
                //{
                //    StartCoroutine(AIActionDecision(waitTime));
                //    idleing = true;
                //}

                direction = MoveDirection.waiting;
                spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true).TimeScale = 1f;

                newDistanceToTarget = 0;
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

            //newDistanceToTarget = 32;
            idleing = true;

            direction = MoveDirection.waiting;

            spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true);

            StartCoroutine(AIActionDecision());
        }
        else
        {
            // Enters here ONLY if enemies are allowed to spawn when there is no alive ally/player unit
            waitTime = 0.3f;
            StartCoroutine(MoveInsideCameraView(waitTime));
        }
    }

    // Gets initiated at the start of the game and makes random decisions for the unit, repeats itself until it dies
    protected virtual IEnumerator AIActionDecision(float waitTime = 0)
    {
        while(GameManager.Instance.DisableControls)
            yield return null;

        yield return new WaitForSeconds(waitTime);

        while (GameManager.Instance.DisableControls)
            yield return null;

        if (unit.target != null)
        {
            int rand = 0;
            if ((GameManager.Instance.Player.unitController as PlayerController).hasPlayerReachedEndOfLevel)
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

            if (rand <= aiVariable.AttackChance) // chose to attack
            {
                AttackDecision();
            }
            else                              // chose to move closer
            {
                // If a unit is very close to target unit already, it does not move closer anymore, it idles
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

                    while(direction != MoveDirection.waiting)
                    {
                        yield return new WaitForFixedUpdate();
                    }
                    idleing = true;

                    waitTime = Random.Range(0, aiVariable.maxWaitAfterMovement / 2);
                    waitTime += Random.Range(0, aiVariable.maxWaitAfterMovement / 2);
                    StartCoroutine(AIActionDecision(waitTime));
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

    protected void AttackDecision()
    {
        float waitTime = 0;

        idleing = false;

        TrackEntry tempTrackEntry;
        // if in kick distance, there is a chance to kick
        float kickDistance = 2f;
        if (Mathf.Abs(transform.position.x - unit.target.transform.position.x) < kickDistance)
        {
            // X % chance to kick
            bool kick = Random.Range(0, 5) == 0;
            if (false)
            {
                List<BasicAnimation> tempBreakAnimation = unit.activeAnimations.BreakStance;

                int randomAttack2 = Random.Range(0, tempBreakAnimation.Count);
                BasicAnimation selectedAnim = tempBreakAnimation[randomAttack2];

                currentAttack = selectedAnim as CloseCombatAnimation;

                tempTrackEntry = spineSkeletonAnimation.state.SetAnimation(1, selectedAnim.SpineAnimationReference, false);
                float animationLength = selectedAnim.SpineAnimationReference.Animation.Duration;
                waitTime = Random.Range(animationLength / 2, (animationLength + aiVariable.maxWaitAfterAttack) / 2);
                waitTime += Random.Range(animationLength / 2, (animationLength + aiVariable.maxWaitAfterAttack) / 2);

                StartCoroutine(AIActionDecision(waitTime));

                AnimationSpeedCurveKeyframeSetup(currentAttack.speedCurve, currentAttack.Keys, currentAttack.Values);
                StartCoroutine(SpeedDuringAnimation(tempTrackEntry, currentAttack.speedCurve));

                if (selectedAnim.ShadowAnimation != null)
                    ShadowAnimator.Play(selectedAnim.ShadowAnimation.name);

                return;
            }
        }
        // if there are multiple stances, we can change stance
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

        // if it is not going to change stance, select attack state
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

        // if it is close enough to attack, attack and start next courutine for decision
        if (Mathf.Abs(transform.position.x - unit.target.transform.position.x) < currentAttack.Reach)
        {
            tempTrackEntry = spineSkeletonAnimation.state.SetAnimation(1, currentAttack.SpineAnimationReference, false);
            float animationLength = currentAttack.SpineAnimationReference.Animation.Duration;
            waitTime = Random.Range(animationLength / 2, (animationLength + aiVariable.maxWaitAfterAttack) / 2);
            waitTime += Random.Range(animationLength / 2, (animationLength + aiVariable.maxWaitAfterAttack) / 2);
            
            StartCoroutine(AIActionDecision(waitTime));

            AnimationSpeedCurveKeyframeSetup(currentAttack.speedCurve, currentAttack.Keys, currentAttack.Values);
            StartCoroutine(SpeedDuringAnimation(tempTrackEntry, currentAttack.speedCurve));

            if (currentAttack.ShadowAnimation != null)
                ShadowAnimator.Play(currentAttack.ShadowAnimation.name);
        }
        else
        {
            unit.TurnTowardsTarget();
            
            StartCoroutine(MoveAndAttack(currentAttack));
        }
    }

    //Coroutine MoveAndAttackCoroutine = null;
    // Activates movement and waits until in reach distance, and attacks
    protected IEnumerator MoveAndAttack(CloseCombatAnimation attack)
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
                // I think i added this to make bosses that can leap work while following player
                if (changeStance == true) changeStance = false;
                AttackDecision();
                yield break;
            }
            yield return null;
        }
        //yield return new WaitUntil(() => direction == MoveDirection.waiting || unit.target == null);
        // target died, if there is no target stop moving forward
        if (unit.target == null)
        {
            newDistanceToTarget = 0;
            direction = MoveDirection.waiting;
            spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true).TimeScale = 1f;
            preparingAttack = false;
            idleing = true;
            StartCoroutine(AIActionDecision()); // waits until animation ends, so does not make decisions during animation
            yield break;
        }

        TrackEntry tempTrackEntry = spineSkeletonAnimation.state.SetAnimation(1, attack.SpineAnimationReference, false);
        float animationLength = attack.SpineAnimationReference.Animation.Duration;
        float waitTime = Random.Range(animationLength / 2, (animationLength + aiVariable.maxWaitAfterAttack) / 2);
        waitTime += Random.Range(animationLength / 2, (animationLength + aiVariable.maxWaitAfterAttack) / 2);
        preparingAttack = false;

        StartCoroutine(AIActionDecision(waitTime)); // waits until animation ends, so does not make decisions during animation

        AnimationSpeedCurveKeyframeSetup(currentAttack.speedCurve, currentAttack.Keys, currentAttack.Values);
        StartCoroutine(SpeedDuringAnimation(tempTrackEntry, currentAttack.speedCurve));

        if (attack.ShadowAnimation != null)
            ShadowAnimator.Play(attack.ShadowAnimation.name);

        // only works if there is an object to spawn, still needs to wait for animation event to fire/throw/use it
        //if (attack.rangedSpawnPrefab != null)
        //    StartCoroutine(UseRangedWeapon(attack));

        /*if (currentStance == StanceList.Stand_A_transition_B)
            currentStance = StanceList.Stand_B;
        if (currentStance == StanceList.Stand_B_transition_A)
            currentStance = StanceList.Stand_A;*/
    }

    protected IEnumerator SuperDumbStopMovementWhenPlayerDiesCheck()
    {
        // Movement was handled in FixedUpdate and ran continuesly but if player was to die during enemy movement
        // there was no way to stop movement and set animation back to idle etc ( not that i could think of ) so i am making this super dumb coroutine
        
        while(unit.target == null)                  // Leaves while when target is found
        {
            yield return new WaitForFixedUpdate();
        }

        while(unit.target != null)                  // Leavess while when target is lost ( null )
        {
            yield return new WaitForFixedUpdate();
        }
        // wait until player is dead
        
        while(isAnimationStarted)
        {
            yield return new WaitForFixedUpdate();

            // If Ai unit is outside of screen borders, we let it continue to move inside screen
            if (gameObject.transform.position.x > ScreenRightBorder.transform.position.x ||
                gameObject.transform.position.x < ScreenLeftBorder.transform.position.x)
            {
                StartCoroutine(SuperDumbStopMovementWhenPlayerDiesCheck());
                yield break;
            }
        }

        float waitTime = Random.Range(0, aiVariable.maxWaitAfterMovement / 2);
        waitTime += Random.Range(0, aiVariable.maxWaitAfterMovement / 2);

        direction = MoveDirection.waiting;
        
        spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true).TimeScale = 1f;

        newDistanceToTarget = 0;

        //yield return new WaitUntil(() => PlayerController.isWaitingForRes == false);
        StartCoroutine(SuperDumbStopMovementWhenPlayerDiesCheck());
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
    IEnumerator DoubleAxeDemonEntrance()
    {
        gameObject.transform.localScale = new Vector3(-1, 1, 1);

        spineSkeletonAnimation.state.SetAnimation(1, "DoubleAxeHuge/Idle4", true);

        yield return new WaitForSeconds(15);

        TextBoxManager textBoxSpawn = Instantiate(GameManager.Instance.TextBoxPrefab).GetComponent<TextBoxManager>();
        textBoxSpawn.transform.position = new Vector3(transform.position.x, transform.position.y + 2f, 0);

        textBoxSpawn.Text.text = GetComponent<UnitDialogues>().dialogueList[0].Context;

        textBoxSpawn.ShowText(textBoxSpawn.Text.text = GetComponent<UnitDialogues>().dialogueList[0].Context);

        yield return new WaitUntil(() => textBoxSpawn.IsEnded);

        yield return new WaitForSeconds(1.5f);

        GameManager.Instance.DisableControls = false;

        StartCoroutine(AIActionDecision());
    }

    IEnumerator DemonSummonerFirstAppeareance()
    {
        gameObject.transform.localScale = new Vector3(-1, 1, 1);
        spineSkeletonAnimation.state.SetAnimation(1, "Demon Magician/idle", true);

        yield return new WaitForSeconds(7);

        TextBoxManager textBoxSpawn = Instantiate(GameManager.Instance.TextBoxPrefab).GetComponent<TextBoxManager>();
        textBoxSpawn.transform.position = new Vector3(transform.position.x, transform.position.y + 2f, 0);

        textBoxSpawn.ShowText(GetComponent<UnitDialogues>().dialogueList[0].Context);

        yield return new WaitUntil(() => textBoxSpawn.IsEnded);

        yield return new WaitForSeconds(1.5f);

        TrackEntry trackEntry = spineSkeletonAnimation.state.SetAnimation(1, "Demon Magician/Exit", false);

        yield return new WaitForSpineAnimationComplete(trackEntry);

        Destroy(gameObject);
    }
    IEnumerator DemonSummonerEntrance()
    {
        gameObject.transform.localScale = new Vector3(-1, 1, 1);
        spineSkeletonAnimation.state.SetAnimation(1, "Demon Magician/idle", true);

        yield return new WaitForSeconds(7);

        spineSkeletonAnimation.state.SetAnimation(1, "Demon Magician/OpenBook_1", false);

        TextBoxManager textBoxSpawn = Instantiate(GameManager.Instance.TextBoxPrefab).GetComponent<TextBoxManager>();
        textBoxSpawn.transform.position = new Vector3(transform.position.x, transform.position.y + 2f, 0);

        textBoxSpawn.ShowText(GetComponent<UnitDialogues>().dialogueList[0].Context);

        yield return new WaitUntil(() => textBoxSpawn.IsEnded);

        yield return new WaitForSeconds(0.5f);

        TrackEntry trackEntry = spineSkeletonAnimation.state.SetAnimation(1, "Demon Magician/OpenBook_2", false);

        int frameToOpenBook = 5;
        while(frameToOpenBook > 0)
        {
            frameToOpenBook--;

            yield return new WaitForFixedUpdate();
        }

        //float spawnPosX = GameManager.Instance.Player.transform.position.x + 8.5f; // +10 cuz it flickers and shows up in screen before transitioning to entance anim
        GameObject spawnedBookParticle = Instantiate(GameManager.Instance.BookParticlePrefab, gameObject.transform);

        yield return new WaitForSpineAnimationComplete(trackEntry);

        //
        // Spawn Portal
        //

        SoundManager.Instance.PlayEffect(GameManager.Instance.PortalOpeningSFX);
        SoundManager.Instance.PlayEffect(GameManager.Instance.PortalIdleSFX);

        float spawnPosX = GameManager.Instance.Player.transform.position.x + 8.5f; // +10 cuz it flickers and shows up in screen before transitioning to entance anim
        GameObject spawnedPortal = Instantiate(GameManager.Instance.PortalPrefab, new Vector3(spawnPosX, GameManager.Instance.PortalPrefab.transform.position.y, 0), GameManager.Instance.PortalPrefab.transform.rotation);

        spawnedPortal.transform.GetChild(1).gameObject.SetActive(false);

        spawnedPortal.transform.localScale = new Vector3(0.1f, 0.1f, 1);

        //yield return new WaitForSeconds(1.5f);

        spawnedPortal.transform.GetChild(1).gameObject.SetActive(true);

        float countDown = 0.15f;
        while (countDown <= 1.5f)
        {
            countDown += Time.deltaTime;
            float perc = countDown / 1.5f;

            spawnedPortal.transform.localScale = new Vector2(perc, perc);

            yield return new WaitForFixedUpdate();
        }

        spawnedPortal.transform.localScale = Vector3.one;

        yield return new WaitForSeconds(1.5f);

        float countdownToDestroyBookParticle = 1.5f;
        while(countdownToDestroyBookParticle > 0.5f)
        {
            countdownToDestroyBookParticle-= Time.deltaTime;
            float perc = countdownToDestroyBookParticle / 1;
            spawnedBookParticle.transform.localScale = new Vector3(1, perc, 1);
            yield return new WaitForFixedUpdate();
        }
        spineSkeletonAnimation.state.SetAnimation(1, "Demon Magician/SummonDemon", false);

        while(countdownToDestroyBookParticle > 0)
        {
            countdownToDestroyBookParticle -= Time.deltaTime;
            float perc = countdownToDestroyBookParticle / 1;
            spawnedBookParticle.transform.localScale = new Vector3(1, perc, 1);
            yield return new WaitForFixedUpdate();
        }
        Destroy(spawnedBookParticle);

        StartCoroutine(BigDemonSoundEffect());

        yield return new WaitForSeconds(0.5f);

        //
        // Spawn Big Boss
        //

        spawnPosX = GameManager.Instance.Player.transform.position.x + 9f + 30;
        GameObject spawnedEnemyGO = Instantiate(GameManager.Instance.BigBossPrefab, new Vector3(spawnPosX, GameManager.Instance.BigBossPrefab.transform.position.y, 0), GameManager.Instance.BigBossPrefab.transform.rotation);

        AIController spawnedEnemyUnit = spawnedEnemyGO.GetComponent<AIController>();
        spawnedEnemyUnit.aiAgressiveness = AIAgressiveness.boss;

        yield return new WaitForFixedUpdate();

        spawnedEnemyGO.transform.position = new Vector3(spawnedEnemyGO.transform.position.x - 30, spawnedEnemyGO.transform.position.y, 0);

        yield return new WaitForSeconds(5);



        textBoxSpawn = Instantiate(GameManager.Instance.TextBoxPrefab).GetComponent<TextBoxManager>();
        textBoxSpawn.transform.position = new Vector3(transform.position.x, transform.position.y + 2f, 0);

        textBoxSpawn.ShowText(GetComponent<UnitDialogues>().dialogueList[1].Context);

        yield return new WaitUntil(() => textBoxSpawn.IsEnded);

        yield return new WaitForSeconds(1.5f);

        SoundManager.Instance.PlayEffect(GameManager.Instance.PortalClosingSFX);

        trackEntry = spineSkeletonAnimation.state.SetAnimation(1, "Demon Magician/Exit", false);

        // Close Portal

        float countdownToDestroyPortal = 1;
        while(countdownToDestroyPortal > 0)
        {
            countdownToDestroyPortal -= Time.deltaTime;
            float perc = countdownToDestroyPortal / 1;
            spawnedPortal.transform.localScale = new Vector3(perc, perc, 1);
            yield return new WaitForFixedUpdate();
        }
        Destroy(spawnedPortal);

        yield return new WaitForSpineAnimationComplete(trackEntry);

        Destroy(gameObject);
    }
    IEnumerator DemonSummonerEnd()
    {
        gameObject.transform.localScale = new Vector3(-1, 1, 1);
        spineSkeletonAnimation.state.SetAnimation(1, "Demon Magician/idle", true);

        yield return new WaitForSeconds(7);
    }
    IEnumerator BigDemonEntrance()
    {
        gameObject.transform.localScale = new Vector3(-1, 1, 1);

        TrackEntry trackEntry = spineSkeletonAnimation.state.SetAnimation(1, "Big_Stickman/Entrance_Portal3", false);

        direction = MoveDirection.left;
        StartCoroutine(SpeedDuringAnimation(trackEntry, GameManager.Instance.BigDemonEntrance.speedCurve));

        yield return new WaitForSpineAnimationComplete(trackEntry);

        spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true);

        spineSkeletonAnimation.maskInteraction = SpriteMaskInteraction.None;

        yield return new WaitForSeconds(5.5f);

        GameManager.Instance.DisableControls = false;

        StartCoroutine(AIActionDecision());
    }

    IEnumerator BigDemonSoundEffect()
    {
        SoundManager.Instance.PlayEffect(GameManager.Instance.Big_Demon_Entrance);

        yield return new WaitForSeconds(4.2f);

        SoundManager.Instance.PlayEffect(GameManager.Instance.Big_Mace_Drop);
    }

    IEnumerator SpearmasterEntrance()
    {
        gameObject.transform.localScale = new Vector3(-1, 1, 1);
        TrackEntry trackEntry = spineSkeletonAnimation.state.SetAnimation(1, "Cinematic/Spearmaster_Entrance_Part 1", false);
        
        yield return new WaitForSeconds(0.25f);
        
        gameObject.transform.position = new Vector3(gameObject.transform.position.x - 10, gameObject.transform.position.y, 0);       // cuz it flickers and shows up in screen before transitioning to entance anim

        yield return new WaitForSpineAnimationComplete(trackEntry);
        yield return new WaitForSeconds(1);

        trackEntry = spineSkeletonAnimation.state.SetAnimation(1, "Cinematic/Spearmaster_Entrance_Part 2", false);
        
        yield return new WaitForSpineAnimationComplete(trackEntry);
        yield return new WaitForSeconds(0.5f);
        
        spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true);

        yield return new WaitForSeconds(0.5f);

        GameManager.Instance.DisableControls = false;

        StartCoroutine(AIActionDecision());
    }

    IEnumerator SycthemasterEntrance()
    {
        SetMixBetweenAnimation(unit.activeAnimations.idle.SpineAnimationReference.Animation.Name, "Cinematic/SYCTHEMASTER_ENTRANCE", 0);
        SetMixBetweenAnimation("Double_Scythe/DoubleSyctheAttackStandingE1.1.4.2 UNITY", "Double_Scythe/DoubleSyctheWalkA2.1.3.1", 0);
        SetMixBetweenAnimation("Double_Scythe/DoubleSyctheAttackStandingE1.1.4.2 UNITY", "Double_Scythe/DoubleSyctheIdle", 0);

        yield return new WaitForSeconds(5);

        TrackEntry anim = spineSkeletonAnimation.state.SetAnimation(1, "Cinematic/SYCTHEMASTER_ENTRANCE", false);

        yield return new WaitForFixedUpdate();

        gameObject.transform.localScale = new Vector3(-1, 1, 1);
        transform.position = new Vector3(GameManager.Instance.Player.transform.position.x + 12.75f/2, transform.position.y);

        yield return new WaitForSpineAnimationComplete(anim);

        transform.position = new Vector3(GameManager.Instance.Player.transform.position.x + 12.75f, transform.position.y, 0);

        yield return new WaitForSeconds(2);

        anim = spineSkeletonAnimation.state.SetAnimation(1, "Cinematic/SYCTHEMASTER_ENTRANCE2", false);

        yield return new WaitForSpineAnimationComplete(anim);

        spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true);
        
        GameManager.Instance.DisableControls = false;

        StartCoroutine(AIActionDecision());
        yield return null;
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