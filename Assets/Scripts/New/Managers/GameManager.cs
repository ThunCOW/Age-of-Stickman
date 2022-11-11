using Spine.Unity;
using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

namespace SpineControllerVersion
{
    public class GameManager : MonoBehaviour, ISaveableJson, ISerializationCallbackReceiver
    {
        public static GameManager Instance;

        // Delegates
        public delegate void OnControlsDsiabled();
        public static OnControlsDsiabled DisableAllControls;
        public static OnControlsDsiabled EnableAllControls;

        

        [Header("_Various Variables_")]
        public SceneLoader SceneLoader;

        [SerializeField] private bool _disableControls;
        public bool DisableControls
        {
            get { return _disableControls; }
            set
            {
                _disableControls = value;
                if (value == true)
                {
                    Debug.Log("Controls are disabled");
                    
                    DisableAllControls();
                }
                else
                {
                    Debug.Log("Controls are enabled");

                    EnableAllControls();
                }
            }
        }

        public GameObject LevelBordersParent;
        public GameObject SceneViewBordersParent;





        [Header("_Unit Assignments_")]
        public List<Unit> EnemyUnits = new List<Unit>();
        [HideInInspector] public List<GameObject> LeftSpawn; // TODO LeftSpawnLazy Count leftspawns, if they enter combat remove from list, max 2 leftspawn, add to list in SpawnManager
        public List<Unit> AllyUnits = new List<Unit>();

        [HideInInspector] public SortManager sortManager = new SortManager();




        // TAGS
        public const string GOLD_TAG = "Gold";
        
        public const string ENEMY_TAG = "EnemyUnit";
        public const string SPEARMASTER_TAG = "Spearmaster";
        public const string SCYTHEMASTER_TAG = "Scythemaster";

        public const string ALLY_TAG = "AllyUnit";
        public const string PLAYER_TAG = "PlayerUnit";


        public const string FINISH_LEVEL_TAG = "FinishLevelTrigger";
        public const string SPEARMASTER_SPAWN_TAG = "SpearmasterBossTrigger";
        public const string SCYTHEMASTER_SPAWN_TAG = "SycthemasterBossTrigger";

        public static List<string> ENEMY_TAGS = new List<string> { ENEMY_TAG, SPEARMASTER_TAG, SCYTHEMASTER_TAG };
        public static List<string> ALLY_TAGS = new List<string> { ALLY_TAG, PLAYER_TAG };





        [Header("_Player Variabes_")]
        public Unit Player;
        [SerializeField] private AllEquipments AllEquipments;
        private List<int> _PlayerEquipmentsKeys = new List<int>();
        private List<int> PlayerEquipmentsKeys
        {
            get //Called when Saving
            {
                _PlayerEquipmentsKeys.Clear();
                foreach (Item item in PlayerEquipments)
                {
                    int index = AllEquipments.Equipments.IndexOf(item);
                    if (index == -1)
                        return null;

                    _PlayerEquipmentsKeys.Add(AllEquipments.Equipments.IndexOf(item));
                    //if (SecondaryWeapon != null) PlayerEquipmentsKeys.Add(AllEquipments.Equipments.IndexOf(SecondaryWeapon));
                }
                return _PlayerEquipmentsKeys; 
            }
            set //Called when Loading
            {
                _PlayerEquipmentsKeys = value;
                PlayerEquipments.Clear();
                foreach(int i in _PlayerEquipmentsKeys)
                {
                    PlayerEquipments.Add(AllEquipments.Equipments[i]);
                }
            }
        }
        public List<Item> PlayerEquipments;

        public PlayerControls PlayerControls;
        //public Item SecondaryWeapon;

        [SerializeField] private int _PlayerLives;
        public int PlayerLives
        {
            get { return _PlayerLives; }
            private set
            {
                _PlayerLives = value;
            }
        }

        public UnitHolder mainMenuPlayer;



        [Header("_Gold Variables_")]

        public List<AudioClip> CoinClickingAfterLevel;
        int _goldGained;
        public int GoldGained
        {
            get { return _goldGained; }
            set
            {
                if(value == 0)
                {
                    GoldChange(GoldGained, 1.5f);
                    
                    if(GoldGained != 0) SoundManager.Instance.PlayEffect(CoinClickingAfterLevel[Random.Range(0, CoinClickingAfterLevel.Count)]);
                }
                _goldGained = value;
            }
        }

