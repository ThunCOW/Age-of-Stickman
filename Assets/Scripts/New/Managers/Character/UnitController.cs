using Spine;
using Spine.Unity;
using SpineControllerVersion;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public enum MoveDirection
{
    left = -1,
    right = 1,
    waiting = 0
}

public class UnitController : MonoBehaviour
{
    [Space]
    protected BoxCollider2D boxCollider2;

    public SkeletonAnimation spineSkeletonAnimation;
    public Animator ShadowAnimator;

    protected Unit unit;
    protected EquipmentManager equipmentManager;

    protected bool canMove = true;
    [HideInInspector] public bool isAnimationStarted = false;   // Animations require direction to be consistent

    protected bool idleing;

    [HideInInspector] public float extraSpeed;   // just temporary for charge speed, it is retrived from AnimationList and assigned in editor
    public float speed; // default moving speed assigned in inspector
    protected float defaultSpeed; // stores default speed
    protected float speedRelativeToAnimation; // speed for animations
    protected MoveDirection direction = MoveDirection.waiting;

    protected bool blockTrigger = false;
    protected bool resurrectionState = false;

    bool _changeStance = false;
    protected bool changeStance
    {
        get { return _changeStance; }
        set
        {
            _changeStance = value;
        }
    }

    public bool isBoss;

    protected Transform LeftWallPosition;
    protected Transform RightWallPosition;

    public delegate void OnControlsDisabled();
    public OnControlsDisabled ResetAttachments;

    // Start is called before the first frame update

    protected virtual void OnValidate()
    {
        if (ShadowAnimator == null)
            ShadowAnimator = GetComponentInChildren<Animator>();
    }

    protected virtual void Start()
    {
        boxCollider2 = GetComponent<BoxCollider2D>();

        unit = GetComponent<Unit>();
        equipmentManager = GetComponent<EquipmentManager>();

        spineSkeletonAnimation.state.Event += HandleAnimationStateEvent;

        defaultSpeed = speed;

        LeftWallPosition = GameManager.Instance.LevelBordersParent.transform.GetChild(0);
        RightWallPosition = GameManager.Instance.LevelBordersParent.transform.GetChild(1);

        GameManager.DisableAllControls += GamePaused;
        GameManager.EnableAllControls += GameContinue;

        EquipmentManager tempEM = GetComponent<EquipmentManager>();
        tempEM.OnArrowRelease += ProjectileRelease;

        SetMixBetweenAnimation(unit.activeAnimations.idle.SpineAnimationReference, unit.activeAnimations.Movement.SpineAnimationReference, 0);
        SetMixBetweenAnimation(unit.activeAnimations.Movement.SpineAnimationReference, unit.activeAnimations.idle.SpineAnimationReference, 0);

        SetMixBetweenAnimation(unit.activeAnimations.BreakStance[0].SpineAnimationReference, unit.activeAnimations.idle.SpineAnimationReference, 0);
        SetMixBetweenAnimation(unit.activeAnimations.BreakStance[1].SpineAnimationReference, unit.activeAnimations.idle.SpineAnimationReference, 0);

        SetMixBetweenAnimation(unit.activeAnimations.idle.SpineAnimationReference, unit.activeAnimations.BreakStance[0].SpineAnimationReference, 0);
        SetMixBetweenAnimation(unit.activeAnimations.idle.SpineAnimationReference, unit.activeAnimations.BreakStance[1].SpineAnimationReference, 0);

        SetMixBetweenAnimation(unit.activeAnimations.Movement.SpineAnimationReference, unit.activeAnimations.BreakStance[0].SpineAnimationReference, 0);
        SetMixBetweenAnimation(unit.activeAnimations.Movement.SpineAnimationReference, unit.activeAnimations.BreakStance[1].SpineAnimationReference, 0);

        SetMixBetweenAnimation(unit.activeAnimations.MovementBackward.SpineAnimationReference, unit.activeAnimations.BreakStance[0].SpineAnimationReference, 0);
        SetMixBetweenAnimation(unit.activeAnimations.MovementBackward.SpineAnimationReference, unit.activeAnimations.BreakStance[1].SpineAnimationReference, 0);
        // Hurt animation should be 0
        //foreach(BasicAnimation basicAnimation in unit.activeAnimations)
    }

    // Update is called once per frame
    void Update()
    {
        if (GameManager.Instance.DisableControls == false)
        {
            if (unit.Health > 0) // Only if alive
            {
                if (idleing == true && unit.target != null) unit.SetUnitDirection();        // Turns towards target while in idle only

                CharacterControls();
            }
        }
    }

    void FixedUpdate()
    {
        if (canMove)
            transform.position = new Vector3(transform.position.x + ((int)direction * (speed + speedRelativeToAnimation + extraSpeed)) * Time.deltaTime, transform.position.y, transform.position.z);
    }

