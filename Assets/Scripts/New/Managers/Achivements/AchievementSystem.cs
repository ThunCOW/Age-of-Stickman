using SpineControllerVersion;
using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class AchievementSystem : MonoBehaviour
{
    public static AchievementSystem Instance;

    public GameObject UnlockAchievementPrefab;

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
    private void Awake()
    {
        Instance = this;    
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

    void PopulateAchievementItem(AchievementItem achievementItem, AchievementByEvent achievementSO, Achievement achievement)
    {
        achievementItem.Achievement.id = achievementSO.Achievement.id;
        achievementItem.Achievement.title = achievementSO.Achievement.title;
        achievementItem.Achievement.description = achievementSO.Achievement.description;
        achievementItem.Achievement.texture = achievementSO.Achievement.texture;
        achievementItem.unlocked = achievement.currentAmount == 1 ? true : false;

        achievementItem.RefreshView();
    }

    void PopulateAchievementItem(AchievementItem achievementItem, AchievementByCounter achievementSO, Achievement achievement)
    {
        achievementItem.Achievement.id = achievementSO.Achievement.id;
        achievementItem.Achievement.title = achievementSO.Achievement.title;
        achievementItem.Achievement.texture = achievementSO.Achievement.texture;

        achievementItem.Achievement.description = "(" + achievement.currentAmount + "/" + achievement.requiredAmount + ") " + achievementSO.Achievement.description;

        achievementItem.unlocked = achievement.currentAmount == achievement.requiredAmount;

        achievementItem.RefreshView();
    }

    public void ShowDescripton(AchievementItem achievementItem)
    {
        AchievementTitleText.enabled = true;
        AchievementDescriptionText.enabled = true;

        AchievementTitleText.text = achievementItem.Achievement.title;
        AchievementDescriptionText.text = achievementItem.Achievement.description;
    }

    public void _Button_ShowAchievements()
    {
        AchievementTitleText.enabled = false;
        AchievementDescriptionText.enabled = false;

        AchievementSave.Instance.LoadFromJson();

        int index = 0;
        foreach (AchivementSO achievementSO in GameManager.Instance.AchievementsInfo)
        {
            if (achievementSO is AchievementByEvent)
                PopulateAchievementItem(AchievementItems[index], achievementSO as AchievementByEvent, AchievementSave.Instance.achievementData.AchievementList[index]);
            else
                PopulateAchievementItem(AchievementItems[index], achievementSO as AchievementByCounter, AchievementSave.Instance.achievementData.AchievementList[index]);

            index++;
        }

        AchievementItems[0].GetComponent<Button>().Select();
        ShowDescripton(AchievementItems[0]);
    }

    public void UpdateAchievement(AchievementIds achievementIds)
    {
        Achievement ach = AchievementSave.Instance.GetAchievementById(achievementIds);
        if(ach.requiredAmount == -1)
        {
            if(ach.currentAmount == 0)
            {
                ach.currentAmount = 1;
                AchievementSave.Instance.SaveAchievements();
                UnlockAch(achievementIds);
            }
            // else already unlocked
        }
        else if(ach.requiredAmount > 0)
        {
            ach.currentAmount = ach.currentAmount <= ach.requiredAmount ? ach.currentAmount + 1 : ach.currentAmount;
            if(ach.currentAmount == ach.requiredAmount)
            {
                ach.currentAmount = ach.requiredAmount;
                AchievementSave.Instance.SaveAchievements();
                UnlockAch(achievementIds);
            }
            else
            {
                ach.currentAmount = 100;
                // already unlocked
            }
        }
    }
    private void UnlockAch(AchievementIds achievementIds)
    {
        AchivementSO achSO = GetAchievementSO(achievementIds);

        GameObject go = Instantiate(UnlockAchievementPrefab, transform.GetChild(0));
        AchUnlock achUnlock = go.GetComponent<AchUnlock>();
        achUnlock.Ach_Title.text = achSO.Achievement.title;
        achUnlock.Ach_Img.sprite = achSO.Achievement.texture;
        achUnlock.Ach_Img.SetNativeSize();
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