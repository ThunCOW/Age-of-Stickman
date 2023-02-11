using SpineControllerVersion;
using System;
using System.Collections;
using System.Collections.Generic;
using TMPro;
using Tymski;
using UnityEditor;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class SceneLoader : MonoBehaviour
{
    public static SceneLoader Instance;

    [Header("Canvases")]
    public GameObject OpeningMenuCanvas;
    public GameObject MainMenuCanvas;
    public GameObject SettingsCanvas;
    public GameObject SettingsButton;
    public GameObject SettingsButtonEndless;
    public Button SaveButton;
    public Slider ProgressBar;
    
    [Space]
    public ShopPanel_V2.ShopPanel ShopCanvas;
    public Button OpenShopCanvas;

    [Space]
    public GameObject NewGameQ;

    [Header("Scenes")]
    public SceneReference MainMenu;
    public SceneReference GameOpeningA;
    
    public SceneReference TempLevel;
    public List<SceneReference> Levels;
    public SceneReference EndlessHumanLevel;
    public SceneReference EndlessElfLevel;
    public SceneReference EndlessDemonLevel;
    public SceneReference EndlessDemonLevel2;
    List<SceneReference> EndlessLevels = new List<SceneReference>();

    public delegate void OnLevelLoaded();
    public static OnLevelLoaded LevelLoaded;

    void Awake()
    {
        Instance = this;    
    }
    void Start()
    {
        //EndlessLevels.Add(EndlessHumanLevel);
        //EndlessLevels.Add(EndlessHumanLevel);
        //EndlessLevels.Add(EndlessElfLevel);
        //EndlessLevels.Add(EndlessElfLevel);
        EndlessLevels.Add(EndlessDemonLevel);
        EndlessLevels.Add(EndlessDemonLevel2);

        SceneManager.sceneLoaded += OnSceneLoaded;

        SoundManager.Instance.PlayMusicOnLoop(GameManager.Instance.Soundtrack_OpeningMenu, 0.5f);

        GameManager.Instance.LoadDataAsJson();
    }

    // OpeningMenu -> New Game
    public void StartNewGame()
    {
        if (FileManager.LoadFromFile(out var json))
        {
            NewGameQ.SetActive(true);
        }
        else
        {
            GameManager.Instance.CreateFreshSaveData();

            foreach(MercenaryUnit mu in MercenaryManager.Instance.Mercenaries)
            {
                mu.isUnlocked = false;
            }
            OpenMainMenu();
        }
    }
    // NewGameQ -> Yes
    public void ForceNewGame()
    {
        GameManager.Instance.CreateFreshSaveData();
        GameManager.Instance.LoadDataAsJson();

        GameManager.Instance.isGameOver = false;
        if (ShopPanel_V2.ShopPanel.Instance != null)
        {
            ShopPanel_V2.ShopPanel.Instance.SetStartingItems();
        }

        OpenMainMenu();
    }
    // OpeningMenu -> Continue
    public void OpenMainMenu()
    {
        GameManager.Instance.LoadDataAsJson();
        GameManager.Instance.mainMenuPlayer.ChangeUnitEquipments(GameManager.Instance.mainMenuPlayer, GameManager.Instance.PlayerEquipments);
        SceneManager.LoadScene(MainMenu);
    }
    public void StartEndlessGame()
    {
        SceneManager.LoadScene(EndlessLevels[UnityEngine.Random.Range(0, EndlessLevels.Count)]);
    }

    bool levelFinishedCheck;
    public void FinishLevel()
    {
        SceneManager.LoadScene(MainMenu);
        levelFinishedCheck = true;

        //MainMenuCanvas.gameObject.SetActive(true);

        //LevelCanvas.SetActive(false);

        GameManager.Instance.EnemyUnits = new List<Unit>();
        GameManager.Instance.AllyUnits = new List<Unit>();
        GameManager.Instance.sortManager = new SortManager();
        GameManager.Instance.Player = null;

        GameManager.Instance.GoldGained += 15;
        GameManager.Instance.GoldGained = 0;

        // MercenaryManager
        MercenaryManager.Instance.MercenarySpawns.Clear();

        GameManager.Instance.Level++;
        
        DayText = Instantiate(DayTextPrefab, MainMenuCanvas.transform);
        
        DayText.transform.GetChild(1).GetComponent<TMP_Text>().text = (GameManager.Instance.Level + 1).ToString();

        StartCoroutine(GameManager.Instance.TextAppearDisappearSlowly(DayText.transform.GetChild(0).gameObject, 2f, 4.5f, 0, 2, 4.5f));
        StartCoroutine(GameManager.Instance.TextAppearDisappearSlowly(DayText.transform.GetChild(1).gameObject, 2f, 4.5f, 0, 2, 4.5f));
        DayCycleManager.Instance.MoveCycle();
    }

    public void FinishGame()
    {
        SceneManager.LoadScene(GameOpeningA);
    }

    // Settings -> Back To Menu button
    public void SaveAndOpenGameOpeningMenu()
    {
        GameManager.Instance.SaveGame();

        SceneManager.LoadScene(GameOpeningA);
    }

    // MainMenu -> Next button
    public void NextLevel()
    {
        SceneManager.LoadScene(Levels[GameManager.Instance.Level]);

        LevelLoaded();
    }

    [SerializeField] private GameObject DayTextPrefab;
    private GameObject DayText;
    private void OnSceneLoaded(Scene scene, LoadSceneMode mode)
    {
        if(scene.name == "Main Menu A")                     // Story Mode Menu
        {
            OpeningMenuCanvas.SetActive(false);
            MainMenuCanvas.SetActive(true);
            if (levelFinishedCheck)
            {
                OpenShopCanvas.onClick.Invoke();
                levelFinishedCheck = false;
            }
            
            SettingsButton.SetActive(true);
            SaveButton.interactable = true;

            SoundManager.Instance.PlayMusicOnLoop(GameManager.Instance.Soundtrack_MainMenu, 0.3f);
        }
        else if(scene.name == "Game Opening A")             // Opening Menu
        {
            OpeningMenuCanvas.SetActive(true);
            MainMenuCanvas.SetActive(false);
            SettingsCanvas.SetActive(false);
            SettingsButton.SetActive(false);
            SettingsButtonEndless.SetActive(false);

            Time.timeScale = 1;

            SoundManager.Instance.PlayMusicOnLoop(GameManager.Instance.Soundtrack_OpeningMenu, 0.5f);
        }
        else if(scene.name.Contains("Endless"))
        {
            OpeningMenuCanvas.SetActive(false);
            SettingsButtonEndless.SetActive(true);
            SaveButton.interactable = false;
            GameManager.Instance.EndlessKillCount = 0;
            GameManager.Instance.EndlessLive();

            SoundManager.Instance.PlayMusicOnLoop(GameManager.Instance.Soundtrack_War_1, 0.2f);
        }
        else                                                // Level 
        {
            MainMenuCanvas.SetActive(false);
            SettingsCanvas.SetActive(false);
            SettingsButton.SetActive(true);
            GameManager.Instance.EndlessKillCount = -999;

            SoundManager.Instance.PlayMusicOnLoop(GameManager.Instance.Soundtrack_War_1, 0.2f);
        }
    }
}
