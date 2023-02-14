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
using static System.TimeZoneInfo;

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

    public GameObject StoryCanvas_EntrancePrefab;
    public GameObject StoryCanvas_SpearmasterPrefab;
    public GameObject StoryCanvas_SycthemasterPrefab;
    public GameObject StoryCanvas_DoubleAxePrefab;
    public GameObject StoryCanvas_EndingPrefab;
    public GameObject TransitionCanvas_Prefab;

    public GameObject BossDefeatedCanvas;
    
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

    public GameObject TransitionScenePrefab;

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

    public void _Button_ResChange(TMP_Text text)
    {
        Screen.SetResolution(1920, 1080, false);

        text.text = Screen.currentResolution.ToString();
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
            GameManager.Instance.isEndlessLevel = false;
            StartCoroutine(LoadMainMenu());
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
            GameManager.Instance.isEndlessLevel = true;
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

    public bool canContinue;
    public IEnumerator LoadMainMenu()
    {
        if (GameManager.Instance.Level == 0)
        {
            SoundManager.Instance.PlayMusicOnLoop(GameManager.Instance.StoryMusic, 0.3f);

            canContinue = false;

            GameObject transitionGO = Instantiate(TransitionCanvas_Prefab);
            Image[] transitionImg = transitionGO.transform.GetComponentsInChildren<Image>();
            

            GameObject storyCanvas_EntanceGO = Instantiate(StoryCanvas_EntrancePrefab);

            foreach(Image image in transitionImg )
            {
                StartCoroutine(ImageDisappearSlowly(image.gameObject, 1f, 0.65f, true));
            }

            yield return new WaitForSeconds(0.8f);

            foreach (Image image in transitionImg)
            {
                image.raycastTarget = false;
            }

            yield return new WaitUntil(() => canContinue);

            transitionGO = Instantiate(TransitionCanvas_Prefab);
            transitionImg = transitionGO.transform.GetComponentsInChildren<Image>();

            Destroy(storyCanvas_EntanceGO);

            foreach (Image image in transitionImg)
            {
                StartCoroutine(ImageDisappearSlowly(image.gameObject, 0.8f, 0.5f, true));
            }
            
            SoundManager.Instance.PlayMusicOnLoop(GameManager.Instance.Soundtrack_MainMenu, 0.3f);
            yield return new WaitForSeconds(0.4f);

            foreach (Image image in transitionImg)
            {
                image.raycastTarget = false;
            }
        }
        else if(GameManager.Instance.Level != 7 || GameManager.Instance.Level != 17 || GameManager.Instance.Level != 21 || GameManager.Instance.Level != 27)
        {
            SoundManager.Instance.PlayMusicOnLoop(GameManager.Instance.Soundtrack_MainMenu, 0.3f);
        }

        OpeningMenuCanvas.SetActive(false);
        MainMenuCanvas.SetActive(true);
        if (levelFinishedCheck)
        {
            OpenShopCanvas.onClick.Invoke();
            levelFinishedCheck = false;
        }

        SettingsButton.SetActive(true);
        SaveButton.interactable = true;
    }

    public void PlayStoryCanvas(float initialWait, string bossTag)
    {
        GameObject storyCanvas = null;
        switch (bossTag)
        {
            case GameManager.SPEARMASTER_TAG:
                storyCanvas = StoryCanvas_SpearmasterPrefab;
                break;
            case GameManager.SCYTHEMASTER_TAG:
                storyCanvas = StoryCanvas_SycthemasterPrefab;
                break;
            case GameManager.DOUBLEAXEDEMON_TAG:
                storyCanvas = StoryCanvas_DoubleAxePrefab;
                break;
            case GameManager.BIG_DEMON_TAG:
                storyCanvas = StoryCanvas_EndingPrefab;
                break;
            default:
                break;
        }
        StartCoroutine(StoryCanvas(initialWait, storyCanvas));
    }

    IEnumerator StoryCanvas(float initialWait, GameObject storyCanvas)
    {
        yield return new WaitForSeconds(initialWait);

        canContinue = false;

        // Spawn transition canvas
        GameObject transitionGO = Instantiate(TransitionCanvas_Prefab, gameObject.transform);
        Image[] transitionImg = transitionGO.transform.GetComponentsInChildren<Image>();
        Color c = Color.white;
        c.a = 0;
        // appears in x second
        foreach (Image image in transitionImg)
        {
            image.color = c;
            StartCoroutine(ImageAppear(image.gameObject, 2.5f));
        }
        SoundManager.Instance.TurnMusicDownSlowly(2.45f);

        yield return new WaitForSeconds(2.5f);

        // spawn story canvas behind
        GameObject storyCanvas_EntanceGO = Instantiate(storyCanvas);
        // transition canvas begin to disapppear
        foreach (Image image in transitionImg)
        {
            StartCoroutine(ImageDisappearSlowly(image.gameObject, 1f, 0.65f, true));
        }

        Debug.Log("Music Changed");
        SoundManager.Instance.PlayMusicOnLoop(GameManager.Instance.StoryMusic, 0.3f);

        yield return new WaitForSeconds(0.8f);

        foreach (Image image in transitionImg)
        {
            image.raycastTarget = false;
        }

        yield return new WaitUntil(() => canContinue);


        transitionGO = Instantiate(TransitionCanvas_Prefab, gameObject.transform);
        transitionImg = transitionGO.transform.GetComponentsInChildren<Image>();

        Destroy(storyCanvas_EntanceGO);

        foreach (Image image in transitionImg)
        {
            StartCoroutine(ImageDisappearSlowly(image.gameObject, 0.8f, 0.5f, true));
        }

        SoundManager.Instance.PlayMusicOnLoop(GameManager.Instance.Soundtrack_MainMenu, 0.3f);
        yield return new WaitForSeconds(0.45f);
        GameManager.Instance.SceneLoader.FinishLevel();

        foreach (Image image in transitionImg)
        {
            image.raycastTarget = false;
        }
    }

    public void PlayEnd()
    {
        StartCoroutine(End(6.5f, StoryCanvas_EndingPrefab));
    }
    IEnumerator End(float initialWait, GameObject storyCanvas)
    {
        yield return new WaitForSeconds(initialWait);

        canContinue = false;

        // Spawn transition canvas
        GameObject transitionGO = Instantiate(TransitionCanvas_Prefab, gameObject.transform);
        Image[] transitionImg = transitionGO.transform.GetComponentsInChildren<Image>();
        Color c = Color.white;
        c.a = 0;
        // appears in x second
        foreach (Image image in transitionImg)
        {
            image.color = c;
            StartCoroutine(ImageAppear(image.gameObject, 2.5f));
        }
        SoundManager.Instance.TurnMusicDownSlowly(2.45f);

        yield return new WaitForSeconds(2.5f);

        // spawn story canvas behind
        GameObject storyCanvas_EntanceGO = Instantiate(storyCanvas);
        // transition canvas begin to disapppear
        foreach (Image image in transitionImg)
        {
            StartCoroutine(ImageDisappearSlowly(image.gameObject, 1f, 0.65f, true));
        }

        Debug.Log("Music Changed");
        SoundManager.Instance.PlayMusicOnLoop(GameManager.Instance.StoryMusic, 0.3f);

        yield return new WaitForSeconds(0.8f);

        foreach (Image image in transitionImg)
        {
            image.raycastTarget = false;
        }

        yield return new WaitUntil(() => canContinue);

        transitionGO = Instantiate(TransitionCanvas_Prefab, gameObject.transform);
        transitionImg = transitionGO.transform.GetComponentsInChildren<Image>();

        Destroy(storyCanvas_EntanceGO);

        foreach (Image image in transitionImg)
        {
            StartCoroutine(ImageDisappearSlowly(image.gameObject, 0.8f, 0.5f, true));
        }

        foreach (Image image in transitionImg)
        {
            image.raycastTarget = false;
        }

        Ending.Instance.GameEnd();
    }
    public void TransitionScene()
    {
        StartCoroutine(Transition());
    }

    IEnumerator Transition()
    {
        GameObject transitionCanvas = Instantiate(TransitionScenePrefab, gameObject.transform);

        ImageAppear(transitionCanvas.transform.GetChild(0).gameObject, 1.5f);

        yield return new WaitForSeconds(2.3f);

        ImageDisappearSlowly(transitionCanvas.transform.GetChild(0).gameObject, 0.8f, 0, true);
    }

    IEnumerator ImageAppear(GameObject Image, float appearTime)
    {
        Image tempImage = Image.GetComponent<Image>();
        Color tempColor = tempImage.color;

        float count = 0;
        while (count < appearTime)
        {
            count += Time.deltaTime;

            float percentage = count / appearTime;

            tempColor.a = percentage;
            tempImage.color = tempColor;

            yield return new WaitForFixedUpdate();
        }
    }
    IEnumerator ImageDisappearSlowly(GameObject Image, float disappearTime = 1.5f, float stallTime = 0, bool destroyAfter = false)
    {
        yield return new WaitForSeconds(stallTime);

        Image tempImage = Image.GetComponent<Image>();
        Color tempColor = tempImage.color;

        float wait = (tempColor.a / 1) * disappearTime;                             // If image does not have maximum alpha, set time according to that
        while (wait > 0)
        {
            if (tempImage == null)
                break;
            wait -= Time.deltaTime;

            float percentage = wait / disappearTime;

            tempColor.a = percentage;
            tempImage.color = tempColor;

            yield return new WaitForFixedUpdate();
        }
    }
}
