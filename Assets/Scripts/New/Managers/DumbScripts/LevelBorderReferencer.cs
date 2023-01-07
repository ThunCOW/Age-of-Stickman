using SpineControllerVersion;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LevelBorderReferencer : MonoBehaviour
{
    public GameObject LeftWall;
    public GameObject RightWall;

    public float MapLength;

    void Awake()
    {
        GameManager.Instance.LevelBordersParent = gameObject;
    }
}
