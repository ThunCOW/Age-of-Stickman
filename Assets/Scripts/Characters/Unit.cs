using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace StickmanChampion
{
    public class Unit : MonoBehaviour
    {
        [Header("Character Stats")]
        [SerializeField] protected int MaxHealth;
        [SerializeField] protected int Health;
        [SerializeField] protected int Damage;
        [SerializeField] protected float PushDistance;

        private StanceList tempState;
        private StanceList _currentStance;
        [SerializeField] protected StanceList currentStance 
        { 
            get { return _currentStance; }
            set 
            { 
                _currentStance = value; 
                attackList = stance[value];
            } 
        }
        [SerializeField] protected List<UnitStance> stanceList;
        [SerializeField] protected List<OffensiveSkills> attackList;
        private Dictionary<StanceList, List<OffensiveSkills>> stance = new Dictionary<StanceList, List<OffensiveSkills>>();

        [Header("Character Animation")]
        public Animator charAnimator = null;

        [Header("Character Movement")]
        protected bool isMoving;
        protected bool canMove = true;
        [HideInInspector] public bool isAnimationDirectionLocked = false;   // Animations require direction to be consistent
        
        protected bool movingForward;

        public float speed;
        protected Directions direction = Directions.waiting;
        [HideInInspector] protected float multiplier = 1;

        [Header("Target Information")]
        [SerializeField] protected Unit target = null;

        protected GameManager gameManager = null;
        // Start is called before the first frame update
        protected virtual void Start()
        {
            gameManager = GameManager.Instance;

            foreach(UnitStance Stance in stanceList)
            {
                stance.Add(Stance.Stance, Stance.attackList);
            }
            attackList = stance[currentStance];

            StartCoroutine(GetClosestUnit());
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

        protected virtual void CharacterControls() {}

        protected enum Directions
        {
            left = -1, 
            right = 1,
            waiting = 0
        }

        protected IEnumerator GetClosestUnit(float waitTime = 0)
        {
            // ie. If current go is enemy, search for player units
            List<Unit> unitList;
            if (gameObject.CompareTag(gameManager.ENEMY_TAG))
                unitList = gameManager.PlayerUnits;
            else
                unitList = gameManager.EnemyUnits;

            yield return new WaitForSeconds(waitTime);

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

            if (Health > 0)
                StartCoroutine(GetClosestUnit(Random.Range(0.1f, 0.25f)));
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
        public List<OffensiveSkills> attackList = new List<OffensiveSkills>();
        
    }
    [System.Serializable]
    public class OffensiveSkills
    {
        public int Damage;
        public float Reach;
        public AnimationClip Animation;
    }
}
