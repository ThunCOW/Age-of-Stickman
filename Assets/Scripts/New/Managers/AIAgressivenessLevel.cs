using StickmanChampion;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(menuName = ("ScriptableObjects / AI_Agressiveness"))]
public class AIAgressivenessLevel : ScriptableObject
{
    public List<AIVariables> aiVariableList;
}
