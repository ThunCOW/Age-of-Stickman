using SpineControllerVersion;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Serialization;


public class SpawnManager : MonoBehaviour
{
    [Header("_Spawn Units_")]
    public List<SpawnUnit> spawnUnitList;

    [SerializeField] private float _spawnTimer;
    private float spawnTimer
    {
        get
        {
            float randTimer = Random.Range(0.2f, _spawnTimer);
            return randTimer;
        }
        set { _spawnTimer = value; }
    }
    private float nextSpawnTimer;
    public int maxSpawn;                                                // Total amount of unit that can be spawned
    public int maxEnemyOnScreen;                                        // Max enemy that can be alive on the screen, so that player is not overwhelmed
    public int maxDeadEnemyOnScreen;                                    // So that dead units does not stack on screen, to prevent cluttering the screen ( looks ugly imo )
    public int GroupSpawnCount;                                         // Player gets some time to move after a group dies
    private int _groupSpawnCount;

    [HideInInspector] public List<Transform> spawnPosList;

    [HideInInspector] public Camera mainCamera;

    [Header("_Bossess_")]
    public GameObject SpearmasterPrefab;
    public GameObject SycthemasterPrefab;

    public static bool isBossSpawned;

    public delegate void OnSpawnBoss();
    public static OnSpawnBoss SpearmasterSpawn;

    bool preparingForBossSpawn;

