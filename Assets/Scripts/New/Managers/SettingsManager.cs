using SpineControllerVersion;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class SettingsManager : MonoBehaviour
{
    public GameObject SettingsMenu;

    public GameObject PlayerControlsMenu;

    public List<Image> MusicVolumeBars;
    public List<Image> SFXVolumeBars;


    Color VolumeBarEmptyColor = Color.white;

    void Start()
    {
        VolumeBarEmptyColor.a = 0.18f;

        LoadSoundSettings();
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
    }

    public void CloseSettings()
    {
        Time.timeScale = 1;
    }
}