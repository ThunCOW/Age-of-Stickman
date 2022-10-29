using System.Collections.Generic;
using TMPro;
using UnityEngine;
using System;
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
            get { return _PlayerEquipmentsKeys; }
            set
            {
                _PlayerEquipmentsKeys = value;
                PlayerEquipments.Clear();
                foreach(int i in PlayerEquipmentsKeys)
                {
                    PlayerEquipments.Add(AllEquipments.Equipments[i]);
                }
            }
        }
        public List<Item> PlayerEquipments;

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





        [Header("_Gold Variables_")]
        [Space]
        public GameObject GoldPrefab;
        public List<AudioClip> CoinPickupSound;
        [SerializeField] private int _Gold;
        public int Gold
        {
            get { return _Gold; }
            private set 
            {
                _Gold = value;
                GoldText.text = value.ToString();
            }
        }
        public TMP_Text GoldText;





        [Header("_Temporary / Dumb Variables_")]
        // Too lazy to make a system fro secondary weapon so im just gonna check if first boss is dead and hide/show weapon lmao
        public bool IsSpearmasterDead;

        public int Level;






        void Awake()
        {
            for(int i = 0; i < AllEquipments.Equipments.Count; i++)
            {
                //AllEquipmentsDict.Add(i, AllEquipments[i]);
            }

            if (Instance == null)
            {
                Instance = this;
                DontDestroyOnLoad(this.gameObject);
            }
            else
                Destroy(this.gameObject);

            LoadDataAsJson();
        }

        // Start is called before the first frame update
        void Start()
        {
            
        }

        public void GoldChange(int Amount)
        {
            Gold += Amount;
        }

        public void PlayerLivesChange(int Amount)
        {
            PlayerLives += Amount;
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
            //a_SaveData.equippedItems = PlayerEquipments;
            PlayerEquipmentsKeys.Clear();
            foreach(Item item in PlayerEquipments)
            {
                int index = AllEquipments.Equipments.IndexOf(item);
                if (index == -1)
                    return false;

                PlayerEquipmentsKeys.Add(AllEquipments.Equipments.IndexOf(item));
                //if (SecondaryWeapon != null) PlayerEquipmentsKeys.Add(AllEquipments.Equipments.IndexOf(SecondaryWeapon));
            }
            a_SaveData.equippedItemIndexs = PlayerEquipmentsKeys;

            a_SaveData.PlayerLives = PlayerLives;
            a_SaveData.Gold = Gold;

            a_SaveData.IsSpearmasterDead = IsSpearmasterDead;

            a_SaveData.Level = Level;

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

            PlayerLives = a_SaveData.PlayerLives;
            Gold = a_SaveData.Gold;

            //IsSpearmasterDead = a_SaveData.IsSpearmasterDead;
            IsSpearmasterDead = false;

            //Level = a_SaveData.Level;
            Level = 7;
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