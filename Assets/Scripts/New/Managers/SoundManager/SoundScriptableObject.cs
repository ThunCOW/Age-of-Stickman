using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(menuName = "SoundSO")]
public class SoundScriptableObject : ScriptableObject
{
    public string Name;
    public SoundEffect swooshSoundEffect;
    public SoundEffect hitSoundEffect;
}
