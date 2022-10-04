using SpineControllerVersion;
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

    void Start()
    {
        ShopCanvas.SetActive(true);
        LevelCanvas.SetActive(false);
    }

    public void OpenMainMenu()
    {
        SceneManager.LoadScene(MainMenu);
        
        ShopCanvas.SetActive(true);
        LevelCanvas.SetActive(false);

        GameManager.Instance.EnemyUnits = new List<Unit>();
        GameManager.Instance.PlayerUnits = new List<Unit>();
        GameManager.Instance.sortManager = new SortManager();
        GameManager.Instance.Player = null;
    }

    public void OpenLevel()
    {
        SceneManager.LoadScene(TempLevel);

        ShopCanvas.SetActive(false);
        LevelCanvas.SetActive(true);
    }
}
