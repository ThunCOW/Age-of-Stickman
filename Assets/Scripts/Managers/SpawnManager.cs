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

        PossibleErrors();
    }

    // Update is called once per frame
    void Update()
    {
        if (maxSpawn > 0) 
            if(maxEnemyOnScreen > SpineControllerVersion.GameManager.Instance.EnemyUnits.Count) 
                SpawnLogic();
    }

    void SpawnLogic()
    {
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
            GameObject spawnedEnemyGO = Instantiate(nextEnemyPrefab, new Vector3(spawnPos.x, nextEnemyPrefab.transform.position.y, 0), nextEnemyPrefab.transform.rotation) as GameObject;

            AIController spawnedEnemyUnit = spawnedEnemyGO.GetComponent<AIController>();
            spawnedEnemyUnit.aiAgressiveness = nextEnemyAgressiveness;

            maxSpawn--;

            if (maxEnemyOnScreen > SpineControllerVersion.GameManager.Instance.EnemyUnits.Count)
                nextSpawnTimer = spawnTimer * 2;
            else
                nextSpawnTimer = spawnTimer;
        }
    }

    void PossibleErrors()
    {
            
    }

    [System.Serializable]
    public class SpawnUnit
    {
        public GameObject unit;
        public int spawnChance;               // Out of 100
        public AIAgressiveness AIAgressiveness;
    }
}
