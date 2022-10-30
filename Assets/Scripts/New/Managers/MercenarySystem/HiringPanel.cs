using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Spine.Unity;
using UnityEngine.UI;
using TMPro;

public class HiringPanel : MonoBehaviour
{
    [SerializeField] MercenaryManager MercenaryManager;

    [Space]
    [SerializeField] Button NextButton;
    [SerializeField] Button PreviousButton;

    [Space]
    [SerializeField] List<UnitHolder> UnitPanel;

    [SerializeField] TMP_Text UnitText;

    UnitHolder currentUnit;

    // Holds the currently viewed mercenary info, when button pressed to change unit it changes to next unit and then fills next unit panel while leaving current panel as it is
    Mercenary currentMercenary;

    // tempo, supposed to hold currently viewed race
    UnitRace currentRace = UnitRace.Human;

    public int speed;
    // Start is called before the first frame update
    void Start()
    {
        // When HiringPanel is initiated it will populate second object in UnitObjects
        currentMercenary = (MercenaryManager.dictAllMercenaries[currentRace])[0];

        List<Item> mercenaryItems = currentMercenary.Unit.GetComponent<EquipmentManager>().startingItems;

        currentUnit = UnitPanel[0];

        ChangeUnitEquipments(currentUnit, mercenaryItems);

        currentUnit.UnitObject.GetComponent<SkeletonGraphic>().AnimationState.SetAnimation(0, currentMercenary.UnitIdleAnimation.SpineAnimationReference, false);
    }

    public void NextUnit()
    {
        NextButton.interactable = false;
        PreviousButton.interactable = false;

        currentMercenary = GetMercenary(true);

        currentUnit = PrepareNextUnit(false);

        List<Item> mercenaryItems = currentMercenary.Unit.GetComponent<EquipmentManager>().startingItems;

        ChangeUnitEquipments(currentUnit, mercenaryItems);

        currentUnit.UnitObject.GetComponent<SkeletonGraphic>().AnimationState.SetAnimation(0, currentMercenary.UnitIdleAnimation.SpineAnimationReference, false);

        MoveUnit(false);
    }

    public void PreviousUnit()
    {
        NextButton.interactable = false;
        PreviousButton.interactable = false;

        currentMercenary = GetMercenary(false);

        currentUnit = PrepareNextUnit(true);

        List<Item> mercenaryItems = currentMercenary.Unit.GetComponent<EquipmentManager>().startingItems;

        ChangeUnitEquipments(currentUnit, mercenaryItems);

        currentUnit.UnitObject.GetComponent<SkeletonGraphic>().AnimationState.SetAnimation(0, currentMercenary.UnitIdleAnimation.SpineAnimationReference, false);

        MoveUnit(true);
    }

