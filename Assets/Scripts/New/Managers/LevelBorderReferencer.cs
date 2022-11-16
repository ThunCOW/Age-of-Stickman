using SpineControllerVersion;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LevelBorderReferencer : MonoBehaviour
{
    void Awake()
    {
        GameManager.Instance.LevelBordersParent = gameObject;
    }
}
