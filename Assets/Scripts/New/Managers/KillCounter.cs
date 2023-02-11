using SpineControllerVersion;
using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class KillCounter : MonoBehaviour
{
    public static KillCounter Instance;

    public TMP_Text KillCount_Text;

    void Awake()
    {
        Instance = this;
    }

    public void Kill()
    {
        if (KillCount_Text != null)
            KillCount_Text.text = GameManager.Instance.EndlessKillCount.ToString();
    }

    void OnDestroy()
    {
        Instance = null;    
    }
}