        public GameObject GoldPrefab;
        public List<AudioClip> CoinPickupSound;
        [SerializeField] private int _Gold;
        public int Gold
        {
            get 
            {
                if (minusGoldAnimation != null)
                {
                    return lastGoldAmount + lastSpentAmount;
                }
                return _Gold; 
            }
            private set 
            {
                if(_Gold != value)
                    GoldText.text = value.ToString();
                
                _Gold = value;
            }
        }
        public TMP_Text GoldText;
        public GameObject MinusGoldTextPrefab;
        public GameObject NotEnoughMoneyTextPrefab;





        [Header("_Temporary / Dumb Variables_")]
        // Too lazy to make a system fro secondary weapon so im just gonna check if first boss is dead and hide/show weapon lmao
        public bool IsSpearmasterDead;

        public int Level;






        void Awake()
        {
            if (Instance == null)
            {
                Instance = this;
                DontDestroyOnLoad(this.gameObject);
            }
            else
                Destroy(this.gameObject);

            QualitySettings.vSyncCount = 0;
            Application.targetFrameRate = 60;

            LoadDataAsJson();



            SceneLoader.LevelLoaded += LevelLoaded;
        }

        void Start()
        {
            mainMenuPlayer.ChangeUnitEquipments(mainMenuPlayer, PlayerEquipments);
        }





        // Gold Change
        GameObject minusGoldTextSpawn;
        Coroutine minusGoldTextSpawnTimer;
        Coroutine minusGoldAnimation;
        int lastGoldAmount;
        int lastSpentAmount;
        public void GoldChange(int Amount, float animationTime = 0.5f)
        {
            if (Amount == 0)
                return;

            GameObject parent = GoldText.transform.parent.gameObject;

            int extraSpace = -25;
            if (Mathf.Abs(Gold) >= 10 && Mathf.Abs(Gold) < 100)
                extraSpace = 25;
            else if (Mathf.Abs(Gold) >= 100)
                extraSpace = 60;

            Vector3 spawnPos = new Vector3(250 + extraSpace, 0, parent.transform.position.z);
            
            GameObject minusGoldTextSpawnTempGO = Instantiate(MinusGoldTextPrefab, GoldText.transform.parent);

            minusGoldTextSpawnTempGO.transform.localPosition = spawnPos;

            string mathSign = "-";
            if (Amount >= 0)
                mathSign = "+";
            minusGoldTextSpawnTempGO.GetComponent<TMP_Text>().text = mathSign + Mathf.Abs(Amount).ToString();

            if (minusGoldTextSpawn != null)
            {
                StopCoroutine(minusGoldTextSpawnTimer);

                Destroy(minusGoldTextSpawn);
            }

            minusGoldTextSpawn = minusGoldTextSpawnTempGO;

            minusGoldTextSpawnTimer = StartCoroutine(TextDisappearSlowly(minusGoldTextSpawn));

            if(minusGoldAnimation != null)
            {
                Gold = lastGoldAmount + lastSpentAmount;
                StopCoroutine(minusGoldAnimation);
                minusGoldAnimation = null;
            }

            lastGoldAmount = Gold;
            lastSpentAmount = Amount;
            minusGoldAnimation = StartCoroutine(MinusGoldAnimation(Amount, animationTime));
        }
        IEnumerator MinusGoldAnimation(int amount, float animationTime = 0.5f)
        {
            int WaitFrame = (int)(60 * animationTime);
            int lastGoldAmount = Gold;

            float changeTextPerFrameDefault = Mathf.Abs((float)WaitFrame / (float)amount);
            float changeAmount = amount >= 0 ? 1 : -1;
            if(Mathf.Abs(amount) > WaitFrame)
            {
                changeAmount = amount / WaitFrame;
            }


            if (changeTextPerFrameDefault >= 1)
            {
                for (int i = 0; i < WaitFrame; i++)
                {
                    Gold = lastGoldAmount + (int)(changeAmount) * (int)(i / changeTextPerFrameDefault);

                    yield return new WaitForEndOfFrame();
                }
                Gold = lastGoldAmount + amount;
            }
            else
            {
                for (int i = 0; i < WaitFrame; i++)
                {
                    Gold = lastGoldAmount + (int)(changeAmount * (i + 1));

                    yield return new WaitForEndOfFrame();
                }
                Gold = lastGoldAmount + amount;
            }
            minusGoldAnimation = null;
        }
        // if waitForWithoutAlphaChange is set to 0, text will start with 65% alpha and disappear within disappearTime second, if not, it will show 100 alpha for waitForWithoutAlphaChange then slowly disappear from 100 to 0
        IEnumerator TextDisappearSlowly(GameObject TextSpawn, float waitForWithoutAlphaChange = 0, float disappearTime = 1.5f, float speed = 10)
        {
            TMP_Text tempText = TextSpawn.GetComponent<TMP_Text>();
            Color tempColor = tempText.color;
            
            float wait = waitForWithoutAlphaChange;
            // First Continue Without Changing Alpha
            while(wait > 0)
            {
                wait -= Time.deltaTime;

                TextSpawn.transform.position = new Vector3(TextSpawn.transform.position.x + (speed * Time.deltaTime), TextSpawn.transform.position.y, TextSpawn.transform.position.z);

                yield return new WaitForFixedUpdate();
            }

            wait = disappearTime;
            // Start Changing Alpha
            while(wait > 0)
            {
                wait -= Time.deltaTime;

                float percentage = waitForWithoutAlphaChange == 0 ? (wait / disappearTime) * 0.65f : (wait / disappearTime);

                tempColor.a = percentage;
                tempText.color = tempColor;

                TextSpawn.transform.position = new Vector3(TextSpawn.transform.position.x + (speed * Time.deltaTime), TextSpawn.transform.position.y, TextSpawn.transform.position.z);

                yield return new WaitForFixedUpdate();
            }
            minusGoldTextSpawn = null;

            Destroy(TextSpawn);
        }