    protected virtual void CharacterControls() { }
    protected CloseCombatAnimation currentAttack = null;
    public void DealDamage()
    {
        // scenario 1: there were multiple target in front of unit, one of them died, now need to change target
        // scenario 2: the target in front died, and there is no target in front or any at all

        // If target is dead
        if (unit.target == null)
            unit.FindClosestUnit();

        // scenario 2
        if (unit.target == null)
        {
            currentAttack.SoundObject.swooshSoundEffect.PlayRandomSoundEffect();

            return;
        }

        // TODO sortingManager 
        //GameManager.Instance.sortManager.BringToFront(this);
        GameManager.Instance.sortManager.ChangePlayerSortOnly(unit, unit.target);

        int dir;

        // i.e current unit is on the right, target is on the left, target will be pushed to left
        if (transform.position.x > unit.target.transform.position.x)
            dir = (int)MoveDirection.left;
        else
            dir = (int)MoveDirection.right;

        // i.e if target is being pushed to right, current unit must be looking right to land the hit, if its not looking right, misses it
        if (dir == (int)MoveDirection.right && transform.localScale.x < 0.1)
        {
            currentAttack.SoundObject.swooshSoundEffect.PlayRandomSoundEffect();

            return;
        }
        else if (dir == (int)MoveDirection.left && transform.localScale.x > 0.1)
        {
            currentAttack.SoundObject.swooshSoundEffect.PlayRandomSoundEffect();

            return;
        }

        // TODO: needs fixing later
        // If target is in damage distance, succesfully landed the hit.
        if (Mathf.Abs(unit.target.GetComponent<BoxCollider2D>().ClosestPoint(transform.position).x - transform.position.x) < currentAttack.Reach)
        {
            int chance = Random.Range(0, 100);
            
            float softDamage = unit.Damage * 0.1f;
            // low damage 15%
            if(chance <= 14)
            {
                softDamage += Random.Range(0, unit.Damage * 0.9f);
            }
            // normal damage 40%
            else if(chance >= 15 && chance < 65)
            {
                softDamage += unit.Damage * 0.4f;
                softDamage += Random.Range(0, unit.Damage / 2);
                softDamage -= Random.Range(0, unit.Damage / 2);
            }
            // high damage 45%
            else
            {
                softDamage += unit.Damage * 0.6f;
                softDamage += Random.Range(0, unit.Damage * 0.3f);
            }
            int damageDealt = (int)(softDamage);

            damageDealt = Random.Range(0, 100) >= 50 ? (int)(softDamage) : ((int)(softDamage * currentAttack.DamageMultiplierMax));

            if (unit.CompareTag(GameManager.PLAYER_TAG)) Debug.Log(damageDealt + "\n Solid damage point = " + ((uint)unit.Damage) + " / Chance = " + chance);

            //float softDamage = Random.Range(0, unit.Damage / 2) + Random.Range(0, unit.Damage / 2);
            //int damageDealt = (int)(softDamage * Random.Range(1, currentAttack.DamageMultiplierMax));
            //Debug.Log("Soft Damage = " + softDamage + " / Damage Dealth = " + damageDealt + " / DamageMultiplier = " + currentAttack.DamageMultiplierMax);

            if (currentAttack.DamageMultiplierMax == 0)
                Debug.LogError("DAMAGE MULTIPLIER OF ANIMATION IS NOT SET!");

            unit.target.unitController.TakeDamage(currentAttack, damageDealt, dir);
        }
        else
        {
            currentAttack.SoundObject.swooshSoundEffect.PlayRandomSoundEffect();
        }
    }

    // Moved over to Projectile script
    public void ProjectileDamage()
    {
        int dir;

        if (transform.position.x > unit.target.transform.position.x)
            dir = (int)MoveDirection.left;
        else
            dir = (int)MoveDirection.right;

        float softDamage = Random.Range(0, unit.Damage / 2) + Random.Range(0, unit.Damage / 2);
        int damageDealt = (int)(softDamage * Random.Range(1, currentAttack.DamageMultiplierMax));

        if (currentAttack.DamageMultiplierMax == 0)
            Debug.LogError("DAMAGE MULTIPLIER OF ANIMATION IS NOT SET!");

        unit.target.unitController.TakeDamage(currentAttack, damageDealt, dir);
    }       

    public void ProjectileRelease()
    {
        GameObject projectile = Instantiate(unit.Projectile, unit.gameObject.transform);
        projectile.GetComponent<Projectile>().projectileAttack = currentAttack;

        currentAttack.SoundObject.swooshSoundEffect.PlayRandomSoundEffect();
    }

