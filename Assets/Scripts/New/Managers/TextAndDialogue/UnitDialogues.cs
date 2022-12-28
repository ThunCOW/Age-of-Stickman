using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UnitDialogues : MonoBehaviour
{
    public List<Dialogue> dialogueList;

}

[System.Serializable]
public class Dialogue
{
    public string Context;
}