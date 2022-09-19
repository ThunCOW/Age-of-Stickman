using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using static UnityEngine.UI.CanvasScaler;

namespace StickmanChampion
{
    public class Unit_Old : MonoBehaviour
    {
        protected enum MoveDirection
        {
            left = -1,
            right = 1,
            waiting = 0
        }
        
        [Header("Character Stats")]
        [SerializeField] protected int MaxHealth;
        [SerializeField] protected int Health;
        [SerializeField] private GameObject bloodObject;

        private StanceList tempState;
        private StanceList _currentStance;
        [SerializeField] protected StanceList currentStance 
        { 
            get { return _currentStance; }
            set 
            { 
                _currentStance = value; 
                attackList = stance[value];
                
                deathActionList = deathActionDict[value];
                PopulateDeathAction(deathActionList);
            } 
        }
        [Header("Animation Lists and Properties")]
        [SerializeField] protected List<UnitStance> stanceList;

        // This Field is populized auto
        protected List<Action> attackList;
        private Dictionary<StanceList, List<Action>> stance = new Dictionary<StanceList, List<Action>>();

        private List<DeathAction> deathActionList;
        private DeathActions deathActions;
        private Dictionary<StanceList, List<DeathAction>> deathActionDict = new Dictionary<StanceList, List<DeathAction>>();
        public class DeathActions
        {
            public List<DeathAction> highRegion;
            public List<DeathAction> midRegion;
            public List<DeathAction> lowRegion;

            public DeathActions()
            {
                highRegion = new List<DeathAction>();
                midRegion = new List<DeathAction>();
                lowRegion = new List<DeathAction>();
            }
        }
        public void PopulateDeathAction(List<DeathAction> deathActionList)
        {
            deathActions = new DeathActions();
            foreach(DeathAction deathAction in deathActionList)
            {
                switch (deathAction.deathType)
                {
                    case HitRegion.High:
                        deathActions.highRegion.Add(deathAction);
                        break;
                    case HitRegion.Mid:
                        deathActions.midRegion.Add(deathAction);
                        break;
                    case HitRegion.Low:
                        deathActions.lowRegion.Add(deathAction);
                        break;
                    case HitRegion.SpearThrowHead:
                        break;
                    case HitRegion.Arrow:
                        break;
                    default:
                        break;
                }
            }
        }
        // End

        // Variations of how it can get stunned
        [SerializeField] protected List<StunVariations> stunVariations;
        protected Dictionary<AttackType, List<BaseAction>> stunType = new Dictionary<AttackType, List<BaseAction>>();

        [Header("Character Animation")]
        public Animator unitAnimator = null;

        [Header("Character Movement")]
        protected bool canMove = true;
        [HideInInspector] public bool isAnimationStarted = false;   // Animations require direction to be consistent

        /// <summary>
        /// if in idle - animation ended / movement ended / attack ended - check for character direction relative to target
        /// </summary>
        protected bool _idleing;
        protected bool idleing
        {
            get { return _idleing; }
            set
            {
                _idleing = value;
                /*if(value == true)
                {
                    StopCoroutine(CheckUnitDirectionCycle());
                    StartCoroutine(CheckUnitDirectionCycle());
                }
                else if(value == false)
                {
                    StopCoroutine(CheckUnitDirectionCycle());
                }*/
            }
        }

        protected bool movingForward;

        public float speed; // default moving speed assigned in inspector
        protected float speed_; // stores default speed
        protected float speedRelativeToAnimation; // speed for animations
        protected MoveDirection direction = MoveDirection.waiting;
        [HideInInspector] protected float multiplier = 1;

        [Header("Target Information")]
        [SerializeField] protected Unit_Old _target;
        protected Unit_Old target
        {
            get { return _target; }
            set
            {
                _target = value;

                /*StopCoroutine(TargetInScreen());
                if ( value != null )
                    StartCoroutine(TargetInScreen());*/
            }
        }
        // Start is called before the first frame update
        protected virtual void Start()
        {
            speed_ = speed;

            if (gameObject.CompareTag(GameManager.Instance.ENEMY_TAG))
                GameManager.Instance.EnemyUnits.Add(this);
            else
                GameManager.Instance.PlayerUnits.Add(this);

            GameManager.Instance.sortManager.AddToOrder(this);

            foreach (UnitStance Stance in stanceList)
            {
                stance.Add(Stance.Stance, Stance.actionList);
                deathActionDict.Add(Stance.Stance, Stance.deathActionList);
            }
            attackList = stance[currentStance];
            deathActionList = deathActionDict[currentStance];
            PopulateDeathAction(deathActionList);

            foreach (StunVariations stun in stunVariations)
            {
                stunType.Add(stun.attackType, stun.actionList);
            }

            StartCoroutine(InitializeClosestUnitSearch());
            //StartCoroutine(GetClosestUnitSearchCycle());
            //StartCoroutine(CheckUnitDirectionCycle());
        }