    // Gets the next unit in MercenaryManager.dictAllMercenaries if isNextUnit set to true
    Mercenary GetMercenary(bool isNextUnit)
    {
        List<Mercenary> mercenaryList = MercenaryManager.dictAllMercenaries[currentRace];

        int nextMercIndex = mercenaryList.IndexOf(currentMercenary);
        nextMercIndex = isNextUnit ? nextMercIndex + 1 : nextMercIndex - 1;

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

    UnitHolder PrepareNextUnit(bool isMovingRight)
    {
        UnitHolder nextUnit = UnitPanel[0] == currentUnit ? UnitPanel[1] : UnitPanel[0];

        if(isMovingRight)
        {
            if (nextUnit.UnitObject.transform.position.x >= currentUnit.UnitObject.transform.position.x)
                nextUnit.UnitObject.transform.position = new Vector3(nextUnit.UnitObject.transform.position.x - 253 * 2, nextUnit.UnitObject.transform.position.y, nextUnit.UnitObject.transform.position.z);
        }
        else
        {
            if (nextUnit.UnitObject.transform.position.x <= currentUnit.UnitObject.transform.position.x)
                nextUnit.UnitObject.transform.position = new Vector3(nextUnit.UnitObject.transform.position.x + 253 * 2, nextUnit.UnitObject.transform.position.y, nextUnit.UnitObject.transform.position.z);
        }

        nextUnit.UnitObject.SetActive(true);

        return nextUnit;
    }

    void MoveUnit(bool isMovingRight)
    {
        if(isMovingRight)
        {
            StartCoroutine(MoveHorizontal(UnitPanel[0].UnitObject, (int)MoveDirection.right));
            StartCoroutine(MoveHorizontal(UnitPanel[1].UnitObject, (int)MoveDirection.right));
        }
        else
        {
            StartCoroutine(MoveHorizontal(UnitPanel[0].UnitObject, (int)MoveDirection.left));
            StartCoroutine(MoveHorizontal(UnitPanel[1].UnitObject, (int)MoveDirection.left));
        }
    }

    IEnumerator MoveHorizontal(GameObject unitObject, int direction)
    {
        float newPos = unitObject.transform.position.x + (direction) * 253;

        while(unitObject.transform.position.x != newPos)
        {
            unitObject.transform.position = new Vector3(unitObject.transform.position.x + (direction * speed * Time.deltaTime),
                unitObject.transform.position.y, unitObject.transform.position.z);

            if(direction == 1)
            {
                if (unitObject.transform.position.x >= newPos)
                    unitObject.transform.position = new Vector3(newPos, unitObject.transform.position.y, unitObject.transform.position.z);
            }
            else
            {
                if (unitObject.transform.position.x <= newPos)
                    unitObject.transform.position = new Vector3(newPos, unitObject.transform.position.y, unitObject.transform.position.z);
            }

            yield return null;
        }

        // Next unit is the unit that has moved out of panel, had to disable GO because spear etc would stick out
        UnitHolder nextUnit = UnitPanel[0] == currentUnit ? UnitPanel[1] : UnitPanel[0];

        nextUnit.UnitObject.SetActive(false);

        NextButton.interactable = true;
        PreviousButton.interactable = true;

        UnitText.text = currentMercenary.UnitType.ToString();
    }









    // Setting Up Equipments
    void ChangeUnitEquipments(UnitHolder Panel, List<Item> mercenaryItems)
    {
        SkeletonGraphic skeletonGraphic = Panel.UnitObject.GetComponent<SkeletonGraphic>();
        
        if(Panel.equippedItems != null)
        {
            ResetEquipments(Panel, skeletonGraphic);
        }

        for (int i = 0; i < mercenaryItems.Count; i++)
        {
            AddEquipment(Panel, skeletonGraphic, mercenaryItems[i].InitiateItem());
        }
    }
    
    void ResetEquipments(UnitHolder Panel, SkeletonGraphic skeletonGraphic)
    {
        foreach(Item item in Panel.equippedItems)
        {
            SetAllAttachment(skeletonGraphic, Panel.dictEquippedItems[item.ItemSlot].front, true);
            SetAllAttachment(skeletonGraphic, Panel.dictEquippedItems[item.ItemSlot].side, true);
            SetAllAttachment(skeletonGraphic, Panel.dictEquippedItems[item.ItemSlot].back, true);
            SetAllAttachment(skeletonGraphic, Panel.dictEquippedItems[item.ItemSlot].back2, true);

            Panel.dictEquippedItems[item.ItemSlot] = null;
        }

        Panel.equippedItems = new List<Item>();
    }

    void AddEquipment(UnitHolder Panel, SkeletonGraphic skeletonGraphic, Item item)
    {
        SetAllAttachment(skeletonGraphic, item.front);
        
        Panel.equippedItems.Add(item);
        Panel.dictEquippedItems[item.ItemSlot] = item;
    }

    void SetAllAttachment(SkeletonGraphic skeletonGraphic, List<SpineAttachment> SpineAttachment, bool remove = false)
    {
        for (int i = 0; i < SpineAttachment.Count; i++)
        {
            if (remove)
                skeletonGraphic.Skeleton.SetAttachment(SpineAttachment[i].SlotName, null);
            else
                skeletonGraphic.Skeleton.SetAttachment(SpineAttachment[i].SlotName, SpineAttachment[i].AttachmentName);
        }
    }






    // Unit Holder
    [System.Serializable]
    class UnitHolder
    {
        public GameObject UnitObject;
        public List<Item> equippedItems = new List<Item>();
        public Dictionary<ItemSlot, Item> dictEquippedItems = new Dictionary<ItemSlot, Item>();

        UnitHolder()
        {
            dictEquippedItems.Add(ItemSlot.Head, null);
            dictEquippedItems.Add(ItemSlot.Leg, null);
            dictEquippedItems.Add(ItemSlot.MainHand, null);
            dictEquippedItems.Add(ItemSlot.Offhand, null);
            dictEquippedItems.Add(ItemSlot.Shoulder, null);
            dictEquippedItems.Add(ItemSlot.TwoHanded, null);
            dictEquippedItems.Add(ItemSlot.SecondaryWeapon, null);
        }
    }
}
