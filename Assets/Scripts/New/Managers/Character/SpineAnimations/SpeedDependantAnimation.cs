using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(menuName = "Spine Animation/Animation Info/Animation With Speed")]
[System.Serializable]
public class SpeedDependantAnimation : BasicAnimation
{
    public AnimationCurve speedCurve;
}