    /// <summary>
    /// Returns true when hit succesfully damaged
    /// </summary>
    public virtual bool TakeDamage(CloseCombatAnimation attack,int DamageTaken, int attackDirection = 0, bool isProjectile = false)
    {
        if(blockTrigger)
        {
            SoundManager.Instance.PlayEffect(SoundManager.Instance.ShieldHitSound[Random.Range(0, SoundManager.Instance.ShieldHitSound.Count)]);

            //unit.SetUnitDirection(attackDirection * -1);
            return false;
        }
        if(resurrectionState)
        {
            attack.SoundObject.hitSoundEffect.PlayRandomSoundEffect();

            return false;
        }

        attack.SoundObject.hitSoundEffect.PlayRandomSoundEffect();

        unit.Health -= DamageTaken;

        equipmentManager.ResetAttachments();

        if (unit.Health <= 0)
        {
            UnitDead(attack, attackDirection);
        }
        // This part is for bossess, gonna leave it for now, only bosses dont have hurt anim
        else if (unit.activeAnimations.Hurt == null)
        {
            if(attack.attackType == AttackType.Casual)
            {
                // boss dont stop movement in hits
            }
            else
            {
                unit.SetUnitDirection();

                StopAllCoroutines();
                StartCoroutine(StunnedFor(attack));
            }
        }
        // Unit got hurt,
        else
        {
            if (!isProjectile) unit.SetUnitDirection(attackDirection * -1);

            StopAllCoroutines();
            StartCoroutine(StunnedFor(attack));
        }

        if (attack.attackType != AttackType.Kick && attack.attackType != AttackType.Shield)
        {
            GameObject blood_go = Instantiate(unit.bloodObject);
            blood_go.transform.position = new Vector3(transform.position.x, attack.hitHeightPosiiton, unit.bloodObject.transform.position.z);
        }

        if(isProjectile)
        {
            bool isHitFromBehind = false;
            if (attackDirection == transform.localScale.x)
                isHitFromBehind = true;
            
            equipmentManager.ArrowOnBody(isHitFromBehind);
        }
        
        return true;
    }

