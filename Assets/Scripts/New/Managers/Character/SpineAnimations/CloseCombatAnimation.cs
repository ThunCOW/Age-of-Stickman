using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(menuName = "Spine Animation/Animation Info/Close Combat Animation")]
[System.Serializable]
public class CloseCombatAnimation : SpeedDependantAnimation
{
    public AttackType attackType;
    public AnimationMovementType animationMovementType;
    public float DamageMultiplierMax;
    public float Reach;
    public float MinDistanceLimit;                          // If unit is closer than min distance, it cannot use this action
    public float PushDistance;
    public HitRegion attackRegion;

    public float hitHeightPosiiton;
    public SoundScriptableObject SoundObject;
    //public SoundEffect swooshSoundEffect;
    //public SoundEffect hitSoundEffect;
}