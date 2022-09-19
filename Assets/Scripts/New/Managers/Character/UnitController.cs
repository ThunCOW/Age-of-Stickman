using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Spine.Unity;
using Spine;
using SpineControllerVersion;

public class UnitController : MonoBehaviour
{
    protected enum MoveDirection
    {
        left = -1,
        right = 1,
        waiting = 0
    }

    public SkeletonAnimation spineSkeletonAnimation;

    protected Unit unit;

    protected bool canMove = true;
    [HideInInspector] public bool isAnimationStarted = false;   // Animations require direction to be consistent

    protected bool idleing;

    public float speed; // default moving speed assigned in inspector
    protected float speed_; // stores default speed
    protected float speedRelativeToAnimation; // speed for animations
    protected MoveDirection direction = MoveDirection.waiting;
    [HideInInspector] protected float multiplier = 1;

    // Start is called before the first frame update
    protected virtual void Start()
    {
        unit = GetComponent<Unit>();

        spineSkeletonAnimation.state.Event += HandleAnimationStateEvent;

        speed_ = speed;
    }

    // Update is called once per frame
    void Update()
    {
        if (unit.Health > 0) // Only if alive
        {
            if (idleing == true && unit.target != null) unit.CheckUnitDirection();        // Turns towards target while in idle only

            CharacterControls();
        }
    }

    void FixedUpdate()
    {
        if (canMove)
            transform.position = new Vector3(transform.position.x + ((int)direction * (speed + speedRelativeToAnimation) * multiplier) * Time.deltaTime, transform.position.y, transform.position.z);
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
            currentAttack.swooshSoundEffect.PlayRandomSoundEffect();

            return;
        }

        // TODO sortingManager 
        //GameManager.Instance.sortManager.BringToFront(this);
        //GameManager.Instance.sortManager.ChangePlayerSortOnly(this, target);

        int dir;

        // i.e current unit is on the right, target is on the left, target will be pushed to left
        if (transform.position.x > unit.target.transform.position.x)
            dir = (int)MoveDirection.left;
        else
            dir = (int)MoveDirection.right;

        // i.e if target is being pushed to right, current unit must be looking right to land the hit, if its not looking right, misses it
        if (dir == (int)MoveDirection.right && transform.localScale.x < 0.1)
        {
            currentAttack.swooshSoundEffect.PlayRandomSoundEffect();

            return;
        }
        else if (dir == (int)MoveDirection.left && transform.localScale.x > 0.1)
        {
            currentAttack.swooshSoundEffect.PlayRandomSoundEffect();

            return;
        }

        // TODO: needs fixing later
        // If target is in damage distance, succesfully landed the hit.
        //Debug.Log("closestPos = " + (target.GetComponent<BoxCollider2D>().ClosestPoint(transform.position).x - transform.position.x));
        if (Mathf.Abs(unit.target.GetComponent<BoxCollider2D>().ClosestPoint(transform.position).x - transform.position.x) < currentAttack.Reach)
        {
            currentAttack.hitSoundEffect.PlayRandomSoundEffect();

            unit.target.unitController.TakeDamage(currentAttack, dir);

            // TODO blood objectc
            /*if (currentAttack.attackType != AttackType.Kick && currentAttack.attackType != AttackType.Shield)
            {
                GameObject blood_go = Instantiate(unit.target.bloodObject);
                blood_go.transform.position = new Vector3(unit.target.transform.position.x, currentAttack.hitHeightPosiiton, unit.target.bloodObject.transform.position.z);
            }*/
        }
        else
        {
            currentAttack.swooshSoundEffect.PlayRandomSoundEffect();
        }
    }

    public void TakeDamage(CloseCombatAnimation attack, int attackDirection = 0)
    {
        unit.Health -= attack.Damage;
        if (unit.Health <= 0)
        {
            unit.CheckUnitDirection();
            StopAllCoroutines();

            canMove = false;

            int randomDeath = 0;
            List<DeathAnimation> deathAnimation;
            switch (attack.attackRegion)
            {
                case HitRegion.High:
                    deathAnimation = unit.activeAnimations.DeathAnimationByDamageRegion.highRegion;
                    randomDeath = Random.Range(0, deathAnimation.Count);
                    spineSkeletonAnimation.state.SetAnimation(1, deathAnimation[randomDeath].SpineAnimationReference, false).TimeScale = 1f;
                    break;
                case HitRegion.Mid:
                    deathAnimation = unit.activeAnimations.DeathAnimationByDamageRegion.midRegion;
                    randomDeath = Random.Range(0, deathAnimation.Count);
                    spineSkeletonAnimation.state.SetAnimation(1, deathAnimation[randomDeath].SpineAnimationReference, false).TimeScale = 1f;
                    break;
                case HitRegion.Low:
                    deathAnimation = unit.activeAnimations.DeathAnimationByDamageRegion.lowRegion;
                    randomDeath = Random.Range(0, deathAnimation.Count);
                    spineSkeletonAnimation.state.SetAnimation(1, deathAnimation[randomDeath].SpineAnimationReference, false).TimeScale = 1f;
                    break;
                default:
                    break;
            }
            // TODO cutting parts of body animations
            /*if (deathActions.highRegion[randomDeath].CutPart != null)
            {
                // Spawn Body Part and set initial position and scales
                Vector3 cutSpawnPos = deathActions.highRegion[randomDeath].CutPart.transform.position;
                GameObject cut_part = Instantiate(deathActions.highRegion[randomDeath].CutPart, gameObject.transform);
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
            }*/

            if (gameObject.CompareTag(GameManager.Instance.ENEMY_TAG))
                GameManager.Instance.EnemyUnits.Remove(unit);
            else
                GameManager.Instance.PlayerUnits.Remove(unit);

            GameManager.Instance.sortManager.RemoveFromOrder(unit);
        }
        else
        {
            unit.CheckUnitDirection();

            StopAllCoroutines();
            StartCoroutine(StunnedFor(0.5f, attack));
        }
    }

    protected IEnumerator StunnedFor(float stunDuration, CloseCombatAnimation attack)
    {
        idleing = false;

        isAnimationStarted = true;                                      // prevents direction to become 0 and stop movement (for player)

        speed = 0f;                                                     // speed is now controlled by speed curve

        if (transform.position.x < unit.target.transform.position.x)  // if target is more on the right, unit direction is right
            direction = MoveDirection.left;
        else
            direction = MoveDirection.right;

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

        speed = speed_;                                                 // speed is now set to default speed level

        speedRelativeToAnimation = 0;

        direction = MoveDirection.waiting;

        currentAttack = null;

        ReStartCoroutines();
    }

    protected virtual void ReStartCoroutines() { }

    // Changes the speed during animation
    protected IEnumerator SpeedDuringAnimation(CloseCombatAnimation Attack)
    {
        idleing = false;

        speed = 0;

        // Animation works in normal speed
        if (Attack.speedCurve.Evaluate(0) == 0)
        {
            speed = speed_;

            yield return new WaitForSeconds(Attack.SpineAnimationReference.Animation.Duration);

            idleing = true;

            currentAttack = null;

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
        speed = speed_;

        speedRelativeToAnimation = 0;

        direction = MoveDirection.waiting;

        idleing = true;

        currentAttack = null;

        spineSkeletonAnimation.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true).TimeScale = 1f;
    }

    private void HandleAnimationStateEvent(TrackEntry trackEntry, Spine.Event e)
    {
        if (e.Data.Name == "MeleeAttack")
        {
            DealDamage();
        }
    }
}
