using Spine;
using Spine.Unity;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

[System.Serializable]
public class MercenaryUnit : MonoBehaviour
{
    public UnitHolder SpineUnitHolder;

    [Space]
    [SerializeField] SkeletonGraphic skeletonGraphic;
    [SerializeField] BasicAnimation idleAnimation;

    [Space]
    [SerializeField] Button HireMercenaryButton;

    [Space]
    Mercenary _currentMercenary = null;
    public Mercenary CurrentMercenary
    {
        get { return _currentMercenary; }
        set
        {
            _currentMercenary = value;

            if(CurrentMercenary == null)
            {
                HireMercenaryImage.SetActive(true);
                MercenaryGameobject.SetActive(false);
                HireMercenaryButton.interactable = true;
                return;
            }

            MercenaryGameobject.SetActive(true);
            HireMercenaryImage.SetActive(false);
            HireMercenaryButton.interactable = false;

            List<Item> mercenaryItems = CurrentMercenary.Unit.GetComponent<EquipmentManager>().startingItems;

            SpineUnitHolder.ChangeUnitEquipments(SpineUnitHolder, mercenaryItems);

            skeletonGraphic.AnimationState.SetAnimation(0, idleAnimation.SpineAnimationReference, false);
        }
    }

    [Space]
    [SerializeField] GameObject HireMercenaryImage;
    [SerializeField] GameObject MercenaryGameobject;

    void Start()
    {
        if(CurrentMercenary == null)
        {
            HireMercenaryImage.SetActive(true);
            MercenaryGameobject.SetActive(false);
        }
        else
        {
            MercenaryGameobject.SetActive(true);
            HireMercenaryImage.SetActive(false);
        }
        
        skeletonGraphic.AnimationState.Event += HandleAnimationStateEvent;
    }

    private void HandleAnimationStateEvent(TrackEntry trackEntry, Spine.Event e)
    {
        //Debug.Log("Event fired! " + e.Data.Name);

        switch(e.Data.Name)
        {
            case "Main Menu/Arrowhead_Hide":
                if (CurrentMercenary.UnitType == UnitType.Archer)
                {
                    skeletonGraphic.Skeleton.SetAttachment("Weapon/Bow_Arrow_00_0", null);
                    skeletonGraphic.Skeleton.SetAttachment("Weapon/Bow_Arrow_00_3", null);
                }
                break;
            case "Main Menu/ShowSecondArrow":
                if (CurrentMercenary.UnitType == UnitType.Archer)
                {
                    skeletonGraphic.Skeleton.SetAttachment("Weapon/Bow_Arrow_00_3", "Weapon/Bow_Arrow_00_0");
                    skeletonGraphic.Skeleton.SetAttachment("Weapon/Bow_Arrow_00_4", "Weapon/Bow_Arrow_00_1");
                    skeletonGraphic.Skeleton.SetAttachment("Weapon/Bow_Arrow_00_5", "Weapon/Bow_Arrow_00_2");
                }
                else
                {
                    skeletonGraphic.Skeleton.SetAttachment("Weapon/Bow_Arrow_00_3", null);
                    skeletonGraphic.Skeleton.SetAttachment("Weapon/Bow_Arrow_00_4", null);
                    skeletonGraphic.Skeleton.SetAttachment("Weapon/Bow_Arrow_00_5", null);
                }
                break;
            case "Armor Triggers/Shoulder_Back":
                if (SpineUnitHolder.dictEquippedItems[ItemSlot.Shoulder] != null)
                {
                    skeletonGraphic.Skeleton.SetAttachment(SpineUnitHolder.dictEquippedItems[ItemSlot.Shoulder].front[0].SlotName, null);
                    skeletonGraphic.Skeleton.SetAttachment(SpineUnitHolder.dictEquippedItems[ItemSlot.Shoulder].back[0].SlotName, SpineUnitHolder.dictEquippedItems[ItemSlot.Shoulder].back[0].AttachmentName);
                    skeletonGraphic.Skeleton.SetAttachment(SpineUnitHolder.dictEquippedItems[ItemSlot.Shoulder].back[1].SlotName, SpineUnitHolder.dictEquippedItems[ItemSlot.Shoulder].back[1].AttachmentName);
                }
                break;
            default:
                break;
        }
    }





    void OnEnable()
    {
        if(CurrentMercenary == null)
        {
            HireMercenaryImage.SetActive(true);
            MercenaryGameobject.SetActive(false);
            HireMercenaryButton.interactable = true;
        }
        else
        {
            MercenaryGameobject.SetActive(true);
            HireMercenaryImage.SetActive(false);
            HireMercenaryButton.interactable = false;

            List<Item> mercenaryItems = CurrentMercenary.Unit.GetComponent<EquipmentManager>().startingItems;

            SpineUnitHolder.ChangeUnitEquipments(SpineUnitHolder, mercenaryItems);

            //SpineUnitHolder.UnitObject.GetComponent<SkeletonGraphic>().AnimationState.SetAnimation(0, CurrentMercenary.PanelIdleAnimation.SpineAnimationReference, false);
        }
    }
}
