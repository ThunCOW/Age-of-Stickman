using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(menuName = "Spine Animation/Animation Info/Close Combat Animation")]
[System.Serializable]
public class CloseCombatAnimation : SpeedDependantAnimation
{
    public AttackType attackType;
    public AnimationMovementType animationMovementType;
    public int Damage;
    public float Reach;
    public float PushDistance;
    public HitRegion attackRegion;

    public float hitHeightPosiiton;
    public SoundEffect swooshSoundEffect;
    public SoundEffect hitSoundEffect;
}