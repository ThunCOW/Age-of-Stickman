using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class AchivementSO : ScriptableObject
{
    public AchievementObject Achievement;
}

[System.Serializable]
public class AchievementObject
{
    public AchievementIds id;
    public string title;
    public string description;
    public Sprite texture;
}