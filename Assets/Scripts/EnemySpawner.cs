using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemySpawner : MonoBehaviour
{
    [SerializeField] GameObject Player;
    [Space]
    [SerializeField] GameObject enemySpawnParent;
    [Space]
    [SerializeField] List<GameObject> enemyPrefabList = new List<GameObject>();
    [Space]
    [SerializeField] List<Transform> spawnPosList = new List<Transform>();
    //public GameObject swordsmanPrefab;
    //public GameObject spearmanPrefab;

    [Space]
    [SerializeField] private int enemyNumber;
    
    private float randSpawnRate;
    private float nextSpawn = 0f;


    // Start is called before the first frame update
    void Start()
    {
        PossibleErrors();
    }

    // Update is called once per frame
    void Update()
    {
        if(enemyNumber > 0) SpawnLogic();
    }

    void SpawnLogic()
    {
        nextSpawn -= Time.deltaTime;
        if (nextSpawn <= 0f)                            //start spawning
        {
            int randNumber = Random.Range(0, 2);
            
            Vector2 spawnPos = spawnPosList[randNumber].position;

            randNumber = Random.Range(0, enemyPrefabList.Count);
            
            GameObject spawned = Instantiate(enemyPrefabList[randNumber], spawnPos, enemyPrefabList[randNumber].transform.rotation) as GameObject;
            spawned.transform.SetParent(enemySpawnParent.transform);
            spawnPos = new Vector2(spawnPos.x + 0.275f, spawnPos.y);

            spawned.GetComponent<TempEnemy>().Player = this.Player;
        
            //set a new spawn time
            randSpawnRate = Random.Range(0, 8f);
            nextSpawn = randSpawnRate;
            
            enemyNumber--;
        }
    }

    void PossibleErrors()
    {
        if(Player == null)
            Debug.LogError("Player object is not set!");

        if(spawnPosList.Count == 0)
            Debug.LogError("Spawn points are not set!");

        if(enemyPrefabList.Count == 0)
            Debug.LogError("Enemy prefab list is empty!");
    }
}