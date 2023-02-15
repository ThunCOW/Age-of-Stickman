using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Spine.Unity;
using UnityEngine.UI;
using TMPro;
using SpineControllerVersion;

public class HiringPanel : MonoBehaviour
{
    [SerializeField] MercenaryManager MercenaryManager;

    [Space]
    [SerializeField] Button NextButton;
    [SerializeField] Button PreviousButton;

    [Space]
    [SerializeField] List<UnitHolder> UnitPanel;
    [SerializeField] TMP_Text UnitPriceText;

    [SerializeField] TMP_Text UnitText;

    UnitHolder currentUnit;
    

    // Holds the currently viewed mercenary info, when button pressed to change unit it changes to next unit and then fills next unit panel while leaving current panel as it is
    Mercenary currentMercenary;

    // tempo, supposed to hold currently viewed race
    //UnitRace currentRace = UnitRace.Human;

    // speed unit cards move
    public int speed;

    // holds ref to which plus button was pressed
    MercenaryUnit targetedMercenaryUnit;
    
    void Awake()
    {
        UnitPanel[0].Init();
        UnitPanel[1].Init();

        UnitPanelDistance = Mathf.Abs(UnitPanel[0].rectTran.anchoredPosition.x - UnitPanel[1].rectTran.anchoredPosition.x);
        Debug.Log(UnitPanelDistance);
    }


    public void HireMercenary()
    {
        if(GameManager.Instance.Gold >= currentMercenary.UnitPrice)
        {
            AchievementSystem.Instance.UpdateAchievement(AchievementIds.TheMoreTheMerrier);
            //AchivementSO ach = AchievementSystem.GetAchievementSO(AchievementIds.TheMoreTheMerrier);
            //if (!(ach as AchievementByEvent).isUnlocked)
            //    (ach as AchievementByEvent).isUnlocked = true;

            if (targetedMercenaryUnit.CurrentMercenary == null)
            {
                targetedMercenaryUnit.CurrentMercenary = currentMercenary;

                GameManager.Instance.GoldChange(-currentMercenary.UnitPrice);

                SoundManager.Instance.PlayEffect(GameManager.Instance.CoinClicking);
            }
            else
            {
                if(targetedMercenaryUnit.CurrentMercenary != currentMercenary)
                {
                    targetedMercenaryUnit.CurrentMercenary = currentMercenary;

                    GameManager.Instance.GoldChange(-currentMercenary.UnitPrice);

                    SoundManager.Instance.PlayEffect(GameManager.Instance.CoinClicking);
                }
            }
        }
        else
        {
            GameManager.Instance.NotEnoughGold();
        }
    }






    // Move Through Mercenaries
    public void NextUnit()
    {
        NextButton.interactable = false;
        PreviousButton.interactable = false;

        currentMercenary = GetMercenary(true);

        UnitPriceText.text = currentMercenary.UnitPrice.ToString();
        
        currentUnit = PrepareNextUnit(false);

        List<Item> mercenaryItems = currentMercenary.Unit.GetComponent<EquipmentManager>().startingItems;

        currentUnit.ChangeUnitEquipments(currentUnit, mercenaryItems);

        currentUnit.UnitObject.GetComponent<SkeletonGraphic>().AnimationState.SetAnimation(0, currentMercenary.PanelIdleAnimation.SpineAnimationReference, true);

        MoveUnit(false);
    }

    public void PreviousUnit()
    {
        NextButton.interactable = false;
        PreviousButton.interactable = false;

        currentMercenary = GetMercenary(false);

        UnitPriceText.text = currentMercenary.UnitPrice.ToString();

        currentUnit = PrepareNextUnit(true);

        List<Item> mercenaryItems = currentMercenary.Unit.GetComponent<EquipmentManager>().startingItems;

        currentUnit.ChangeUnitEquipments(currentUnit, mercenaryItems);

        currentUnit.UnitObject.GetComponent<SkeletonGraphic>().AnimationState.SetAnimation(0, currentMercenary.PanelIdleAnimation.SpineAnimationReference, true);

        MoveUnit(true);
    }

