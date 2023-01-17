using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class AchievementItem : MonoBehaviour
{
    [SerializeField] Image AchievementIcon;
    [SerializeField] Image LockIcon;

    public bool unlocked;
    public AchievementObject Achievement;

    public void RefreshView()
    {
        AchievementIcon.sprite = Achievement.texture;

        LockIcon.enabled = !unlocked;
    }
}
