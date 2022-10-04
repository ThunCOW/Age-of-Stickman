using SpineControllerVersion;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Unit : MonoBehaviour
{
    [Header("Character Stats")]
    public GameObject HealthBar;
    public int HealthMax;
    [SerializeField] private int _Health;
    public int Health
    {
        get { return _Health; }
        set
        {
            _Health = value;
            if (value < 0)
                _Health = 0;
            
            float healthPercentage = (float)Health / (float)HealthMax;
            HealthBar.transform.localScale = new Vector3(healthPercentage, 1, 1);
        }
    }
    public int Damage;
    public GameObject bloodObject;

    [HideInInspector] public UnitController unitController;
    [HideInInspector] public EquipmentManager unitInventory;

    private StanceList _currentStance;
    [SerializeField]
    protected StanceList currentStance
    {
        get { return _currentStance; }
        set
        {
            _currentStance = value;

            //activeAnimations = animationList.GetActiveAnimationsByStance(currentStance);
        }
    }

    [SerializeField] private AnimationList _animationList;
    public AnimationList animationList
    {
        get { return _animationList; }
        set
        {
            _animationList = value;

            // Reset stance
            currentStance = StanceList.Stand_A;

            // When new item is equipped, set proper animations for item
            activeAnimations = animationList.GetActiveAnimationsByStance(currentStance);

            unitController.spineSkeletonAnimation.state.SetAnimation(1, activeAnimations.idle.SpineAnimationReference, true).TimeScale = 1f;
        }
    }

    public UnitAnimations activeAnimations;

    [Header("Target Information")]
    public Unit target;

    void OnValidate()
    {
        // Unit Controller
        if(unitController == null) unitController = GetComponent<UnitController>();

        if (unitInventory == null) unitInventory = GetComponent<EquipmentManager>();

        if (HealthBar == null) HealthBar = gameObject.transform.Find("HealthBar").GetChild(0).gameObject;
    }

    // Start is called before the first frame update
    void Start()
    {
        Health = HealthMax;

        // GameManager
        if (gameObject.CompareTag(GameManager.Instance.ENEMY_TAG))
            GameManager.Instance.EnemyUnits.Add(this);
        else
            GameManager.Instance.PlayerUnits.Add(this);

        GameManager.Instance.sortManager.AddToOrder(this);

        // Animation List
        //animationList.OnStart();
        activeAnimations = animationList.GetActiveAnimationsByStance(currentStance);

        StartCoroutine(InitializeClosestUnitSearch());
    }

    // Update is called once per frame
    void Update()
    {

    }

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

    protected IEnumerator GetClosestUnitSearchCycle(float waitTime = 0)
    {
        yield return new WaitForSeconds(waitTime);

        FindClosestUnit();

        if (Health > 0)
            StartCoroutine(GetClosestUnitSearchCycle(Random.Range(0.1f, 0.25f)));
    }

    public void FindClosestUnit()
    {
        // ie. If current unit is enemy, search for player units
        List<Unit> unitList;
        if (gameObject.CompareTag(GameManager.Instance.ENEMY_TAG))
            unitList = GameManager.Instance.PlayerUnits;
        else
            unitList = GameManager.Instance.EnemyUnits;

        Unit lastUnit = target;
        
        target = null;

        float closestX = 5000;
        foreach (Unit unit in unitList)
        {
            float dist = Mathf.Abs(transform.position.x - unit.transform.position.x);
            if (gameObject.CompareTag(GameManager.Instance.ENEMY_TAG))
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

        if(gameObject.GetComponent<PlayerController>() != null)
        {
            if(lastUnit != null)
            {
                lastUnit.HealthBar.transform.parent.gameObject.SetActive(false);
            }
            if (target != null)
            {
                target.HealthBar.transform.parent.gameObject.SetActive(true);
            }
        }
    }

    public void CheckUnitDirection()
    {
        // i.e if target is more on the right but unit is looking left, turn it right
        int lookDir = transform.position.x > target.transform.position.x ? -1 : 1;

        transform.localScale = new Vector3(lookDir, transform.localScale.y, transform.localScale.z);
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