    // Gets the next unit in MercenaryManager.dictAllMercenaries if isNextUnit set to true
    Mercenary GetMercenary(bool isNextUnit)
    {
        int lvl = 1;
        int currentMercIndex = 0;  // currently holds the index of current mercenary unit on panel, which found in if statements below, then next mercenary index is given further down below
        if(currentMercenary.UnitType == UnitType.Swordsman)
        {
            lvl = isNextUnit ? GameManager.Instance.SpearsmanUnitLevel : GameManager.Instance.ArcherUnitLevel;
            currentMercIndex = 0;
        }
        else if(currentMercenary.UnitType == UnitType.Spearsman)
        {
            lvl = isNextUnit ? GameManager.Instance.ArcherUnitLevel : GameManager.Instance.SwordsmanUnitLevel;
            currentMercIndex = 1;
        }
        else if(currentMercenary.UnitType == UnitType.Archer)
        {
            lvl = isNextUnit ? GameManager.Instance.SwordsmanUnitLevel : GameManager.Instance.SpearsmanUnitLevel;
            currentMercIndex = 2;
        }

        List<Mercenary> mercenaryList = MercenaryManager.dictAllMercenariesByLevel[lvl];

        int nextMercIndex = isNextUnit ? currentMercIndex + 1 : currentMercIndex - 1;

        if(isNextUnit)
        {
            if (nextMercIndex > mercenaryList.Count - 1)
                nextMercIndex = 0;
        }
        else
        {
            if (nextMercIndex < 0)
                nextMercIndex = mercenaryList.Count - 1;
        }

        return mercenaryList[nextMercIndex];
    }

    float UnitPanelDistance;
    UnitHolder PrepareNextUnit(bool isMovingRight)
    {
        UnitHolder nextUnit = UnitPanel[0] == currentUnit ? UnitPanel[1] : UnitPanel[0];

        if(isMovingRight)
        {
            if (nextUnit.rectTran.anchoredPosition.x >= currentUnit.rectTran.anchoredPosition.x)
                nextUnit.rectTran.anchoredPosition = new Vector3(nextUnit.rectTran.anchoredPosition.x - UnitPanelDistance * 2, nextUnit.rectTran.anchoredPosition.y);
        }
        else
        {
            if (nextUnit.rectTran.anchoredPosition.x <= currentUnit.rectTran.anchoredPosition.x)
                nextUnit.rectTran.anchoredPosition = new Vector3(nextUnit.rectTran.anchoredPosition.x + UnitPanelDistance * 2, nextUnit.rectTran.anchoredPosition.y);
        }

        nextUnit.UnitObject.SetActive(true);

        return nextUnit;
    }

    void MoveUnit(bool isMovingRight)
    {
        if(isMovingRight)
        {
            isActive = StartCoroutine(MoveHorizontal(UnitPanel[0].rectTran, (int)MoveDirection.right));
            StartCoroutine(MoveHorizontal(UnitPanel[1].rectTran, (int)MoveDirection.right));
        }
        else
        {
            isActive = StartCoroutine(MoveHorizontal(UnitPanel[0].rectTran, (int)MoveDirection.left));
            StartCoroutine(MoveHorizontal(UnitPanel[1].rectTran, (int)MoveDirection.left));
        }
    }

    Coroutine isActive;
    IEnumerator MoveHorizontal(RectTransform rectTransform, int direction)
    {
        float newPos = rectTransform.anchoredPosition.x + (direction) * UnitPanelDistance;

        while(rectTransform.anchoredPosition.x != newPos)
        {
            rectTransform.anchoredPosition = new Vector3(rectTransform.anchoredPosition.x + (direction * speed * Time.deltaTime), rectTransform.anchoredPosition.y);

            if(direction == 1)
            {
                if (rectTransform.anchoredPosition.x >= newPos)
                    rectTransform.anchoredPosition = new Vector3(newPos, rectTransform.anchoredPosition.y);
            }
            else
            {
                if (rectTransform.anchoredPosition.x <= newPos)
                    rectTransform.anchoredPosition = new Vector3(newPos, rectTransform.anchoredPosition.y);
            }

            yield return null;
        }

        // Next unit is the unit that has moved out of panel, had to disable GO because spear etc would stick out
        UnitHolder nextUnit = UnitPanel[0] == currentUnit ? UnitPanel[1] : UnitPanel[0];

        nextUnit.UnitObject.SetActive(false);

        NextButton.interactable = true;
        PreviousButton.interactable = true;

        UnitText.text = currentMercenary.UnitType.ToString();

        isActive = null;
    }









    


    void OnEnable()
    {
        // When HiringPanel is initiated it will populate second object in UnitObjects
        currentMercenary = (MercenaryManager.dictAllMercenariesByLevel[GameManager.Instance.SwordsmanUnitLevel])[0];

        UnitPriceText.text = currentMercenary.UnitPrice.ToString();

        currentUnit = UnitPanel[0];

        List<Item> mercenaryItems = currentMercenary.Unit.GetComponent<EquipmentManager>().startingItems;

        currentUnit.ChangeUnitEquipments(currentUnit, mercenaryItems);

        currentUnit.UnitObject.GetComponent<SkeletonGraphic>().AnimationState.SetAnimation(0, currentMercenary.PanelIdleAnimation.SpineAnimationReference, true);

        UnitText.text = currentMercenary.UnitType.ToString();
    }

