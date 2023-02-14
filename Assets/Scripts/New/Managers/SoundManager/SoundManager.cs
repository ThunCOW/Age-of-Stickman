using SpineControllerVersion;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SoundManager : MonoBehaviour
{
    public static SoundManager Instance;

    private float MaxVolume;
    private int _MusicVolume;
    public int MusicVolume
    {
        get { return _MusicVolume; }
        set
        {
            _MusicVolume = value;

            musicSource.volume = ((float)_MusicVolume / (float)8) * MaxVolume;
        }
    }
    private int _SFXVolume;
    public int SFXVolume
    {
        get { return _SFXVolume; }
        set
        {
            _SFXVolume = value;

            effectSource.volume = ((float)_SFXVolume / (float)8) * 0.25f;
        }
    }

    
    [SerializeField] private AudioSource musicSource, effectSource;

    [Header("Singular Used Sounds")]
    public List<AudioClip> ShieldHitSound;
    public List<AudioClip> ShieldBigMaceHit;
    public List<AudioClip> ShieldAxeHit;
    public List<AudioClip> ShieldZweiHit;

    public List<AudioClip> DeathSFX;

    public List<AudioClip> SyctheSpin;
    public AudioClip SyctheEntrance;

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

    public void PlayMusicOnLoop(AudioClip clip, float maxVolume = 0.1f)
    {
        MaxVolume = maxVolume;
        MusicVolume = MusicVolume;

        musicSource.clip = clip;
        musicSource.Play();
    }

    public void PlayMusic(AudioClip clip)
    {
        musicSource.PlayOneShot(clip);
    }
    public void PlayBossMusic()
    {
        StartCoroutine(TurnMusicDownTimed(1));
    }

    public void TurnMusicDown()
    {
        //StartCoroutine(TurnMusicDownTimed());
    }

    public void TurnMusicDownSlowly(float x)
    {
        StartCoroutine(TurnMusicDownTimed(x));
    }
    IEnumerator TurnMusicDownTimed(float x)
    {
        float countDown = x;
        while (countDown > 0)
        {
            countDown -= Time.deltaTime;
            float currentMusicVol = ((float)_MusicVolume / (float)8) * MaxVolume;
            musicSource.volume = currentMusicVol * countDown / x;
            yield return new WaitForFixedUpdate();
        }

        PlayMusicOnLoop(GameManager.Instance.Soundtrack_Boss_1, 0.3f);
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
