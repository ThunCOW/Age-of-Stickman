using SpineControllerVersion;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Serialization;


public class SpawnManager : MonoBehaviour
{
    public static SpawnManager Instance;

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


    public bool isBossLevel;
    public bool isBossSpawned;

    public delegate void OnSpawnBoss(string BossTag);
    public OnSpawnBoss SpawnBossEvent;

    bool preparingForBossSpawn;

    private void OnValidate()
    {
        if (mainCamera == null)
            mainCamera = Camera.main;

        spawnPosList = new List<Transform>();

        foreach (Transform spawnPos in transform.GetComponentsInChildren<Transform>())
        {
            if (spawnPos != transform)  spawnPosList.Add(spawnPos);     // GetComponentsInChildren also counts parent object
        }
    }

    void Awake()
    {
        Instance = this;
        
        /*if (mainCamera == null)
            mainCamera = Camera.main;

        if (spawnPosList == null)
        {
            spawnPosList = new List<Transform>();

            foreach (Transform spawnPos in transform.GetComponentsInChildren<Transform>())
            {
                if (spawnPos != transform) spawnPosList.Add(spawnPos);     // GetComponentsInChildren also counts parent object
            }
        }*/
    }

    // Start is called before the first frame update
    void Start()
    {
        transform.parent = mainCamera.gameObject.transform;
        transform.localPosition = new Vector2(0, transform.localPosition.y);

        nextSpawnTimer = spawnTimer;

        _groupSpawnCount = GroupSpawnCount;

        (GameManager.Instance.Player.unitController as PlayerController).BossTrigger += SpawnBoss;
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
                        // Means there is too many dead body on screen
                        if(DeadOnScreen.DeadUnitsOnScreen.Count >= maxDeadEnemyOnScreen)
                        {
                            // If player is at the end of level, continue to spawn
                            if((GameManager.Instance.Player.unitController as PlayerController).hasPlayerReachedEndOfLevel)
                            {
                                SpawnLogic();
                            }
                        }
                        // If dead unit on screen limit is not reached but total amount of alive + dead enemy unit
                        // is bigger than limit + 1 ( can have 1 more spawn than limit, not more than that )
                        else if(DeadOnScreen.DeadUnitsOnScreen.Count + GameManager.Instance.EnemyUnits.Count >= maxDeadEnemyOnScreen + 1)
                        {
                            SpawnLogic();
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
        else if(!(GameManager.Instance.Player.unitController as PlayerController).hasPlayerReachedEndOfLevel)
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



            if ((GameManager.Instance.Player.unitController as PlayerController).hasPlayerReachedEndOfLevel)
            {
                nextSpawnTimer = Random.Range(4, 11f);
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
                StartCoroutine(SpawnSpearmasterAfterNoEnemy());
                break;
            case GameManager.SCYTHEMASTER_SPAWN_TAG:
                StartCoroutine(SpawnSycthemasterAfterNoEnemy());
                break;
            case GameManager.DOUBLEAXEDEMON_SPAWN_TAG:
                StartCoroutine(SpawnDoubleAxeDemonSummoner());
                break;
            case GameManager.BIG_DEMON_SPAWN_TAG:
                StartCoroutine(SpawnBigDemonSummoner());
                break;
            case GameManager.DUALSWORDBOSS_SPAWN_TAG:
                StartCoroutine(DualSwordBossAfterNoEnemy());
                break;
            default:
                break;
        }
    }

    private IEnumerator DualSwordBossAfterNoEnemy()
    {
        Debug.Log("SpawnBossAfterNoEnemy");
        preparingForBossSpawn = true;
        maxSpawn = 1;

        yield return new WaitUntil(() => maxSpawn == 0 && GameManager.Instance.EnemyUnits.Count == 0);

        SoundManager.Instance.TurnMusicDown();

        GameManager.Instance.DisableControls = true;

        isBossSpawned = true;

        GameManager.Instance.Player.transform.localScale = new Vector3(1, 1, 1);    // Turn player to right just in case it isn't (since boss is going to appear from right)

        SpawnBossEvent(GameManager.DUALSWORDBOSS_SPAWN_TAG);

        yield return new WaitForSeconds(4.5f);

        float spawnPosX = GameManager.Instance.Player.transform.position.x + 13.5f + 10; // +10 cuz it flickers and shows up in screen before transitioning to entance anim
        GameObject spawnedEnemyGO = Instantiate(GameManager.Instance.DualSwordBossPrefab, new Vector3(spawnPosX, GameManager.Instance.DualSwordBossPrefab.transform.position.y, 0), GameManager.Instance.DualSwordBossPrefab.transform.rotation);

        AIController spawnedEnemyUnit = spawnedEnemyGO.GetComponent<AIController>();
        spawnedEnemyUnit.aiAgressiveness = AIAgressiveness.boss;
    }

    private IEnumerator DualSwordBossAfterNoEnemy2()
    {
        Debug.Log("SpawnBossAfterNoEnemy");
        preparingForBossSpawn = true;
        maxSpawn = 1;

        yield return new WaitUntil(() => maxSpawn == 0 && GameManager.Instance.EnemyUnits.Count == 0);

        GameManager.Instance.DisableControls = false;

        isBossSpawned = true;

        //GameManager.Instance.Player.transform.localScale = new Vector3(1, 1, 1);    // Turn player to right just in case it isn't (since boss is going to appear from right)

        //SpawnBossEvent(GameManager.DUALSWORDBOSS_SPAWN_TAG);

        float spawnPosX = GameManager.Instance.Player.transform.position.x + 13.5f + 10; // +10 cuz it flickers and shows up in screen before transitioning to entance anim
        GameObject spawnedEnemyGO = Instantiate(GameManager.Instance.DualSwordBossPrefab, new Vector3(spawnPosX, GameManager.Instance.DualSwordBossPrefab.transform.position.y, 0), GameManager.Instance.DualSwordBossPrefab.transform.rotation);

        AIController spawnedEnemyUnit = spawnedEnemyGO.GetComponent<AIController>();
        spawnedEnemyUnit.aiAgressiveness = AIAgressiveness.boss;
    }

    IEnumerator SpawnDoubleAxeDemonSummoner()
    {
        Debug.Log("SpawnDoubleAxeDemonSummoner");

        maxSpawn = 0;

        GameManager.Instance.DisableControls = true;

        isBossSpawned = true;

        GameManager.Instance.Player.transform.localScale = new Vector3(1, 1, 1);    // Turn player to right just in case it isn't (since boss is going to appear from right)

        SpawnBossEvent(GameManager.DOUBLEAXEDEMON_SPAWN_TAG);

        // Spawn DemonSummoner

        float spawnPosX = GameManager.Instance.Player.transform.position.x + 29.1f;
        GameObject spawnedEnemyGO_A = Instantiate(GameManager.Instance.DemonSummonerFirstEntrance, new Vector3(spawnPosX, GameManager.Instance.DemonSummonerFirstEntrance.transform.position.y, 0), GameManager.Instance.DemonSummonerFirstEntrance.transform.rotation);

        AIController spawnedEnemyUnit_A = spawnedEnemyGO_A.GetComponent<AIController>();
        spawnedEnemyUnit_A.aiAgressiveness = AIAgressiveness.boss;

        // Spawn Double Axe Demon Boss

        spawnPosX = GameManager.Instance.Player.transform.position.x + 27.5f;
        GameObject spawnedEnemyGO_B = Instantiate(GameManager.Instance.DoubleAxeDemon, new Vector3(spawnPosX, GameManager.Instance.DoubleAxeDemon.transform.position.y, 0), GameManager.Instance.DoubleAxeDemon.transform.rotation);

        AIController spawnedEnemyUnit_B = spawnedEnemyGO_B.GetComponent<AIController>();
        spawnedEnemyUnit_B.aiAgressiveness = AIAgressiveness.boss;

        yield return new WaitForSeconds(3);

        SoundManager.Instance.TurnMusicDown();
    }
    
    IEnumerator SpawnBigDemonSummoner()
    {
        Debug.Log("SpawnBigDemonSummoner");
        
        maxSpawn = 0;

        GameManager.Instance.DisableControls = true;

        isBossSpawned = true;

        GameManager.Instance.Player.transform.localScale = new Vector3(1, 1, 1);    // Turn player to right just in case it isn't (since boss is going to appear from right)

        SpawnBossEvent(GameManager.BIG_DEMON_SPAWN_TAG);

        float spawnPosX = GameManager.Instance.Player.transform.position.x + 29.1f;
        GameObject spawnedEnemyGO = Instantiate(GameManager.Instance.DemonSummoner, new Vector3(spawnPosX, GameManager.Instance.DemonSummoner.transform.position.y, 0), GameManager.Instance.DemonSummoner.transform.rotation);

        AIController spawnedEnemyUnit = spawnedEnemyGO.GetComponent<AIController>();
        spawnedEnemyUnit.aiAgressiveness = AIAgressiveness.boss;

        yield return new WaitForSeconds(3);

        SoundManager.Instance.TurnMusicDown();
    }

    /*IEnumerator SpawnBigBossAfterPortalOpening()
    {
        Debug.Log("SpawnBigBossAfterPortalOpening");
        preparingForBossSpawn = true;
        maxSpawn = 1;

        yield return new WaitUntil(() => maxSpawn == 0 && GameManager.Instance.EnemyUnits.Count == 0);

        GameManager.Instance.DisableControls = true;

        isBossSpawned = true;

        GameManager.Instance.Player.transform.localScale = new Vector3(1, 1, 1);    // Turn player to right just in case it isn't (since boss is going to appear from right)

        SpawnBossEvent();

        yield return new WaitForSeconds(4.5f);

        //
        // Spawn Portal
        //

        float spawnPosX = GameManager.Instance.Player.transform.position.x + 8.5f; // +10 cuz it flickers and shows up in screen before transitioning to entance anim
        GameObject spawnedPortal = Instantiate(PortalPrefab, new Vector3(spawnPosX, PortalPrefab.transform.position.y, 0), PortalPrefab.transform.rotation);

        spawnedPortal.transform.GetChild(1).gameObject.SetActive(false);

        spawnedPortal.transform.localScale = new Vector3(0.1f, 0.1f, 1);

        yield return new WaitForSeconds(1.5f);

        spawnedPortal.transform.GetChild(1).gameObject.SetActive(true);

        float countDown = 0.15f;
        while(countDown <= 1.5f)
        {
            countDown += Time.deltaTime;
            float perc = countDown / 1.5f;

            spawnedPortal.transform.localScale = new Vector2(perc, perc);
            
            yield return new WaitForFixedUpdate();
        }
        
        spawnedPortal.transform.localScale = Vector3.one;

        //
        //

        yield return new WaitForSeconds(7.5f);

        //
        // Spawn Big Boss
        //

        spawnPosX = GameManager.Instance.Player.transform.position.x + 8.5f; // +10 cuz it flickers and shows up in screen before transitioning to entance anim
        GameObject spawnedEnemyGO = Instantiate(BigBossPrefab, new Vector3(spawnPosX, BigBossPrefab.transform.position.y, 0), BigBossPrefab.transform.rotation);

        AIController spawnedEnemyUnit = spawnedEnemyGO.GetComponent<AIController>();
        spawnedEnemyUnit.aiAgressiveness = AIAgressiveness.boss;
    }*/

    IEnumerator SpawnSpearmasterAfterNoEnemy()
    {
        Debug.Log("SpawnBossAfterNoEnemy");
        preparingForBossSpawn = true;
        maxSpawn = 1;

        yield return new WaitUntil(() => maxSpawn == 0 && GameManager.Instance.EnemyUnits.Count == 0);

        SoundManager.Instance.TurnMusicDown();

        GameManager.Instance.DisableControls = true;
        
        isBossSpawned = true;

        GameManager.Instance.Player.transform.localScale = new Vector3(1, 1, 1);    // Turn player to right just in case it isn't (since boss is going to appear from right)
        
        SpawnBossEvent(GameManager.SPEARMASTER_SPAWN_TAG);

        yield return new WaitForSeconds(4.5f);

        float spawnPosX = GameManager.Instance.Player.transform.position.x + 13.5f + 10; // +10 cuz it flickers and shows up in screen before transitioning to entance anim
        GameObject spawnedEnemyGO = Instantiate(GameManager.Instance.SpearmasterPrefab, new Vector3(spawnPosX, GameManager.Instance.SpearmasterPrefab.transform.position.y, 0), GameManager.Instance.SpearmasterPrefab.transform.rotation);

        AIController spawnedEnemyUnit = spawnedEnemyGO.GetComponent<AIController>();
        spawnedEnemyUnit.aiAgressiveness = AIAgressiveness.boss;
    }

    IEnumerator SpawnSycthemasterAfterNoEnemy()
    {
        Debug.Log("SpawnSycthemasterAfterNoEnemy");
        preparingForBossSpawn = true;
        maxSpawn = 1;


        float LandPosX = GameManager.Instance.Player.transform.position.x + 12.35f;
        Vector3 spawnPos = new Vector3(GameManager.Instance.Player.transform.position.x + 25, GameManager.Instance.SycthemasterPrefab.transform.position.y, 0);
        GameObject spawnedEnemyGO = Instantiate(GameManager.Instance.SycthemasterPrefab, spawnPos, GameManager.Instance.SycthemasterPrefab.transform.rotation);

        AIController spawnedEnemyUnit = spawnedEnemyGO.GetComponent<AIController>();
        spawnedEnemyUnit.aiAgressiveness = AIAgressiveness.boss;

        yield return new WaitUntil(() => maxSpawn == 0 && GameManager.Instance.EnemyUnits.Count == 1);

        SoundManager.Instance.TurnMusicDown();

        spawnedEnemyGO.GetComponent<AIController>().enabled = true;

        GameManager.Instance.DisableControls = true;

        isBossSpawned = true;

        GameManager.Instance.Player.transform.localScale = new Vector3(1, 1, 1);    // Turn player to right just in case it isn't (since boss is going to appear from right)

        SpawnBossEvent(GameManager.SCYTHEMASTER_SPAWN_TAG);
    }

    [System.Serializable]
    public class SpawnUnit
    {
        public GameObject unit;
        public int spawnChance;               // Out of 100
        public AIAgressiveness AIAgressiveness;
    }
}
