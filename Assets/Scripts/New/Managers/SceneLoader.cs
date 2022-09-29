using System.Collections;
using System.Collections.Generic;
using Tymski;
using UnityEditor;
using UnityEngine;
using UnityEngine.SceneManagement;

public class SceneLoader : MonoBehaviour
{
    public SceneReference MainMenu;
    
    public SceneReference TempLevel;

    public void OpenMainMenu()
    {
        SceneManager.LoadScene(MainMenu);
    }

    public void OpenLevel()
    {
        SceneManager.LoadScene(TempLevel);
    }
}
