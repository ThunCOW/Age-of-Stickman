using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AchievementSave : MonoBehaviour
{
    public static AchievementSave Instance;

    public AchievementData achievementData = new AchievementData();
    public void Awake()
    {
        Instance = this;
        LoadFromJson();
    }

    public void SaveAchievements()
    {
        string achievement = JsonUtility.ToJson(achievementData);
        System.IO.File.WriteAllText(Application.persistentDataPath + "/AchievementData.dat", achievement);
    }

    public void LoadFromJson()
    {
        string filePath = System.IO.Path.Combine(Application.persistentDataPath, "AchievementData.dat");
        
        try
        {
            string data = System.IO.File.ReadAllText(filePath);
            achievementData = JsonUtility.FromJson<AchievementData>(data);
        }
        catch
        {
            SaveAchievements();
        }
    }

    public Achievement GetAchievementById(AchievementIds achievementIds)
    {
        foreach(Achievement ach in achievementData.AchievementList)
        {
            if (achievementIds == ach.id)
                return ach;
        }
        return null;
    }
}