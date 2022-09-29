using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(menuName = "Spine Animation/Animation Info/Death By Dismembering Animation")]
public class DeathByDismemberAnimation : DeathAnimation
{
    public GameObject CutPart;
    public Vector2 spawnPosition;
}