    void OnDisable()
    {
        if(isActive != null)
        {
            StopAllCoroutines();
            isActive = null;
        }

        NextButton.interactable = true;
        PreviousButton.interactable = true;

        UnitPanel[0].UnitObject.transform.localPosition = UnitPanel[0].defaultLocalPosition;
        UnitPanel[1].UnitObject.transform.localPosition = UnitPanel[1].defaultLocalPosition;

        UnitPanel[0].UnitObject.SetActive(true);
        UnitPanel[1].UnitObject.SetActive(false);

        gameObject.SetActive(false);
    }

    public void EnableHiringPanel(MercenaryUnit mercenaryUnit)
    {
        if(gameObject.activeSelf)
        {
            if (mercenaryUnit == targetedMercenaryUnit)
            {
                gameObject.SetActive(false);
                return;
            }
            OnDisable();
            OnEnable();
        }
        else
            gameObject.SetActive(true);

        targetedMercenaryUnit = mercenaryUnit;
        
        transform.position = new Vector3(mercenaryUnit.transform.position.x, 
            transform.position.y, transform.position.z);
    }
}

// Unit Holder
[System.Serializable]
public class UnitHolder
{
    public GameObject UnitObject;
    [HideInInspector] public List<Item> equippedItems = new List<Item>();
    public Dictionary<ItemSlot, Item> dictEquippedItems = new Dictionary<ItemSlot, Item>();

    [HideInInspector] public Vector3 defaultLocalPosition;
    [HideInInspector] public RectTransform rectTran; 

    public void Init()
    {
        rectTran = (RectTransform)UnitObject.transform;
        defaultLocalPosition = rectTran.localPosition;

        dictEquippedItems.Add(ItemSlot.Head, null);
        dictEquippedItems.Add(ItemSlot.Leg, null);
        dictEquippedItems.Add(ItemSlot.MainHand, null);
        dictEquippedItems.Add(ItemSlot.Offhand, null);
        dictEquippedItems.Add(ItemSlot.Shoulder, null);
        dictEquippedItems.Add(ItemSlot.TwoHanded, null);
        dictEquippedItems.Add(ItemSlot.SecondaryWeapon, null);
    }

    // Setting Up Equipments
    public void ChangeUnitEquipments(UnitHolder unitHolder, List<Item> equippedItems)
    {
        SkeletonGraphic skeletonGraphic = unitHolder.UnitObject.GetComponent<SkeletonGraphic>();

        if (unitHolder.equippedItems != null && unitHolder.equippedItems != equippedItems)
        {
            ResetEquipments(unitHolder, skeletonGraphic);
        }

        for (int i = 0; i < equippedItems.Count; i++)
        {
            AddEquipment(unitHolder, skeletonGraphic, equippedItems[i].InitiateItem());
        }

        
        if (equippedItems == GameManager.Instance.PlayerEquipments)
        {
            // TODO: TEMP
            //if(GameManager.Instance.IsSpearmasterDead)
            //    skeletonGraphic.Skeleton.SetAttachment(dictEquippedItems[ItemSlot.MainHand].front[1].SlotName, dictEquippedItems[ItemSlot.MainHand].front[1].AttachmentName);
            //else
            //    skeletonGraphic.Skeleton.SetAttachment(dictEquippedItems[ItemSlot.MainHand].front[1].SlotName, null);
        }
    }

    public void ResetEquipments(UnitHolder Panel, SkeletonGraphic skeletonGraphic)
    {
        foreach (Item item in Panel.equippedItems)
        {
            SetAllAttachment(skeletonGraphic, Panel.dictEquippedItems[item.ItemSlot].front, true);
            SetAllAttachment(skeletonGraphic, Panel.dictEquippedItems[item.ItemSlot].side, true);
            SetAllAttachment(skeletonGraphic, Panel.dictEquippedItems[item.ItemSlot].back, true);
            SetAllAttachment(skeletonGraphic, Panel.dictEquippedItems[item.ItemSlot].back2, true);
            SetAllAttachment(skeletonGraphic, Panel.dictEquippedItems[item.ItemSlot].FacingCam, true);

            Panel.dictEquippedItems[item.ItemSlot] = null;
        }

        Panel.equippedItems = new List<Item>();
    }

    public void AddEquipment(UnitHolder Panel, SkeletonGraphic skeletonGraphic, Item item)
    {
        SetAllAttachment(skeletonGraphic, item.front);

        Panel.equippedItems.Add(item);
        Panel.dictEquippedItems[item.ItemSlot] = item;
    }

    public void SetAllAttachment(SkeletonGraphic skeletonGraphic, List<SpineAttachment> SpineAttachment, bool remove = false)
    {
        for (int i = 0; i < SpineAttachment.Count; i++)
        {
            if (remove)
                skeletonGraphic.Skeleton.SetAttachment(SpineAttachment[i].SlotName, null);
            else
                skeletonGraphic.Skeleton.SetAttachment(SpineAttachment[i].SlotName, SpineAttachment[i].AttachmentName);
        }
    }
}
