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

    UnitHolder MainMenuPlayer;

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

        SoundManager.Instance.PlayMusicOnLoop(GameManager.Instance.Soundtrack_OpeningMenu);
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

            OpenMainMenu();

            SoundManager.Instance.PlayMusicOnLoop(GameManager.Instance.Soundtrack_MainMenu);
        }
    }
    // NewGameQ -> Yes
    public void ForceNewGame()
    {
        GameManager.Instance.CreateFreshSaveData();

        OpenMainMenu();

        SoundManager.Instance.PlayMusicOnLoop(GameManager.Instance.Soundtrack_MainMenu);
    }
    // OpeningMenu -> Continue
    public void OpenMainMenu()
    {
        GameManager.Instance.LoadDataAsJson();

        SceneManager.LoadScene(MainMenu);

        SoundManager.Instance.PlayMusicOnLoop(GameManager.Instance.Soundtrack_MainMenu);
    }
    public void StartEndlessGame()
    {
        SceneManager.LoadScene(EndlessLevels[UnityEngine.Random.Range(0, EndlessLevels.Count)]);

        OpeningMenuCanvas.SetActive(false);
    }

    public void FinishLevel()
    {
        SceneManager.LoadScene(MainMenu);


        MainMenuCanvas.gameObject.SetActive(true);
        OpenShopCanvas.onClick.Invoke();

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
        if(scene.name == "Main Menu A")
        {
            OpeningMenuCanvas.SetActive(false);
            MainMenuCanvas.SetActive(true);
            SettingsButton.SetActive(true);
        }
        else if(scene.name == "Game Opening A")
        {
            OpeningMenuCanvas.SetActive(true);
            MainMenuCanvas.SetActive(false);
            SettingsCanvas.SetActive(false);
            SettingsButton.SetActive(false);

            Time.timeScale = 1;
        }
        else
        {
            MainMenuCanvas.SetActive(false);
            SettingsCanvas.SetActive(false);
        }
    }
}