        GameObject notEnoughGoldTextSpawn;
        Coroutine notEnoughGoldTextCoroutine;
        public void NotEnoughGold()
        {
            int extraSpace = -100;
            if (Mathf.Abs(Gold) >= 10 && Mathf.Abs(Gold) < 100)
                extraSpace = -35;
            else if (Mathf.Abs(Gold) >= 100)
                extraSpace = 0;

            GameObject NotEnoughMoneyTextSpawnTempGO = Instantiate(NotEnoughMoneyTextPrefab, GoldText.transform.parent, false);

            NotEnoughMoneyTextSpawnTempGO.transform.localPosition = new Vector3(NotEnoughMoneyTextSpawnTempGO.transform.localPosition.x + extraSpace, NotEnoughMoneyTextSpawnTempGO.transform.localPosition.y, NotEnoughMoneyTextSpawnTempGO.transform.localPosition.z);

            if (notEnoughGoldTextSpawn != null)
            {
                StopCoroutine(notEnoughGoldTextCoroutine);

                Destroy(notEnoughGoldTextSpawn);
            }

            notEnoughGoldTextSpawn = NotEnoughMoneyTextSpawnTempGO;

            notEnoughGoldTextCoroutine = StartCoroutine(TextDisappearSlowly(notEnoughGoldTextSpawn, 0.7f));
        }







        // Player Lives
        public void PlayerLivesChange(int Amount)
        {
            PlayerLives += Amount;
        }

        void LevelLoaded()
        {
            StartCoroutine(SpawnMercenaries());
        }
        
        IEnumerator SpawnMercenaries()
        {
            yield return new WaitUntil(() => Player != null);

            int order = 1;
            for (int i = 0; i < MercenaryManager.Instance.Mercenaries.Count; i++)
            {
                if (MercenaryManager.Instance.Mercenaries[i].CurrentMercenary == null)
                    continue;

                GameObject MercenaryGameObject = MercenaryManager.Instance.Mercenaries[i].CurrentMercenary.Unit;

                float DistanceToPlayer = Random.Range(1.5f * order, 2.2f * order);
                float spawnPosX = Player.transform.position.x - (DistanceToPlayer);
                GameObject spawnedAllyGO = Instantiate(MercenaryGameObject, new Vector3(spawnPosX, MercenaryGameObject.transform.position.y, 0), MercenaryGameObject.transform.rotation);

                AllyController spawnedAllyController = spawnedAllyGO.GetComponent<AllyController>();

                spawnedAllyController.aiAgressiveness = AIAgressiveness.boss;

                spawnedAllyController.DistanceToPlayer = DistanceToPlayer;

                spawnedAllyController.mercenaryUnit = MercenaryManager.Instance.Mercenaries[i];

                spawnedAllyController.MercenaryDead += MercenaryManager.Instance.MercenaryDead;

                order++;
            }
        }






        /*********************
         * Saving and Loading
        */
        [ContextMenu("SaveJsonData")]
        public void SaveDataAsJson()
        {
            SaveData sd = new SaveData();
            
            if (PopulateSaveData(sd))
                FileManager.WriteToFile(sd.ToJson());
            else
                Debug.LogError("Failed to save game data");
        }

