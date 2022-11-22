using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(menuName = "Items/BodyPartSO")]
public class BodyPartSO : ScriptableObject
{
    public List<BodyPartByRace> BodyPartByRace;
}

[System.Serializable]
public class BodyPartByRace
{
    public UnitRace UnitRace;
    public List<BodyPart> BodyParts;
}

[System.Serializable]
public class BodyPart
{
    public BodyPartType BodyPartType;
    public GameObject BodyPartPrefab;
}