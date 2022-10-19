using Spine.Unity;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

namespace SpineControllerVersion
{
    public class GameManager : MonoBehaviour, ISaveableJson, ISerializationCallbackReceiver
    {
        public static GameManager Instance;

        [Header("Unit Assignments")]
        public List<Unit> EnemyUnits = new List<Unit>();
        public List<Unit> PlayerUnits = new List<Unit>();

        public string ENEMY_TAG = "EnemyUnit";
        public string PLAYER_TAG = "PlayerUnit";
        public string GOLD_TAG = "Gold";

        [Header("Player Data")]
        public Unit Player;
        [SerializeField] private List<Item> AllEquipments;
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
                    PlayerEquipments.Add(AllEquipments[i]);
                }
            }
        }
        public List<Item> PlayerEquipments;

        [SerializeField] private int _PlayerLives;
        public int PlayerLives
        {
            get { return _PlayerLives; }
            private set
            {
                _PlayerLives = value;
            }
        }

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

        [HideInInspector] public SortManager sortManager = new SortManager();

        void ChangeEquipment(Item newEquipment)
        {

        }
        private void Awake()
        {
            for(int i = 0; i < AllEquipments.Count; i++)
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
            Instance = this;
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
                int index = AllEquipments.IndexOf(item);
                if (index == -1)
                    return false;

                PlayerEquipmentsKeys.Add(AllEquipments.IndexOf(item));
            }
            a_SaveData.equippedItemIndexs = PlayerEquipmentsKeys;

            a_SaveData.PlayerLives = PlayerLives;
            a_SaveData.Gold = Gold;

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
            if (aggressor.CompareTag(SpineControllerVersion.GameManager.Instance.PLAYER_TAG))
            {
                aggressor.GetComponentInChildren<MeshRenderer>().sortingOrder = 999;
            }
            else if (target.CompareTag(SpineControllerVersion.GameManager.Instance.PLAYER_TAG))
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