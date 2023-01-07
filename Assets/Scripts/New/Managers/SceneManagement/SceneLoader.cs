using SpineControllerVersion;
using System;
using System.Collections;
using System.Collections.Generic;
using Tymski;
using UnityEditor;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class SceneLoader : MonoBehaviour
{
    [Header("Canvases")]
    public GameObject MainMenuCanvas;
    [Space]
    public ShopPanel_V2.ShopPanel ShopCanvas;
    public Button OpenShopCanvas;

    [Header("Scenes")]
    public SceneReference MainMenu;
    
    public SceneReference TempLevel;
    public List<SceneReference> Levels;

    public delegate void OnLevelLoaded();
    public static OnLevelLoaded LevelLoaded;

    UnitHolder MainMenuPlayer;

    void Start()
    {
        MainMenuCanvas.gameObject.SetActive(true);

        SceneManager.sceneLoaded += OnSceneLoaded;
    }

    public void OpenMainMenu()
    {
        SceneManager.LoadScene(MainMenu);
    }

    public void FinishLevel()
    {
        OpenMainMenu();

        GameManager.Instance.Level++;
    }

    public void FinishGame()
    {
        OpenMainMenu();
    }

    public void NextLevel()
    {
        SceneManager.LoadScene(Levels[GameManager.Instance.Level]);
    }

    private void OnSceneLoaded(Scene scene, LoadSceneMode mode)
    {
        if(scene.name == "Main Menu")
        {
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
        }
        else
        {
            MainMenuCanvas.gameObject.SetActive(false);

            LevelLoaded();

            //LevelCanvas.SetActive(true);
        }
    }
}