        // Update is called once per frame
        private void Update()
        {
            if (tempState != currentStance)
            {
                tempState = currentStance;
                attackList = stance[currentStance];
            }

            if (Health > 0) // Only if alive
            {
                if (idleing == true && target != null) CheckUnitDirection();        // Turns towards target while in idle only
                
                CharacterControls();
            }
        }

        private void FixedUpdate()
        {
            if (canMove)
                transform.position = new Vector3(transform.position.x + ((int)direction * (speed + speedRelativeToAnimation) * multiplier) * Time.deltaTime, transform.position.y, transform.position.z);
        }

        /// <summary>
        /// Runs in Update
        /// </summary>
        protected virtual void CharacterControls() {}

        public void TakeDamage(Action attack, int attackDirection = 0)
        {
            Health -= attack.Damage;
            if(Health <= 0)
            {
                CheckUnitDirection();
                StopAllCoroutines();

                canMove = false;

                int randomDeath = 0;
                switch (attack.attackRegion)
                {
                    case HitRegion.High:
                        randomDeath = Random.Range(0, deathActions.highRegion.Count);
                        unitAnimator.Play(deathActions.highRegion[randomDeath].AnimationClip.name, 0);
                        break;
                    case HitRegion.Mid:
                        randomDeath = Random.Range(0, deathActions.midRegion.Count);
                        unitAnimator.Play(deathActions.midRegion[randomDeath].AnimationClip.name, 0);
                        break;
                    case HitRegion.Low:
                        randomDeath = Random.Range(0, deathActions.lowRegion.Count);
                        unitAnimator.Play(deathActions.lowRegion[randomDeath].AnimationClip.name, 0);
                        break;
                    default:
                        break;
                }
                if (deathActions.highRegion[randomDeath].CutPart != null)
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
                }

                if (gameObject.CompareTag(GameManager.Instance.ENEMY_TAG))
                    GameManager.Instance.EnemyUnits.Remove(this);
                else
                    GameManager.Instance.PlayerUnits.Remove(this);

                GameManager.Instance.sortManager.RemoveFromOrder(this);
            }
            else
            {
                CheckUnitDirection();

                StopAllCoroutines();
                StartCoroutine(StunnedFor(0.5f, attack));
            }
        }

        // DealDamage called when attack decisiion happen, and meleeHitTrigger turns true via animation call
        [HideInInspector] public bool meleeHitTrigger = false;
        protected Action currentAttack = null;
        public IEnumerator DealDamage()
        {
            yield return new WaitUntil(() => meleeHitTrigger == true);
            
            meleeHitTrigger = false;

            // scenario 1: there were multiple target in front of unit, one of them died, now need to change target
            // scenario 2: the target in front died, and there is no target in front or any at all
            
            // If target is dead
            if (target == null)
                FindClosestUnit();

            // scenario 2
            if (target == null)
            {
                currentAttack.swooshSoundEffect.PlayRandomSoundEffect();

                yield break;
            }

            GameManager.Instance.sortManager.BringToFront(this);
            GameManager.Instance.sortManager.ChangePlayerSortOnly(this, target);

            int dir;
            
            // i.e current unit is on the right, target is on the left, target will be pushed to left
            if (transform.position.x > target.transform.position.x)
                dir = (int)MoveDirection.left;
            else
                dir = (int)MoveDirection.right;

            // i.e if target is being pushed to right, current unit must be looking right to land the hit, if its not looking right, misses it
            if (dir == (int)MoveDirection.right && transform.localScale.x < 0.1)
            {
                currentAttack.swooshSoundEffect.PlayRandomSoundEffect();

                yield break;
            }
            else if (dir == (int)MoveDirection.left && transform.localScale.x > 0.1)
            {
                currentAttack.swooshSoundEffect.PlayRandomSoundEffect();

                yield break;
            }

            // TODO: needs fixing later
            // If target is in damage distance, succesfully landed the hit.
            //Debug.Log("closestPos = " + (target.GetComponent<BoxCollider2D>().ClosestPoint(transform.position).x - transform.position.x));
            if (Mathf.Abs(target.GetComponent<BoxCollider2D>().ClosestPoint(transform.position).x - transform.position.x) < currentAttack.Reach)
            {
                currentAttack.hitSoundEffect.PlayRandomSoundEffect();

                target.TakeDamage(currentAttack, dir);

                if(currentAttack.attackType != AttackType.Kick && currentAttack.attackType != AttackType.Shield)
                {
                    GameObject blood_go = Instantiate(bloodObject);
                    blood_go.transform.position = new Vector3(target.transform.position.x, currentAttack.hitHeightPosiiton, bloodObject.transform.position.z);
                }
            }
            else
            {
                currentAttack.swooshSoundEffect.PlayRandomSoundEffect();
            }
        }

