using SpineControllerVersion;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;

public class SettingsManager : MonoBehaviour
{
    public static SettingsManager Instance;

    public GameObject SettingsMenu;

    public GameObject ChangeControlMenu;
    public GameObject KeyboardControlsMenu;
    
    //
    public GameObject NextLevelButton;
    public GameObject DaysPanel;
    public GameObject PlayerLivesPanel;
    //

    public List<Image> MusicVolumeBars;
    public List<Image> SFXVolumeBars;


    Color VolumeBarEmptyColor = Color.white;

    void Start()
    {
        Instance = this;

        VolumeBarEmptyColor.a = 0.18f;
    }

    public void LoadSoundSettings()
    {
        int i = 0;
        for(; i < SoundManager.Instance.MusicVolume; i++)
        {
            MusicVolumeBars[i].color = Color.white;
        }
        for(; i < MusicVolumeBars.Count; i++)
        {
            MusicVolumeBars[i].color = VolumeBarEmptyColor;
        }

        i = 0;
        for(; i < SoundManager.Instance.SFXVolume; i++)
        {
            SFXVolumeBars[i].color = Color.white;
        }
        for(; i < SFXVolumeBars.Count; i++)
        {
            SFXVolumeBars[i].color = VolumeBarEmptyColor;
        }
    }

    public void MusicVolumeChange(int value)
    {
        SoundManager.Instance.MusicVolume += value;

        if (SoundManager.Instance.MusicVolume < 0)
            SoundManager.Instance.MusicVolume = 0;
        else if (SoundManager.Instance.MusicVolume > MusicVolumeBars.Count)
            SoundManager.Instance.MusicVolume = MusicVolumeBars.Count;

        if (value == 1)
            MusicVolumeBars[SoundManager.Instance.MusicVolume - 1].color = Color.white;
        else
            MusicVolumeBars[SoundManager.Instance.MusicVolume].color = VolumeBarEmptyColor;
    }

    public void SFXVolumeChange(int value)
    {
        SoundManager.Instance.SFXVolume += value;

        if (SoundManager.Instance.SFXVolume < 0)
            SoundManager.Instance.SFXVolume = 0;
        else if (SoundManager.Instance.SFXVolume > SFXVolumeBars.Count)
            SoundManager.Instance.SFXVolume = SFXVolumeBars.Count;

        if(value == 1)
            SFXVolumeBars[SoundManager.Instance.SFXVolume - 1].color = Color.white;
        else
            SFXVolumeBars[SoundManager.Instance.SFXVolume].color = VolumeBarEmptyColor;
    }

    public void PlayerArrowControls()
    {
        GameManager.Instance.PlayerControls = PlayerControls.ArrowControls;
    }

    public void PlayerJoystickControls()
    {
        GameManager.Instance.PlayerControls = PlayerControls.JoystickControls;
    }

    public void OpenSettings()
    {
        Time.timeScale = 0;

        LoadSoundSettings();

        if(GameManager.Instance.Player != null)
        {
            PlayerController temp = GameManager.Instance.Player.unitController as PlayerController;
            foreach(Button b in temp.ControlButtons)
            {
                b.interactable = false;
                b.GetComponent<EventTrigger>().enabled = false;
            }
            foreach(Image img in temp.JoystickImages)
            {
                img.raycastTarget = false;
            }
        }
    }

    public void OpenChangeControlMenu()
    {
        Time.timeScale = 0;

        if(Application.platform == RuntimePlatform.WindowsEditor || Application.platform == RuntimePlatform.WebGLPlayer || Application.platform == RuntimePlatform.WindowsPlayer)
        {
            KeyboardControlsMenu.SetActive(true);
            StartCoroutine(KeyboardControlsMenuClose());
        }
        else
        {
            ChangeControlMenu.SetActive(true);

            if(GameManager.Instance.Player != null)
            {
                ChangeControlMenu.transform.GetChild(0).gameObject.SetActive(true);
                ChangeControlMenu.transform.GetChild(1).gameObject.SetActive(false);
            }
            else
            {
                ChangeControlMenu.transform.GetChild(0).gameObject.SetActive(false);
                ChangeControlMenu.transform.GetChild(1).gameObject.SetActive(true);
            }
        }
    }

    IEnumerator KeyboardControlsMenuClose()
    {
        while(true)
        {
            if(Input.GetKeyDown(KeyCode.Escape) || Input.GetKeyDown(KeyCode.A) || Input.GetKeyDown(KeyCode.D))
            {
                KeyboardControlsMenu.SetActive(false);

                NextLevelButton.SetActive(true);
                DaysPanel.SetActive(true);
                PlayerLivesPanel.SetActive(true);

                Time.timeScale = 1;
                break;
            }
            yield return null;
        }
    }

    public void CloseSettings()
    {
        Time.timeScale = 1;

        if(GameManager.Instance.Player != null)
        {
            PlayerController temp = GameManager.Instance.Player.unitController as PlayerController;
            foreach (Button b in temp.ControlButtons)
            {
                b.interactable = true;
                b.GetComponent<EventTrigger>().enabled = true;
            }
            foreach (Image img in temp.JoystickImages)
            {
                img.raycastTarget = true;
            }
        }
    }
}