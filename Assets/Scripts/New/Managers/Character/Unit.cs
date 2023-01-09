using SpineControllerVersion;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Serialization;

public class Unit : MonoBehaviour
{
    [Header("Character Stats")]
    public UnitRace Race;
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
    public StanceList currentStance
    {
        get { return _currentStance; }
        set
        {
            _currentStance = value;

            activeAnimations = animationList.GetActiveAnimationsByStance(currentStance);

            unitController.extraSpeed = animationList.GetSpeedByStance(currentStance);
        }
    }

    [SerializeField] private AnimationList _animationList;
    public AnimationList animationList
    {
        get { return _animationList; }
        set
        {
            _animationList = value.InitializeSO();

            // Reset stance
            currentStance = StanceList.Stand_A;

            // When new item is equipped, set proper animations for item
            //activeAnimations = animationList.GetActiveAnimationsByStance(currentStance);

            unitController.spineSkeletonAnimation.state.SetAnimation(1, activeAnimations.idle.SpineAnimationReference, true).TimeScale = 1f;
        }
    }

    public UnitAnimations activeAnimations;

    [Header("Target Information")]
    public Unit target;

    public GameObject Projectile;              // VERY VERY TEMPORARY stores reference to prefab of sycthe so boss can throw and shit, its very bad coding wise but later i might make a more flexible system

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
        
        if(CompareTags(gameObject, GameManager.ENEMY_TAGS))
            GameManager.Instance.EnemyUnits.Add(this);
        else if(CompareTags(gameObject, GameManager.ALLY_TAGS))
            GameManager.Instance.AllyUnits.Add(this);

        GameManager.Instance.sortManager.AddToOrder(this);

        // Animation List
        //animationList.OnStart();
        activeAnimations = animationList.GetActiveAnimationsByStance(currentStance);

        StartCoroutine(InitializeClosestUnitSearch());
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
            TurnTowardsTarget();
            StartCoroutine(GetClosestUnitSearchCycle());
        }
    }

    public IEnumerator GetClosestUnitSearchCycle(float waitTime = 0)
    {
        yield return new WaitForSeconds(waitTime);

        FindClosestUnit();

        if (Health > 0)
            StartCoroutine(GetClosestUnitSearchCycle(Random.Range(0.1f, 0.25f)));
    }

    public void FindClosestUnit()
    {
        // ie. If current unit is enemy, search for player units
        List<Unit> unitList = CompareTags(gameObject, GameManager.ENEMY_TAGS) ? GameManager.Instance.AllyUnits : GameManager.Instance.EnemyUnits;

        Unit lastUnit = target;
        
        float closestX = 5000;

        // If its Ally unit, it only targets enemies within camera view, if it continues to fight out of camera view it continues until target is dead,
        // and then if still outside of view it targets closest enemy unit like enemies instead of running back to player
        bool isAllyOutOfView = false;
        if(CompareTag(GameManager.ALLY_TAG))
        {
            if(target != null)
            {
                if(transform.position.x < GameManager.Instance.Player.transform.position.x)
                {
                    if (target.transform.position.x < GameManager.Instance.SceneViewBordersParent.transform.GetChild(0).transform.position.x)
                    {
                        isAllyOutOfView = true;
                        if (target.Health <= 0)
                            target = null;
                        else
                            return;
                    }
                }
                else if(transform.position.x > GameManager.Instance.Player.transform.position.x)
                {
                    if (target.transform.position.x > GameManager.Instance.SceneViewBordersParent.transform.GetChild(1).transform.position.x)
                    {
                        isAllyOutOfView = true;
                        if (target.Health <= 0)
                            target = null;
                        else
                            return;
                    }
                }
            }
        }
        
        target = null;

        foreach (Unit unit in unitList)
        {
            float dist = Mathf.Abs(transform.position.x - unit.transform.position.x);
            if(CompareTags(gameObject, GameManager.ENEMY_TAGS) || isAllyOutOfView)
            {
                if (closestX > dist)
                {
                    target = unit;
                    closestX = Mathf.Abs(transform.position.x - unit.transform.position.x);
                }
            }
            else if(CompareTag(GameManager.ALLY_TAG))
            {
                if (closestX > dist)
                {
                    // If enemy is not in camera borders, we want ally mercenaries to ignore it
                    if(unit.transform.position.x > transform.position.x)
                    {
                        if (unit.transform.position.x > GameManager.Instance.SceneViewBordersParent.transform.GetChild(1).transform.position.x)
                        {
                            continue;   
                        }
                    }
                    else if(unit.transform.position.x < transform.position.x)
                    {
                        if (unit.transform.position.x < GameManager.Instance.SceneViewBordersParent.transform.GetChild(0).transform.position.x)
                            continue;
                    }

                    target = unit;
                    closestX = Mathf.Abs(transform.position.x - unit.transform.position.x);
                }
            }
            // For Player
            else
            {
                float maxVision = SpawnManager.Instance.isBossSpawned ? 20 : 8.65f;    // maxVision is for player, player won't detect enemies outside of cam

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

        // For Player
        if(unitController is PlayerController)
        {
            if(lastUnit != null)
            {
                lastUnit.HealthBar.transform.parent.gameObject.SetActive(false);
            }
            if (target != null)
            {
                if(GameManager.Instance.DisableControls == false)
                    target.HealthBar.transform.parent.gameObject.SetActive(true);
            }
        }
    }

    /// <summary>
    /// Automatically turns current unit towards the target(enemy)
    /// </summary>
    public void TurnTowardsTarget()
    {
        // i.e if target is more on the right but unit is looking left, turn it right
        int lookDir = transform.position.x > target.transform.position.x ? -1 : 1;

        transform.localScale = new Vector3(lookDir, transform.localScale.y, transform.localScale.z);
    }

    public void SetUnitDirection(int lookDir)
    {
        if (lookDir == 0)
            return;

        transform.localScale = new Vector3(lookDir, transform.localScale.y, transform.localScale.z);
    }

    public MoveDirection GetDirectionRelativeToTarget()
    {
        return transform.position.x > target.transform.position.x ? MoveDirection.left : MoveDirection.right;
    }

    public static bool CompareTags(GameObject gameObject, List<string> tags)
    {
        foreach(string tag in tags)
        {
            if (gameObject.CompareTag(tag))
                return true;
        }
        return false;
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

enum GameLayers
{
    Default,
    TransparentFX,
    IgnoreRaycast,
    Empty,
    Water,
    UI,
    Blood,
    Blood2,
    Ground,
    Cut_Unit_Parts,
    Gold,
    Player,
    Projectile,
    Player_Interactible_Trigger,
    DeadUnit,
}