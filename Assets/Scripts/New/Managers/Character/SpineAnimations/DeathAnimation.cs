using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(menuName = "Spine Animation/Animation Info/Death Animation")]
[System.Serializable]
public class DeathAnimation : BasicAnimation
{
    public HitRegion deathType;
    public AnimationClip bloodAnimation;
}
