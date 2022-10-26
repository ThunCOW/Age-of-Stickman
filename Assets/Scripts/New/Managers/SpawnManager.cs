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
    public int maxSpawn;
    public int maxEnemyOnScreen;

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
        
        PlayerController.BossTrigger += SpawnBoss;
    }

    // Update is called once per frame
    void Update()
    {
        if(GameManager.Instance.DisableControls == false)
        {
            if (maxSpawn > 0) 
                if(maxEnemyOnScreen > GameManager.Instance.EnemyUnits.Count) 
                    SpawnLogic();
        }
    }

    void SpawnLogic()
    {
        
        if(preparingForBossSpawn)
        {
            if(GameManager.Instance.EnemyUnits.Count == 0)
                nextSpawnTimer = nextSpawnTimer > 2 ? Random.Range(0, 1.5f) : nextSpawnTimer;
        }
        else if(PlayerController.hasPlayerReachedEndOfLevel)
        {
            nextSpawnTimer = Random.Range(0, 11f);
        }
        else
        {
            if (GameManager.Instance.EnemyUnits.Count == 0)
                nextSpawnTimer = nextSpawnTimer > 4 ? Random.Range(0, 3.5f) : nextSpawnTimer;
        }

        nextSpawnTimer -= Time.deltaTime;
        if (nextSpawnTimer <= 0f)                            //start spawning
        {

            int randNumber = Random.Range(0, spawnPosList.Count);

            Vector2 spawnPos = spawnPosList[randNumber].position;

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

            if (maxEnemyOnScreen > GameManager.Instance.EnemyUnits.Count)
                nextSpawnTimer = spawnTimer * 2;
            else
                nextSpawnTimer = spawnTimer;
        }
    }

    void SpawnBoss(string BossTag)
    {
        switch (BossTag)
        {
            case GameManager.SPEARMASTER_TAG:
                StartCoroutine(SpawnBossAfterNoEnemy());

                break;
            case GameManager.SCYTHEMASTER_TAG:

                break;
            default:
                break;
        }
    }

    IEnumerator SpawnBossAfterNoEnemy()
    {
        preparingForBossSpawn = true;

        maxSpawn = 1;

        //while(maxSpawn != 0 && GameManager.Instance.EnemyUnits.Count != 0)
        //{
        //    yield return new WaitForFixedUpdate();
        //}
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

    [System.Serializable]
    public class SpawnUnit
    {
        public GameObject unit;
        public int spawnChance;               // Out of 100
        public AIAgressiveness AIAgressiveness;
    }
}