        public bool PopulateSaveData(SaveData a_SaveData)
        {
            if (PlayerEquipments.Count == 0)
                return false;
            
            a_SaveData.equippedItemIndexs = PlayerEquipmentsKeys;
            if (a_SaveData.equippedItemIndexs == null)              // Means there is a problem finding item/s ( maybe AllItem SO does not contain one of the item etc.)
                return false;

            a_SaveData.PlayerLives = PlayerLives;
            a_SaveData.Gold = Gold;

            a_SaveData.IsSpearmasterDead = IsSpearmasterDead;

            a_SaveData.Level = Level;

            //foreach (MercenaryUnit mercenaryUnit in MercenaryManager.Instance.Mercenaries)
            //    a_SaveData.Mercenaries.Add(mercenaryUnit.CurrentMercenary);
            a_SaveData.mercenarySaves = MercenaryManager.Instance.MercenarySave;

            a_SaveData.PlayerControls = PlayerControls;

            return true;
        }

        [ContextMenu("LoadJsonData")]
        public void LoadDataAsJson()
        {
            if(FileManager.LoadFromFile(out var json))
            {
                SaveData sd = new SaveData();
                sd.LoadFromJson(json);

                LoadFromSaveData(sd);
            }
            else
            {
                // No save is found, new game
            }
        }
        
        public void LoadFromSaveData(SaveData a_SaveData)
        {
            //PlayerEquipments = a_SaveData.equippedItems;
            PlayerEquipmentsKeys = a_SaveData.equippedItemIndexs;

            PlayerLives = 3;
            Gold = 200;

            //IsSpearmasterDead = a_SaveData.IsSpearmasterDead;
            IsSpearmasterDead = false;

            Level = a_SaveData.Level;

            //for (int i = 0; i < a_SaveData.Mercenaries.Count; i++)
            //    MercenaryManager.Instance.Mercenaries[i].CurrentMercenary = a_SaveData.Mercenaries[i];

            if(a_SaveData.mercenarySaves != null)
                MercenaryManager.Instance.MercenarySave = a_SaveData.mercenarySaves;

            PlayerControls = a_SaveData.PlayerControls;
        }

        void OnApplicationQuit()
        {
            SaveDataAsJson();    
        }

#if UNITY_ANDROID && !UNITY_EDITOR
        void OnApplicationPause(bool pause)
        {
            if (pause)
            {
                SaveDataAsJson();
            }
        }
#endif

        public void ResetGameData()
        {

        }

        public void OnBeforeSerialize()
        {
            
        }

        public void OnAfterDeserialize()
        {
            
        }
    }

    [System.Serializable]
    public class SortManager
    {
        [SerializeField]
        public List<Unit> sortingOrder;

        public SortManager()
        {
            sortingOrder = new List<Unit>();
        }

        public void BringToFront(Unit unit)
        {
            /*sortingOrder.Remove(unit);
            sortingOrder.Add(unit);
            foreach(Unit u in sortingOrder)
            {
                ChangeSort(u);
            }*/
        }

        public void ChangePlayerSortOnly(Unit aggressor, Unit target)
        {
            if (aggressor.CompareTag(SpineControllerVersion.GameManager.PLAYER_TAG))
            {
                aggressor.GetComponentInChildren<MeshRenderer>().sortingOrder = 999;
            }
            else if (target.CompareTag(SpineControllerVersion.GameManager.PLAYER_TAG))
            {
                target.GetComponentInChildren<MeshRenderer>().sortingOrder = -1;
            }
        }

        // Newly initiated unit 
        public void AddToOrder(Unit unit)
        {
            sortingOrder.Add(unit);
            ChangeSort(unit);
        }

        // Dead units are thrown to the back, newly dead units will have higher priority on sorting order.
        private int deathNumber;
        public void RemoveFromOrder(Unit unit)
        {
            sortingOrder.Remove(unit);
            unit.GetComponentInChildren<MeshRenderer>().sortingOrder = -999 + deathNumber;
            deathNumber++;

            foreach (Unit u in sortingOrder)
            {
                ChangeSort(u);
            }
        }

        void ChangeSort(Unit unit)
        {
            int newOrder = sortingOrder.IndexOf(unit);
            unit.GetComponentInChildren<MeshRenderer>().sortingOrder = newOrder;
        }
    }
}