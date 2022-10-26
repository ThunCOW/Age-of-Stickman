using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SoundManager : MonoBehaviour
{
    public static SoundManager Instance;

    [SerializeField] private AudioSource musicSource, effectSource;

    void Awake()
    {
        if (Instance == null)
        {
            Instance = this;
            DontDestroyOnLoad(this.gameObject);
        }
        else
            Destroy(this.gameObject);
    }

    public void PlayEffect(AudioClip clip)
    {
        effectSource.PlayOneShot(clip);
    }

    public void PlayMusic(AudioClip clip)
    {
        musicSource.PlayOneShot(clip);
    }
}

[System.Serializable]
public class SoundEffect
{
    public List<AudioClip> soundEffectsList;

    public void PlayRandomSoundEffect()
    {
        if (soundEffectsList.Count == 0)
            return;

        int randomSoundEffect = Random.Range(0, soundEffectsList.Count);

        SoundManager.Instance.PlayEffect(soundEffectsList[randomSoundEffect]);
    }
}
