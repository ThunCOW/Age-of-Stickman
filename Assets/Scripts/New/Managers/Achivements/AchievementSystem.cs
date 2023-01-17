using SpineControllerVersion;
using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class AchievementSystem : MonoBehaviour
{
    [SerializeField] TMP_Text AchievementTitleText;
    [SerializeField] TMP_Text AchievementDescriptionText;

    [Space]
    public List<AchievementItem> AchievementItems;

    [SerializeField] bool getAchievementItems;
    [SerializeField] bool populateAchievementItems;
    private void OnValidate()
    {
        if(getAchievementItems)
        {
            AchievementItems.Clear();
            
            foreach(AchievementItem item in transform.GetComponentsInChildren<AchievementItem>())
            {
                AchievementItems.Add(item);
            }
            getAchievementItems = false;
        }

        if(populateAchievementItems)
        {
            int index = 0;
            foreach(AchivementSO achievementSO in GameManager.Instance.AchievementsInfo)
            {
                if(achievementSO is AchievementByEvent)
                    PopulateAchievementItem(AchievementItems[index], achievementSO as AchievementByEvent);
                else
                    PopulateAchievementItem(AchievementItems[index], achievementSO as AchievementByCounter);
                
                index++;
            }
            populateAchievementItems = false;
        }
    }
   
    void PopulateAchievementItem(AchievementItem achievementItem, AchievementByCounter achievementSO)
    {
        achievementItem.Achievement.id = achievementSO.Achievement.id;
        achievementItem.Achievement.title = achievementSO.Achievement.title;
        achievementItem.Achievement.texture = achievementSO.Achievement.texture;

        achievementItem.Achievement.description = "(" + achievementSO.currentAmount + "/" + achievementSO.requiredAmount + ") " + achievementSO.Achievement.description;
        
        achievementItem.unlocked = achievementSO.currentAmount == achievementSO.requiredAmount;

        achievementItem.RefreshView();
    }

    void PopulateAchievementItem(AchievementItem achievementItem, AchievementByEvent achievementSO)
    {
        achievementItem.Achievement.id = achievementSO.Achievement.id;
        achievementItem.Achievement.title = achievementSO.Achievement.title;
        achievementItem.Achievement.description = achievementSO.Achievement.description;
        achievementItem.Achievement.texture = achievementSO.Achievement.texture;
        achievementItem.unlocked = achievementSO.isUnlocked;

        achievementItem.RefreshView();
    }

    public void ShowDescripton(AchievementItem achievementItem)
    {
        AchievementTitleText.enabled = true;
        AchievementDescriptionText.enabled = true;

        AchievementTitleText.text = achievementItem.Achievement.title;
        AchievementDescriptionText.text = achievementItem.Achievement.description;
    }

    void OnEnable()
    {
        AchievementTitleText.enabled = false;
        AchievementDescriptionText.enabled = false;

        AchievementItems[0].GetComponent<Button>().Select();
        ShowDescripton(AchievementItems[0]);

        int index = 0;
        foreach (AchivementSO achievementSO in GameManager.Instance.AchievementsInfo)
        {
            if (achievementSO is AchievementByEvent)
                PopulateAchievementItem(AchievementItems[index], achievementSO as AchievementByEvent);
            else
                PopulateAchievementItem(AchievementItems[index], achievementSO as AchievementByCounter);

            index++;
        }
    }

    public static AchivementSO GetAchievementSO(AchievementIds achievementId)
    {
        foreach(AchivementSO ach in GameManager.Instance.AchievementsInfo)
        {
            if (ach.Achievement.id == achievementId)
                return ach;
        }
        return null;
    }
}

public enum AchievementIds
{
    TasteOfBlood,
    TheMoreTheMerrier,
    ToHellAndBack,
    Bloodbath,
    Spearmaster,
    FallenKing,
    TheGolliath,
    Swordhood,
}