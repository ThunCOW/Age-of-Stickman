using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameOverScript : MonoBehaviour
{
    public Button GameOverButton;

    void Start()
    {
        StartCoroutine(GameOver());
    }

    public void _Button_GameOver()
    {
        SceneLoader.Instance.SaveAndOpenGameOpeningMenu();    
    }

    IEnumerator GameOver()
    {
        yield return new WaitForSeconds(1.5f);
        
        GameOverButton.interactable = true;
    }
}
