using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[System.Serializable]
public class AchievementData
{
    public List<Achievement> AchievementList = new List<Achievement>();
}

[System.Serializable]
public class Achievement
{
    public AchievementIds id;
    public int currentAmount;
    public int requiredAmount;
}