        protected virtual IEnumerator StunnedFor(float stunDuration, Action attack)
        {
            yield return new WaitForSeconds(stunDuration);
        }

        protected virtual void ReStartCoroutines() { }

        // Changes the speed during animation
        protected IEnumerator SpeedDuringAnimation(Action Attack)
        {
            speed = 0;

            // Animation works in normal speed
            if (Attack.speedCurve.Evaluate(0) == 0)
            {
                speed = speed_;

                yield return new WaitForSeconds(Attack.AnimationClip.length);

                idleing = true;

                if (meleeHitTrigger == true)
                {
                    meleeHitTrigger = false;
                    currentAttack = null;
                }

                yield break;
            }

            // Check for what ???
            if (target != null)
            {
                if (transform.position.x < target.transform.position.x)     // if target is more on the right, unit direction is right
                    direction = MoveDirection.right;
                else
                    direction = MoveDirection.left;
            }

            // lasts until animation ends
            float animationLength = Attack.AnimationClip.length;
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

            if (meleeHitTrigger == true)
            {
                meleeHitTrigger = false;
                currentAttack = null;
            }
        }

        // Triggered when there is a projectile, waits until animation to turn releaseProjectile true.
        [HideInInspector] public bool releaseProjectile = false;
        public IEnumerator UseRangedWeapon(Action rangedAttack)
        {
            yield return new WaitUntil(() => releaseProjectile == true);

            currentAttack.swooshSoundEffect.PlayRandomSoundEffect();

            releaseProjectile = false;
            GameObject projectile_go = Instantiate(rangedAttack.rangedSpawnPrefab, gameObject.transform);
            projectile_go.transform.localPosition = rangedAttack.rangedSpawnPrefab.transform.position;
            projectile_go.transform.parent = null;

            Projectile projectile = projectile_go.GetComponent<Projectile>();

            projectile.RangedAttack = rangedAttack;
            if (gameObject.transform.localScale.x == 1)
            {
                projectile.projectileDir = 1;
                projectile.gameObject.transform.localScale = new Vector3(projectile.transform.localScale.x, projectile.transform.localScale.y, 1);
            }
            else
            {
                projectile.projectileDir = -1;
                projectile.gameObject.transform.localScale = new Vector3(-projectile.transform.localScale.x, projectile.transform.localScale.y, 1);
            }

            if (gameObject.CompareTag(GameManager.Instance.ENEMY_TAG))
                projectile.targetTag = GameManager.Instance.PLAYER_TAG;
            else
                projectile.targetTag = GameManager.Instance.ENEMY_TAG;
        }

        // Called at Start, this helps to fix direction of spawned object
        private IEnumerator InitializeClosestUnitSearch(float waitTime = 0)
        {
            yield return new WaitForSeconds(waitTime);

            FindClosestUnit();
            
            if (target == null)
            {
                StartCoroutine(InitializeClosestUnitSearch(Random.Range(0.1f, 0.25f)));
            }
            else
            {
                CheckUnitDirection();
                StartCoroutine(GetClosestUnitSearchCycle());
            }
        }
        // repeats itself until unit dies, searches for closest target
        protected IEnumerator GetClosestUnitSearchCycle(float waitTime = 0)
        {
            yield return new WaitForSeconds(waitTime);

            FindClosestUnit();

            if (Health > 0)
                StartCoroutine(GetClosestUnitSearchCycle(Random.Range(0.1f, 0.25f)));
        }