    protected virtual void UnitDead(CloseCombatAnimation attack, int attackDirection = 0)
    {
        if (unit.CompareTag(GameManager.PLAYER_TAG))
        {
            if (GameManager.Instance.PlayerLives == 0)
            {
                // Player Dies bring up you are dead screen
            }
            else
            {
                // Player Lives Decreases
                GameManager.Instance.PlayerLivesChange(-1);

                unit.SetUnitDirection(attackDirection * -1);
                StopRoutine();
                //StopAllCoroutines();
                //return;
            }
        }

        boxCollider2.enabled = false;

        if (isBoss)
        {
            //canMove = false;

            BossDead();

            unit.target.unitController.BossDead();

            if (Unit.CompareTags(gameObject, GameManager.ENEMY_TAGS))
            {
                GameManager.Instance.EnemyUnits.Remove(unit);
            }
            else
                GameManager.Instance.AllyUnits.Remove(unit);

            GameObject finishLevelTrigger = RightWallPosition.GetChild(0).gameObject;
            finishLevelTrigger.transform.position = new Vector3(GameManager.Instance.Player.transform.position.x + 7.7f, finishLevelTrigger.transform.position.y, 0);
            finishLevelTrigger.SetActive(true);

            //GameManager.Instance.sortManager.RemoveFromOrder(unit);
            //return;
        }
        unit.SetUnitDirection(attackDirection * -1);
        StopRoutine();

        canMove = false;

        int randomDeath = 0;
        List<DeathAnimation> deathAnimation;
        DeathAnimation tempDeathAnim = null;
        switch (attack.attackRegion)
        {
            case HitRegion.High:
                deathAnimation = unit.activeAnimations.DeathAnimationByDamageRegion.highRegion;
                randomDeath = Random.Range(0, deathAnimation.Count);
                tempDeathAnim = deathAnimation[randomDeath];
                spineSkeletonAnimation.state.SetAnimation(1, tempDeathAnim.SpineAnimationReference, false).TimeScale = 1f;
                if (tempDeathAnim.ShadowAnimation != null)
                    ShadowAnimator.Play(tempDeathAnim.ShadowAnimation.name);
                break;
            case HitRegion.Mid:
                deathAnimation = unit.activeAnimations.DeathAnimationByDamageRegion.midRegion;
                randomDeath = Random.Range(0, deathAnimation.Count);
                tempDeathAnim = deathAnimation[randomDeath];
                spineSkeletonAnimation.state.SetAnimation(1, tempDeathAnim.SpineAnimationReference, false).TimeScale = 1f;
                if (tempDeathAnim.ShadowAnimation != null)
                    ShadowAnimator.Play(tempDeathAnim.ShadowAnimation.name);
                break;
            case HitRegion.Low:
                deathAnimation = unit.activeAnimations.DeathAnimationByDamageRegion.lowRegion;
                randomDeath = Random.Range(0, deathAnimation.Count);
                tempDeathAnim = deathAnimation[randomDeath];
                spineSkeletonAnimation.state.SetAnimation(1, tempDeathAnim.SpineAnimationReference, false).TimeScale = 1f;
                if (tempDeathAnim.ShadowAnimation != null)
                    ShadowAnimator.Play(tempDeathAnim.ShadowAnimation.name);
                break;
            default:
                break;
        }
        if (tempDeathAnim is DeathByDismemberAnimation)
            DismemberBody(tempDeathAnim as DeathByDismemberAnimation);

        // Dead enemies drop gold ( boss tag exc )
        if (gameObject.CompareTag(GameManager.ENEMY_TAG))
        {
            // There should be a chance for enemy to drop like 10 gold and play gold sound at higher levels

            //GameManager.Instance.Level

            int goldAmount = 0;
            int dropChance = 0;
            dropChance = Random.Range(0, 100);
            if (GameManager.Instance.Level <= 3)
            {
                if (dropChance > 60)
                {
                    goldAmount = 1;
                    goldAmount += Random.Range(0, 2);
                    goldAmount += Random.Range(0, 2);

                    GoldDrop(goldAmount);
                }
            }
            else if (GameManager.Instance.Level > 3 && GameManager.Instance.Level <= 7)
            {
                if (dropChance > 50)
                {
                    goldAmount = 2;
                    goldAmount -= Random.Range(0, 2);
                    goldAmount += Random.Range(0, 2);
                    GoldDrop(goldAmount);
                }
            }
            else if (GameManager.Instance.Level > 7 && GameManager.Instance.Level <= 15)
            {
                if (dropChance > 50)
                {
                    goldAmount = 3;
                    goldAmount -= Random.Range(0, 3);
                    goldAmount += Random.Range(0, 4);
                    GoldDrop(goldAmount);
                }
            }
            else
            {
                if (dropChance > 40)
                {
                    goldAmount = 6;
                    goldAmount -= Random.Range(0, 4);
                    goldAmount += Random.Range(0, 5);
                    GoldDrop(goldAmount);
                }
            }
        }


        if (Unit.CompareTags(gameObject, GameManager.ENEMY_TAGS))
        {
            GameManager.Instance.EnemyUnits.Remove(unit);
            // TODO LeftSpawnLazy Count leftspawns, if they enter combat remove from list, max 2 leftspawn, add to list in SpawnManager
            GameManager.Instance.LeftSpawn.Remove(gameObject);
        }
        else
            GameManager.Instance.AllyUnits.Remove(unit);

        GameManager.Instance.sortManager.RemoveFromOrder(unit);
    }
    protected void BossDead()
    {
        StopRoutine();
        //StopAllCoroutines();

        CinematicAction cAnim = GetComponent<CinematicAction>();

        if(gameObject.CompareTag(GameManager.PLAYER_TAG))
        {
            ResetAttachments();
            
            GameManager.Instance.DisableControls = true;
            
            StartCoroutine(PlayCinematicAnimation(cAnim.SpearmasterDead, true));

            ReStartCoroutines();
        }
        else
        {
            unit.GetComponentInChildren<MeshRenderer>().sortingOrder = 1000;

            float distBetween = Mathf.Abs(gameObject.transform.position.x - unit.target.transform.position.x);
            if (distBetween != 1.6f)
            {
                float distToMove = 0;
                if (distBetween > 1.6f)
                    distToMove = distBetween - 1.6f;
                else
                    distToMove = distBetween - 1.6f;

                float speed = distToMove / 0.3666f;

                Keyframe[] keyframe = cAnim.SpearmasterDead.speedCurve.keys;

                for (int i = 0; i < cAnim.SpearmasterDead.Keys.Count; i++)
                {
                    keyframe[cAnim.SpearmasterDead.Keys[i]].value = speed;
                }
                cAnim.SpearmasterDead.speedCurve.keys = keyframe;
            }

            StartCoroutine(PlayCinematicAnimation(cAnim.SpearmasterDead, false));
        }
    }

