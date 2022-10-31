using SpineControllerVersion;
using System;
using System.Collections;
using System.Collections.Generic;
using Tymski;
using UnityEditor;
using UnityEngine;
using UnityEngine.SceneManagement;

public class SceneLoader : MonoBehaviour
{
    public GameObject ShopCanvas;
    public GameObject LevelCanvas;

    public SceneReference MainMenu;
    
    public SceneReference TempLevel;
    public List<SceneReference> Levels;

    public delegate void OnLevelLoaded();
    public static OnLevelLoaded LevelLoaded;

    void Start()
    {
        ShopCanvas.SetActive(true);
        //LevelCanvas.SetActive(false);

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

    public void NextLevel()
    {
        SceneManager.LoadScene(Levels[GameManager.Instance.Level]);
    }

    private void OnSceneLoaded(Scene scene, LoadSceneMode mode)
    {
        if(scene.name == "Main Menu")
        {
            ShopCanvas.SetActive(true);
            //LevelCanvas.SetActive(false);

            GameManager.Instance.EnemyUnits = new List<Unit>();
            GameManager.Instance.AllyUnits = new List<Unit>();
            GameManager.Instance.sortManager = new SortManager();
            GameManager.Instance.Player = null;
        }
        else
        {
            ShopCanvas.SetActive(false);

            LevelLoaded();

            //LevelCanvas.SetActive(true);
        }
    }
}