    private void OnValidate()
    {
        if(mainCamera == null)
            mainCamera = Camera.main;

        spawnPosList = new List<Transform>();

        foreach (Transform spawnPos in transform.GetComponentsInChildren<Transform>())
        {
            if (spawnPos != transform)  spawnPosList.Add(spawnPos);     // GetComponentsInChildren also counts parent object
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        transform.parent = mainCamera.gameObject.transform;
        transform.localPosition = new Vector2(0, transform.localPosition.y);

        nextSpawnTimer = spawnTimer;

        _groupSpawnCount = GroupSpawnCount;


        PlayerController.BossTrigger += SpawnBoss;
    }

    // Update is called once per frame
    void Update()
    {
        if (GameManager.Instance.EnemyUnits.Count < maxEnemyOnScreen)
        {
            if (GameManager.Instance.DisableControls == false)
            {
                if (!PlayerController.isWaitingForRes)
                {
                    if (maxSpawn > 0)
                    {
                        if(DeadOnScreen.DeadUnitsOnScreen.Count >= maxDeadEnemyOnScreen)
                        {
                            if(PlayerController.hasPlayerReachedEndOfLevel)
                            {
                                SpawnLogic();
                            }
                        }
                        else
                        {
                            SpawnLogic();
                        }
                    }
                }
            }
        }
    }

    float nextGroupCountDown = 10;
    float _nextGroupCountDown = 10;
    void SpawnLogic()
    {
        // Spawning the boss ?
        if(preparingForBossSpawn)
        {
            if(GameManager.Instance.EnemyUnits.Count == 0)
                nextSpawnTimer = nextSpawnTimer > 2 ? Random.Range(0, 1.5f) : nextSpawnTimer;
        }
        // If player has not reached to end yet, set spawn timer,
        else if(!PlayerController.hasPlayerReachedEndOfLevel)
        {
            // If player has not reached to end yet, but a group is killed, wait for certain amount of time before start spawning again
            if(_groupSpawnCount == 0)
            {
                if(_nextGroupCountDown > 0)
                {
                    _nextGroupCountDown -= Time.deltaTime;
                    return;
                }
                else
                {
                    _groupSpawnCount = GroupSpawnCount / 2;
                    _groupSpawnCount += Random.Range(0, GroupSpawnCount / 2);
                    _nextGroupCountDown = nextGroupCountDown;
                }
            }
            // If player has not reached to end yet, and there is no enemy on screen, spawn in within 3.5f second
            else if (GameManager.Instance.EnemyUnits.Count == 0)
                nextSpawnTimer = nextSpawnTimer > 4 ? Random.Range(0, 3.5f) : nextSpawnTimer;
        }

        nextSpawnTimer -= Time.deltaTime;
        if (nextSpawnTimer <= 0f)                            //start spawning
        {
            //Vector2 spawnPos = spawnPosList[Random.Range(0, spawnPosList.Count)].position;
            int randNumber = Random.Range(0, 100);
            Vector2 spawnPos;
            if (GameManager.Instance.LeftSpawn.Count < 2)
                spawnPos = randNumber >= 80 ? spawnPosList[1].position : spawnPosList[0].position;
            else
                spawnPos = spawnPosList[0].position;

            GameObject nextEnemyPrefab = null;
            AIAgressiveness nextEnemyAgressiveness = 0;

            int randUnit = Random.Range(1, 101);
            int spawnPieChance = 0;                                         // all units sum of spawn chance is 100, imagine it like a pie of chance to spawn for every unit calculated by adding to each other
            foreach(SpawnUnit spawnUnit in spawnUnitList)
            {
                spawnPieChance += spawnUnit.spawnChance;
                if(randUnit <= spawnPieChance)
                {
                    nextEnemyPrefab = spawnUnit.unit;
                    nextEnemyAgressiveness = spawnUnit.AIAgressiveness;
                    break;
                }
            }

            if(nextEnemyPrefab == null)
            {
                Debug.LogError("Could not find nextEnemy during in SpawnLogic function");
                return;
            }
            GameObject spawnedEnemyGO = Instantiate(nextEnemyPrefab, new Vector3(spawnPos.x, nextEnemyPrefab.transform.position.y, 0), nextEnemyPrefab.transform.rotation);


            AIController spawnedEnemyUnit = spawnedEnemyGO.GetComponent<AIController>();
            spawnedEnemyUnit.aiAgressiveness = nextEnemyAgressiveness;

            maxSpawn--;



            if (PlayerController.hasPlayerReachedEndOfLevel)
            {
                nextSpawnTimer = Random.Range(0, 11f);
            }
            else
            {
                if (GameManager.Instance.EnemyUnits.Count >= maxEnemyOnScreen)
                    nextSpawnTimer = spawnTimer * 2;
                else
                    nextSpawnTimer = spawnTimer;
            }
            
            // TODO LeftSpawnLazy Count leftspawns, if they enter combat remove from list, max 2 leftspawn, add to list in SpawnManager
            if (spawnPos == (Vector2)spawnPosList[1].position)
                GameManager.Instance.LeftSpawn.Add(spawnedEnemyGO);
        }
    }

    void SpawnBoss(string BossTag)
    {
        Debug.Log("SpawnBoss");
        switch (BossTag)
        {
            
            case GameManager.SPEARMASTER_SPAWN_TAG:
                StartCoroutine(SpawnBossAfterNoEnemy());

                break;
            case GameManager.SCYTHEMASTER_SPAWN_TAG:
                StartCoroutine(SpawnSycthemasterAfterNoEnemy());
                break;
            default:
                break;
        }
    }

    IEnumerator SpawnBossAfterNoEnemy()
    {
        Debug.Log("SpawnBossAfterNoEnemy");
        preparingForBossSpawn = true;
        maxSpawn = 1;

        yield return new WaitUntil(() => maxSpawn == 0 && GameManager.Instance.EnemyUnits.Count == 0);

        GameManager.Instance.DisableControls = true;
        
        isBossSpawned = true;

        GameManager.Instance.Player.transform.localScale = new Vector3(1, 1, 1);    // Turn player to right just in case it isn't (since boss is going to appear from right)
        
        SpearmasterSpawn();

        yield return new WaitForSeconds(6);

        float spawnPosX = GameManager.Instance.Player.transform.position.x + 13.5f + 10; // +10 cuz it flickers and shows up in screen before transitioning to entance anim
        GameObject spawnedEnemyGO = Instantiate(SpearmasterPrefab, new Vector3(spawnPosX, SpearmasterPrefab.transform.position.y, 0), SpearmasterPrefab.transform.rotation);

        AIController spawnedEnemyUnit = spawnedEnemyGO.GetComponent<AIController>();
        spawnedEnemyUnit.aiAgressiveness = AIAgressiveness.boss;
    }

    IEnumerator SpawnSycthemasterAfterNoEnemy()
    {
        Debug.Log("SpawnSycthemasterAfterNoEnemy");
        preparingForBossSpawn = true;
        maxSpawn = 1;

        yield return new WaitUntil(() => maxSpawn == 0 && GameManager.Instance.EnemyUnits.Count == 0);

        GameManager.Instance.DisableControls = true;

        isBossSpawned = true;

        GameManager.Instance.Player.transform.localScale = new Vector3(1, 1, 1);    // Turn player to right just in case it isn't (since boss is going to appear from right)

        SpearmasterSpawn();

        yield return new WaitForSeconds(6);

        float spawnPosX = GameManager.Instance.Player.transform.position.x + 12.35f;
        GameObject spawnedEnemyGO = Instantiate(SycthemasterPrefab, new Vector3(spawnPosX, SycthemasterPrefab.transform.position.y, 0), SycthemasterPrefab.transform.rotation);

        AIController spawnedEnemyUnit = spawnedEnemyGO.GetComponent<AIController>();
        spawnedEnemyUnit.aiAgressiveness = AIAgressiveness.boss;
    }

    [System.Serializable]
    public class SpawnUnit
    {
        public GameObject unit;
        public int spawnChance;               // Out of 100
        public AIAgressiveness AIAgressiveness;
    }
}