    protected void DismemberBody(DeathByDismemberAnimation deathAnimation)
    {
        // Head part
        if(deathAnimation.BodyPart == DeathByDismemberAnimation.BodyPartType.Head)
        {
            if (deathAnimation.CutPart != null)
            {
                // Spawn Body Part and set initial position and scales
                Vector3 cutSpawnPos = deathAnimation.CutPart.transform.position;
                GameObject cut_part = Instantiate(deathAnimation.CutPart, gameObject.transform);
                cut_part.transform.localPosition = new Vector3(cutSpawnPos.x, cutSpawnPos.y, cutSpawnPos.z);
                cut_part.transform.localScale = new Vector3(cut_part.transform.parent.transform.localScale.x, 1, 1);

                // Randomize a fling degree and get vector equivalent
                float degree = Random.Range(0, 180);
                float degreeToRad = degree * Mathf.Deg2Rad;
                Vector2 radToVec2 = new Vector2(Mathf.Cos(degreeToRad), Mathf.Sin(degreeToRad));

                // Add speed on X and Y axis calculated above, force amount is also randomized
                cut_part.GetComponent<Rigidbody2D>().AddForce(radToVec2 * Random.Range(300, 500));

                // Add torque to make it spin around
                int torqDir = radToVec2.x > 0 ? -1 : 1;
                cut_part.GetComponent<Rigidbody2D>().AddTorque(Random.Range(40, 100) * torqDir, ForceMode2D.Force);
            }
        }
        // Leg part
        else
        {
            if (deathAnimation.CutPart != null)
            {
                // Spawn Body Part and set initial position and scales
                Vector3 cutSpawnPos = deathAnimation.CutPart.transform.position;
                GameObject cut_part = Instantiate(deathAnimation.CutPart, gameObject.transform);
                cut_part.transform.localPosition = new Vector3(cutSpawnPos.x, cutSpawnPos.y, cutSpawnPos.z);
                //cut_part.transform.localScale = new Vector3(cut_part.transform.parent.transform.localScale.x, cut_part.transform., 1);

                // Randomize a fling degree and get vector equivalent
                float degree = Random.Range(0, -180);
                float degreeToRad = degree * Mathf.Deg2Rad;
                Vector2 radToVec2 = new Vector2(Mathf.Cos(degreeToRad), Mathf.Sin(degreeToRad));

                // Add speed on X and Y axis calculated above, force amount is also randomized
                cut_part.GetComponent<Rigidbody2D>().AddForce(radToVec2 * Random.Range(100, 200));

                // Add torque to make it spin around
                int torqDir = radToVec2.x > 0 ? -1 : 1;
                cut_part.GetComponent<Rigidbody2D>().AddTorque(Random.Range(15, 30) * torqDir, ForceMode2D.Force);
            }
        }
    }

    private void GoldDrop(int SpawnAmount)
    {
        List<GameObject> tempSpawnObjects = new List<GameObject>();

        int i = 0;
        // Spawn Gold and set initial position and scales
        for (; i < SpawnAmount; i++)
        {
            Vector3 goldPos = GameManager.Instance.GoldPrefab.transform.position;
            GameObject gold = Instantiate(GameManager.Instance.GoldPrefab, gameObject.transform);
            gold.transform.localPosition = new Vector3(goldPos.x, goldPos.y, goldPos.z);
            gold.transform.localScale = new Vector3(gold.transform.parent.transform.localScale.x, 1, 1);
            gold.transform.parent = null;
            tempSpawnObjects.Add(gold);
        }
        
        i--;
        for(; i >= 0; --i)
        {
            // Randomize a fling degree and get vector equivalent
            float degree = Random.Range(0, 180);
            float degreeToRad = degree * Mathf.Deg2Rad;
            Vector2 radToVec2 = new Vector2(Mathf.Cos(degreeToRad), Mathf.Sin(degreeToRad));

            // Add speed on X and Y axis calculated above, force amount is also randomized
            tempSpawnObjects[i].GetComponent<Rigidbody2D>().AddForce(radToVec2 * Random.Range(300, 301));

            // Add torque to make it spin around
            int torqDir = radToVec2.x > 0 ? -1 : 1;
            tempSpawnObjects[i].GetComponent<Rigidbody2D>().AddTorque(Random.Range(5, 15) * torqDir, ForceMode2D.Force);
        }
    }

    protected IEnumerator StunnedFor(CloseCombatAnimation attack)
    {
        idleing = false;

        isAnimationStarted = true;                                      // prevents direction to become 0 and stop movement (for player)

        speed = 0f;                                                     // speed is now controlled by speed curve
        
        if(unit.target != null)
        {
            if (transform.position.x < unit.target.transform.position.x)  // if target is more on the right, unit direction is right
                direction = MoveDirection.left;
            else
                direction = MoveDirection.right;
        }

        if(changeStance)
        {
            changeStance = false;

            if (unit.currentStance == StanceList.Stand_A)
                unit.currentStance = StanceList.Stand_B;
            else if (unit.currentStance == StanceList.Stand_B)
                unit.currentStance = StanceList.Stand_A;
        }

        //List<CloseCombatAnimation> stunActionList = null;
        SpeedDependantAnimation stunAnimation = null;
        switch (attack.attackType)
        {
            case AttackType.Casual:
                stunAnimation = unit.activeAnimations.Hurt as SpeedDependantAnimation;
                transform.position = new Vector2(transform.position.x + attack.PushDistance * (int)direction, transform.position.y);
                break;
            case AttackType.Kick:
                stunAnimation = unit.activeAnimations.Kicked as SpeedDependantAnimation;
                break;
            case AttackType.Shield:
                stunAnimation = unit.activeAnimations.Slammed as SpeedDependantAnimation;
                break;
            default:
                break;
        }
        // TODO : I set mix time every time here, it could be set in Start for once too
        SetMixBetweenAnimation(spineSkeletonAnimation.state.GetCurrent(1).Animation.Name, stunAnimation.SpineAnimationReference.Animation.Name, 0f);

        spineSkeletonAnimation.state.SetAnimation(1, stunAnimation.SpineAnimationReference, false).TimeScale = 1f;
        //StartCoroutine(WaitForEndOfAnimation(stunAnimation.SpineAnimationReference.Animation.Duration));

        float animationLength = stunAnimation.SpineAnimationReference.Animation.Duration;
        float animationCurrentTime = 0;
        while (animationLength > animationCurrentTime)
        {
            animationCurrentTime += Time.deltaTime;
            speedRelativeToAnimation = stunAnimation.speedCurve.Evaluate(animationCurrentTime);
            yield return null;
        }

        spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true).TimeScale = 1f;

