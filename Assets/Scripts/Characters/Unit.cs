using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace StickmanChampion
{
    public class Unit : MonoBehaviour
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
        protected bool isMoving;
        protected bool canMove = true;
        [HideInInspector] public bool isAnimationStarted = false;   // Animations require direction to be consistent

        /// <summary>
        /// if in idle - animation ended / movement ended / attack ended - check for character direction relative to target
        /// </summary>
        protected bool idleing = false;

        protected bool movingForward;

        public float speed; // default moving speed assigned in inspector
        protected float speed_; // stores default speed
        protected float speedRelativeToAnimation; // speed for animations
        protected MoveDirection direction = MoveDirection.waiting;
        [HideInInspector] protected float multiplier = 1;

        [Header("Target Information")]
        [SerializeField] protected Unit target = null;

        protected GameManager gameManager = null;
        // Start is called before the first frame update
        protected virtual void Start()
        {
            gameManager = GameManager.Instance;

            speed_ = speed;

            if (gameObject.CompareTag(gameManager.ENEMY_TAG))
                gameManager.EnemyUnits.Add(this);
            else
                gameManager.PlayerUnits.Add(this);

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

            StartCoroutine(GetClosestUnitCycle());
            StartCoroutine(FixDirection());
        }

        // Update is called once per frame
        private void Update()
        {
            if(tempState != currentStance)
            {
                tempState = currentStance;
                attackList = stance[currentStance];
            }

            if (Health > 0) // Only if alive
            {
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

                canMove = false;
                StopAllCoroutines();
                // death
                //Health = 100;

                //Destroy(gameObject);
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

                if (gameObject.CompareTag(gameManager.ENEMY_TAG))
                    gameManager.EnemyUnits.Remove(this);
                else
                    gameManager.PlayerUnits.Remove(this);
            }
            else
            {
                //transform.position = new Vector2(transform.position.x + attack.PushDistance * attackDirection, transform.position.y);

                CheckUnitDirection();

                StopAllCoroutines();
                StartCoroutine(StunnedFor(0.5f, attack));
            }
        }

        // DealDamage called when attack decisiion happen, and meleeHitTrigger turns true via animation call
        [HideInInspector] public bool meleeHitTrigger = false;
        protected Action currentAttack = null;
        protected IEnumerator DealDamage()
        {
            yield return new WaitUntil(() => meleeHitTrigger == true);
            
            meleeHitTrigger = false;

            // If target is dead
            // scenario 1: there were multiple target in front of unit, one of them died, now need to change target
            // scenario 2: the target in front died, now there is no target in front or any at all
            if (target == null)
                FindClosestUnit();

            // scenario 2
            if (target == null)
                yield break;

            int dir;
            
            // i.e current unit is on the right, target is on the left, target will be pushed to left
            if (transform.position.x > target.transform.position.x)
                dir = (int)MoveDirection.left;
            else
                dir = (int)MoveDirection.right;

            // i.e if target is being pushed to right, current unit must be looking right to land the hit, if its not looking right, misses it
            if (dir == (int)MoveDirection.right && transform.localScale.x < 0.1)
                yield break;
            else if (dir == (int)MoveDirection.left && transform.localScale.x > 0.1)
                yield break;

            // TODO: needs fixing later
            //Debug.Log("closestPos = " + (target.GetComponent<BoxCollider2D>().ClosestPoint(transform.position).x - transform.position.x));
            if(Mathf.Abs(target.GetComponent<BoxCollider2D>().ClosestPoint(transform.position).x - transform.position.x) < currentAttack.Reach)
                target.TakeDamage(currentAttack, dir);
        }

        protected virtual IEnumerator StunnedFor(float stunDuration, Action attack)
        {
            direction = MoveDirection.waiting;
            // play hurt animation

            yield return new WaitForSeconds(stunDuration);
        }

        // Changes the speed during animation
        protected IEnumerator SpeedDuringAnimation(Action Attack)
        {
            StartCoroutine(IdleAfterAnimation(Attack));

            if (Attack.speedCurve.Evaluate(0) == 0)
            {
                yield break;
            }

            if (target != null)
            {
                if (transform.position.x < target.transform.position.x)     // if target is more on the right, unit direction is right
                    direction = MoveDirection.right;
                else
                    direction = MoveDirection.left;
            }

            float animationLength = Attack.AnimationClip.length;
            float animationCurrentTime = 0;
            while (animationLength > animationCurrentTime)
            {
                animationCurrentTime += Time.deltaTime;
                speedRelativeToAnimation = Attack.speedCurve.Evaluate(animationCurrentTime);
                yield return null;
            }
            speedRelativeToAnimation = 0;
            direction = MoveDirection.waiting;
        }

        // idleing turns true after animation ends
        protected IEnumerator IdleAfterAnimation(Action Action)
        {
            yield return new WaitForSeconds(Action.AnimationClip.length);
            idleing = true;

            if (meleeHitTrigger == true)
            {
                meleeHitTrigger = false;
                currentAttack = null; 
            }
        }

        // repeats itself until it dies, searches for closest target
        protected IEnumerator GetClosestUnitCycle(float waitTime = 0)
        {
            yield return new WaitForSeconds(waitTime);

            FindClosestUnit();

            if (Health > 0)
                StartCoroutine(GetClosestUnitCycle(Random.Range(0.1f, 0.25f)));
        }

        protected void FindClosestUnit()
        {
            // ie. If current unit is enemy, search for player units
            List<Unit> unitList;
            if (gameObject.CompareTag(gameManager.ENEMY_TAG))
                unitList = gameManager.PlayerUnits;
            else
                unitList = gameManager.EnemyUnits;

            if (unitList.Count == 0)
                target = null;

            float closestX = 5000;
            foreach (Unit unit in unitList)
            {
                if (closestX > Mathf.Abs(transform.position.x - unit.transform.position.x))
                {
                    target = unit;
                    closestX = Mathf.Abs(transform.position.x - unit.transform.position.x);
                }
            }
        }

        // Sometimes target is not found at start, repeats itself until it finds a target and fixes direction then kills the process.
        protected IEnumerator FixDirection()
        {
            while(target == null)
            {
                yield return null;
            }

            if (target != null)
            {
                CheckUnitDirection();
            }
        }

        protected void CheckUnitDirection()
        {
            // i.e if target is more on the right but unit is looking left, turn it right
            if (transform.position.x < target.transform.position.x && transform.localScale.x < 0)
                transform.localScale = new Vector3(Mathf.Abs(transform.localScale.x), transform.localScale.y, transform.localScale.z);
            else if (transform.position.x > target.transform.position.x && transform.localScale.x > 0)
                transform.localScale = new Vector3(-transform.localScale.x, transform.localScale.y, transform.localScale.z);
        }

        // Triggered when there is a projectile, waits until animation to turn releaseProjectile true.
        [HideInInspector] public bool releaseProjectile = false;
        public IEnumerator UseRangedWeapon(Action rangedAttack)
        {
            yield return new WaitUntil(() => releaseProjectile == true);

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

            if (gameObject.CompareTag(gameManager.ENEMY_TAG))
                projectile.targetTag = gameManager.PLAYER_TAG;
            else
                projectile.targetTag= gameManager.ENEMY_TAG;
        }

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

    [System.Serializable]
    public class UnitStance
    {
        public StanceList Stance;
        public List<Action> actionList = new List<Action>();
        public List<DeathAction> deathActionList = new List<DeathAction>();
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
    }

    [System.Serializable]
    public class DeathAction : BaseAction
    {
        public HitRegion deathType;
    }

    [System.Serializable]
    public class StunVariations
    {
        public AttackType attackType;
        public List<BaseAction> actionList = new List<BaseAction>();
    }
    [System.Serializable]
    public class BaseAction
    {
        public AnimationClip AnimationClip;
        public AnimationCurve speedCurve;
    }
    /*[System.Serializable]
    public class TestStance
    {
        [SerializeReference]
        public ActionTest test = new RangedAttackAction();
    }

    [System.Serializable]
    public class ActionTest
    {
        public string Test;
    }
    [System.Serializable]
    public class MeleeAttackAction : ActionTest
    {
        public int Damage;
        public float Reach;
        public float PushDistance;
    }
    [System.Serializable]
    public class RangedAttackAction : MeleeAttackAction
    {
        public GameObject rangedSpawnObject = null;
    }*/

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