        protected virtual void FindClosestUnit()
        {
            // ie. If current unit is enemy, search for player units
            List<Unit_Old> unitList;
            if (gameObject.CompareTag(GameManager.Instance.ENEMY_TAG))
                unitList = GameManager.Instance.PlayerUnits;
            else
                unitList = GameManager.Instance.EnemyUnits;

            target = null;

            Unit_Old lastUnit = target;

            float closestX = 5000;
            foreach (Unit_Old unit in unitList)
            {
                float dist = Mathf.Abs(transform.position.x - unit.transform.position.x);
                if (this is AIUnit)
                {
                    if (closestX > dist)
                    {
                        target = unit;
                        closestX = Mathf.Abs(transform.position.x - unit.transform.position.x);
                    }
                }
                else
                {
                    float maxVision = 8.65f;    // maxVision is for player, player won't detect enemies outside of cam
                    if (dist < maxVision)
                    {
                        if (closestX > dist)
                        {
                            target = unit;
                            closestX = Mathf.Abs(transform.position.x - unit.transform.position.x);
                        }
                    }
                }
            }

            /*if(target != null)
            {
                if(idleing == true)
                {
                    StopCoroutine(TargetInScreen());
                    StartCoroutine(TargetInScreen());
                }
            }*/

            // target changed, look direction 
            if (lastUnit != target)
            {

            }
        }

        /*private IEnumerator CheckUnitDirectionCycle()
        {
            yield return new WaitForSeconds(Random.Range(0, 0.15f));

            StopCoroutine(TargetInScreen());
            StartCoroutine(TargetInScreen());

            StartCoroutine(CheckUnitDirectionCycle());
        }

        protected IEnumerator TargetInScreen()
        {
            float dist = Mathf.Abs(this.transform.position.x - target.transform.position.x);
            Debug.Log(dist);
            while (dist >= 910.5f)
            {
                yield return null;
            }

            if(target != null)
            {
                if(idleing == true) CheckUnitDirection();
            }
        }*/

        protected void CheckUnitDirection()
        {
            //Debug.Log("enters CheckUnitDirection");
            // i.e if target is more on the right but unit is looking left, turn it right
            int lookDir = transform.position.x > target.transform.position.x ? -1 : 1;

            transform.localScale = new Vector3(lookDir, transform.localScale.y, transform.localScale.z);
        }
    }

    [System.Serializable]
    public class Action
    {
        public AttackType attackType;
        public AnimationMovementType animationMovementType;
        public int Damage;
        public float Reach;
        public float PushDistance;
        public AnimationClip AnimationClip;
        [SerializeField] public AnimationCurve speedCurve;
        public GameObject rangedSpawnPrefab = null;
        public HitRegion attackRegion;

        public float hitHeightPosiiton;
        public SoundEffect swooshSoundEffect;
        public SoundEffect hitSoundEffect;
    }

    [System.Serializable]
    public class BaseAction
    {
        public AnimationClip AnimationClip;
        public AnimationCurve speedCurve;
    }

    [System.Serializable]
    public class DeathAction : BaseAction
    {
        public HitRegion deathType;
        public GameObject CutPart;
    }

    [System.Serializable]
    public class StunVariations
    {
        public AttackType attackType;
        public List<BaseAction> actionList = new List<BaseAction>();
    }

    [System.Serializable]
    public class UnitStance
    {
        public StanceList Stance;
        public List<Action> actionList = new List<Action>();
        public List<DeathAction> deathActionList = new List<DeathAction>();
    }

    public enum StanceList
    {
        Stand_A,
        Stand_A_transition_B,
        Stand_B,
        Stand_B_transition_A,
        Walking,
        Special
    }

    public enum AttackType
    {
        Normal,
        Kick,
        Shield
    }

    public enum HitRegion
    {
        High,
        Mid,
        Low,
        SpearThrowHead,
        Arrow
    }

    public enum AnimationMovementType
    {
        Stationary,
        NonStationary
    }
}