        idleing = true;

        isAnimationStarted = false;                                     // direction released (for player)

        speed = defaultSpeed;                                                 // speed is now set to default speed level

        speedRelativeToAnimation = 0;

        direction = MoveDirection.waiting;

        currentAttack = null;

        ReStartCoroutines();
    }

    protected virtual void ReStartCoroutines() { }

    protected virtual void StopRoutine()
    {
        StopAllCoroutines();
    }

    // Changes the speed during animation
    protected IEnumerator SpeedDuringAnimation(CloseCombatAnimation Attack)
    {
        idleing = false;

        speed = 0;
        
        if(Attack.Keys.Count > 0)
        {
            if(unit.target != null)
            {
                float time = Attack.speedCurve[Attack.Keys[Attack.Keys.Count - 1]].time - Attack.speedCurve[Attack.Keys[0]].time;
                float animSpeed = (Mathf.Abs(transform.position.x - unit.target.transform.position.x) - 2f) / time;
                //Debug.Log("Time = " + time + " / Speed = " + animSpeed + " / CurPos = " + transform.position.x + " / NextPos = " + transform.position.x + (time * animSpeed));

                //Debug.Log("Time Dif = " + time + " / move = " + time * 32);
                //Debug.Log("Current Distance = " + transform.position.x + " / next position = " +  (transform.position.x + (time * 32)));
                // calculate distance to target and find speed

                Keyframe[] keyframe = Attack.speedCurve.keys;

                for (int i = 0; i < Attack.Keys.Count; i++)
                {
                    keyframe[Attack.Keys[i]].value = animSpeed;
                    //Debug.Log(Attack.speedCurve.keys[Attack.Keys[i]].value + " / " + Attack.Values[i]);
                }
                Attack.speedCurve.keys = keyframe;
            }
            else
            {
                Keyframe[] keyframe = Attack.speedCurve.keys;

                for (int i = 0; i < Attack.Keys.Count; i++)
                {
                    keyframe[Attack.Keys[i]].value = Attack.Values[i];
                    //Debug.Log(Attack.speedCurve.keys[Attack.Keys[i]].value + " / " + Attack.Values[i]);
                }
                Attack.speedCurve.keys = keyframe;
            }
        }
        
        if (Attack.speedCurve.Evaluate(0) == 0)
        {
            speed = defaultSpeed;

            direction = MoveDirection.waiting;

            yield return new WaitForSeconds(Attack.SpineAnimationReference.Animation.Duration);

            idleing = true;

            currentAttack = null;

            if (changeStance)
            {
                if (unit.currentStance == StanceList.Stand_A)
                    unit.currentStance = StanceList.Stand_B;
                else if (unit.currentStance == StanceList.Stand_B)
                    unit.currentStance = StanceList.Stand_A;

                changeStance = false;
            }

            spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true).TimeScale = 1f;

            yield break;
        }

        // Check for what ???
        if (unit.target != null)
        {
            if (transform.position.x < unit.target.transform.position.x)     // if target is more on the right, unit direction is right
                direction = MoveDirection.right;
            else
                direction = MoveDirection.left;
        }

        // lasts until animation ends
        float animationLength = Attack.SpineAnimationReference.Animation.Duration;
        float animationCurrentTime = 0;
        while (animationLength >= animationCurrentTime)
        {
            animationCurrentTime += Time.deltaTime;
            speedRelativeToAnimation = Attack.speedCurve.Evaluate(animationCurrentTime);
            yield return null;
        }
        speed = defaultSpeed;

        speedRelativeToAnimation = 0;

        direction = MoveDirection.waiting;

        idleing = true;

        currentAttack = null;

        if (changeStance)
        {
            if (unit.currentStance == StanceList.Stand_A)
                unit.currentStance = StanceList.Stand_B;
            else if (unit.currentStance == StanceList.Stand_B)
                unit.currentStance = StanceList.Stand_A;

            changeStance = false;
        }

        spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true).TimeScale = 1f;
    }
    protected IEnumerator SpeedDuringAnimation(SpeedDependantAnimation Animation)
    {
        idleing = false;

        speed = 0;

        if (Animation.speedCurve.Evaluate(0) == 0)
        {
            speed = defaultSpeed;

            direction = MoveDirection.waiting;

            yield return new WaitForSeconds(Animation.SpineAnimationReference.Animation.Duration);

            idleing = true;

            currentAttack = null;

            if (changeStance)
            {
                if (unit.currentStance == StanceList.Stand_A)
                    unit.currentStance = StanceList.Stand_B;
                else if (unit.currentStance == StanceList.Stand_B)
                    unit.currentStance = StanceList.Stand_A;

                changeStance = false;
            }

            spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true).TimeScale = 1f;

            yield break;
        }

        // Check for what ???
        if (unit.target != null)
        {
            if (transform.position.x < unit.target.transform.position.x)     // if target is more on the right, unit direction is right
                direction = MoveDirection.right;
            else
                direction = MoveDirection.left;
        }

        // lasts until animation ends
        float animationLength = Animation.SpineAnimationReference.Animation.Duration;
        float animationCurrentTime = 0;
        while (animationLength >= animationCurrentTime)
        {
            animationCurrentTime += Time.deltaTime;
            speedRelativeToAnimation = Animation.speedCurve.Evaluate(animationCurrentTime);
            yield return null;
        }
        speed = defaultSpeed;

        speedRelativeToAnimation = 0;

        direction = MoveDirection.waiting;

        idleing = true;

        currentAttack = null;

        if (changeStance)
        {
            if (unit.currentStance == StanceList.Stand_A)
                unit.currentStance = StanceList.Stand_B;
            else if (unit.currentStance == StanceList.Stand_B)
                unit.currentStance = StanceList.Stand_A;

            changeStance = false;
        }

        spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true).TimeScale = 1f;
    }

    protected IEnumerator PlayCinematicAnimation(SpeedDependantAnimation Animation, bool continueIdle = false)
    {
        TrackEntry track = spineSkeletonAnimation.state.SetAnimation(1, Animation.SpineAnimationReference, false);
        var completeOrEnd = WaitForSpineAnimation.AnimationEventTypes.Complete | WaitForSpineAnimation.AnimationEventTypes.End;

        idleing = false;

        speed = 0;

        if (Animation.speedCurve.Evaluate(0) == 0)
        {
            speed = defaultSpeed;

            direction = MoveDirection.waiting;

            yield return new WaitForSpineAnimation(track, completeOrEnd);
            
            idleing = true;

            currentAttack = null;

            if (changeStance)
            {
                if (unit.currentStance == StanceList.Stand_A)
                    unit.currentStance = StanceList.Stand_B;
                else if (unit.currentStance == StanceList.Stand_B)
                    unit.currentStance = StanceList.Stand_A;

                changeStance = false;
            }

            if (continueIdle) spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true).TimeScale = 1f;

            yield break;
        }

        // Check for what ???
        if (unit.target != null)
        {
            if (transform.position.x < unit.target.transform.position.x)     // if target is more on the right, unit direction is right
                direction = MoveDirection.right;
            else
                direction = MoveDirection.left;
        }
        
        // lasts until animation ends
        float animationCurrentTime = 0;
        while (track.IsComplete == false)
        {
            animationCurrentTime += Time.deltaTime;
            speedRelativeToAnimation = Animation.speedCurve.Evaluate(animationCurrentTime);
            yield return null;
        }

        speed = defaultSpeed;

        speedRelativeToAnimation = 0;

        direction = MoveDirection.waiting;

        idleing = true;

        currentAttack = null;

        isAnimationStarted = false;                                     // direction released (for player)

        if (changeStance)
        {
            if (unit.currentStance == StanceList.Stand_A)
                unit.currentStance = StanceList.Stand_B;
            else if (unit.currentStance == StanceList.Stand_B)
                unit.currentStance = StanceList.Stand_A;

            changeStance = false;
        }

        if (continueIdle)
        {
            spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true).TimeScale = 1f;

            GameManager.Instance.DisableControls = false;
        }
    }

    protected IEnumerator PlayCasualAnimation(BasicAnimation Animation)
    {
        TrackEntry track = spineSkeletonAnimation.state.SetAnimation(1, Animation.SpineAnimationReference, false);
        var completeOrEnd = WaitForSpineAnimation.AnimationEventTypes.Complete | WaitForSpineAnimation.AnimationEventTypes.End;

        idleing = false;

        isAnimationStarted = true;

        speed = 0;

        direction = MoveDirection.waiting;

        yield return new WaitForSpineAnimation(track, completeOrEnd);

        idleing = true;

        spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true).TimeScale = 1f;
    }

    public void SetMixBetweenAnimation(AnimationReferenceAsset from, AnimationReferenceAsset to, float mixDuration)
    {
        if (from == null || to == null)
            return;

        spineSkeletonAnimation.AnimationState.Data.SetMix(from.Animation.Name, to.Animation.Name, mixDuration);
    }
    public void SetMixBetweenAnimation(string from, string to, float mixDuration)
    {
        if (from == null || to == null)
            return;

        spineSkeletonAnimation.AnimationState.Data.SetMix(from, to, mixDuration);
    }
    protected virtual void HandleAnimationStateEvent(TrackEntry trackEntry, Spine.Event e)
    {
        switch (e.Data.Name)
        {
            case "MeleeAttack":
                DealDamage();
                break;
            case "Game Event/Weapon_Hit_Sound":
                if(currentAttack == null)
                {
                    CloseCombatAnimation tempAnim = unit.activeAnimations.Attack[0] as CloseCombatAnimation;
                    tempAnim.SoundObject.hitSoundEffect.PlayRandomSoundEffect();
                }
                else
                {
                    currentAttack.SoundObject.hitSoundEffect.PlayRandomSoundEffect();
                }
                break;
            case "Game Event/Weapon_Miss_Sound":
                if (currentAttack == null)
                {
                    CloseCombatAnimation tempAnim = unit.activeAnimations.Attack[0] as CloseCombatAnimation;
                    tempAnim.SoundObject.swooshSoundEffect.PlayRandomSoundEffect();
                }
                else
                {
                    currentAttack.SoundObject.swooshSoundEffect.PlayRandomSoundEffect();
                }
                break;

            default:
                break;
        }
    }

    void GamePaused()
    {

    }

    void GameContinue()
    {

    }

    protected virtual void OnDestroy()
    {
        GameManager.EnableAllControls -= GameContinue;
        GameManager.DisableAllControls -= GamePaused;
    }

    void TestDamage()
    {
        List<double> damage = new List<double>();
        Dictionary<int, List<double>> dictDmg = new Dictionary<int, List<double>>();
        dictDmg.Add(0, new List<double>());
        dictDmg.Add(1, new List<double>());
        dictDmg.Add(2, new List<double>());

        int dmg = 100;

        //for (int y = 0; y < 10; y++)
        //{
            //damage.Clear();
            for (int i = 0; i < 100; i++)
            {
                System.Random rand = new System.Random(System.Guid.NewGuid().GetHashCode());
                int chance = rand.Next(0, 100);

                double softDamage = dmg * 0.1;
                // low damage 15%
                if (chance <= 14)
                {
                    //System.Console.Write("Risky Damage\n");
                    softDamage += rand.NextDouble() * dmg * 0.9;

                    dictDmg[0].Add(softDamage);
                }
                // normal damage 50%
                else if (chance >= 15 && chance < 65)
                {
                    //System.Console.Write("Normal Damage\n");
                    softDamage += dmg * 0.4f;
                    softDamage += (rand.NextDouble() / 2) * dmg;
                    softDamage -= (rand.NextDouble() / 2) * dmg;

                    dictDmg[1].Add(softDamage);
                }
                // high damage 35%
                else
                {
                    //System.Console.Write("High Damage\n");
                    softDamage += dmg * 0.6;
                    softDamage += rand.NextDouble() * dmg * 0.3;

                    dictDmg[2].Add(softDamage);
                }

                damage.Add(softDamage);
            }

            damage.Sort();
            int biggerThanSeventy = 0;
            int smallerThanThirty = 0;
            foreach (double d in damage)
            {
                if (d >= 70)
                    biggerThanSeventy++;
                if (d <= 30)
                    smallerThanThirty++;
                //System.Console.Write("Damage = " + d + "\n");
            }
            System.Console.Write("70 >= " + biggerThanSeventy + "\n");
            System.Console.Write("30 to 70 = " + (100 - biggerThanSeventy - smallerThanThirty) + "\n");
            System.Console.Write("30 <= " + smallerThanThirty + "\n");

            System.Console.Write("\n\n");

            dictDmg[0].Sort();
            System.Console.Write("Risky Damage Amount = " + dictDmg[0].Count + "\n");
            foreach (double d in dictDmg[0])
            {
                System.Console.Write("Damage = " + d + "\n");
            }

            System.Console.Write("\n\n");

            dictDmg[1].Sort();
            System.Console.Write("Normal Damage Amount = " + dictDmg[1].Count + "\n");
            foreach (double d in dictDmg[1])
            {
                System.Console.Write("Damage = " + d + "\n");
            }

            System.Console.Write("\n\n");

            dictDmg[2].Sort();
            System.Console.Write("High Damage Amount = " + dictDmg[2].Count + "\n");
            foreach (double d in dictDmg[2])
            {
                System.Console.Write("Damage = " + d + "\n");
            }
            
        //}
    }
    
}
