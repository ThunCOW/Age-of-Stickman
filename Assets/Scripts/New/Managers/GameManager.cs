using Spine.Unity;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

namespace SpineControllerVersion
{
    public class GameManager : MonoBehaviour
    {
        public static GameManager Instance;

        [Header("Unit Assignments")]
        public Unit Player;
        public List<Unit> EnemyUnits = new List<Unit>();
        public List<Unit> PlayerUnits = new List<Unit>();

        public string ENEMY_TAG = "EnemyUnit";
        public string PLAYER_TAG = "PlayerUnit";

        [Header("Player Gold")]
        private int _Gold;
        public int Gold
        {
            get { return _Gold; }
            set 
            {
                _Gold = value;
                GoldText.text = value.ToString();
            }
        }
        public Text GoldText;

        [HideInInspector] public SortManager sortManager = new SortManager();

        private void Awake()
        {
            if (Instance == null)
            {
                Instance = this;
                DontDestroyOnLoad(this.gameObject);
            }
            else
                Destroy(this.gameObject);
        }

        // Start is called before the first frame update
        void Start()
        {
            Instance = this;
        }

        // Update is called once per frame
        void Update()
        {

        }

        void AddGold()
        {
            _Gold++;
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