using Spine;
using Spine.Unity;
using SpineControllerVersion;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

[System.Serializable]
public class MercenaryUnit : MonoBehaviour
{
    public UnitHolder SpineUnitHolder;

    [Space]
    [SerializeField] HiringPanel hiringPanel;
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

            if (_isUnlocked)
            {
                if (CurrentMercenary == null)
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
    }

    public GameObject UnlockMercSlotOption;

    [Space]
    [SerializeField] GameObject HireMercenaryImage;
    [SerializeField] GameObject MercenaryGameobject;
    [SerializeField] GameObject LockIcon;
    private bool _isUnlocked;
    public bool isUnlocked
    {
        get { return _isUnlocked; }
        set
        {
            _isUnlocked = value;
            if(value == true)
            {
                LockIcon.SetActive(false);
                HireMercenaryImage.SetActive(true);
                HireMercenaryButton.targetGraphic = HireMercenaryImage.GetComponent<Image>();
            }
            else
            {
                LockIcon.SetActive(true);
                HireMercenaryImage.SetActive(false);
                HireMercenaryButton.targetGraphic = LockIcon.GetComponent<Image>();
            }
        }
    }

    void Start()
    {
        skeletonGraphic.AnimationState.Event += HandleAnimationStateEvent;
    }

    public void _Button_UnlockOrOpenHiringPanel()
    {
        if (isUnlocked)
            hiringPanel.EnableHiringPanel(this);
        else
        {
            if(mercSlotSelected == this && UnlockMercSlotOption.activeSelf)
            {
                UnlockMercSlotOption.SetActive(false);
                return;
            }

            UnlockMercSlotOption.SetActive(true);
            UnlockMercSlotOption.transform.position = new Vector3(transform.position.x, UnlockMercSlotOption.transform.position.y, 0);
            mercSlotSelected = this;

            int i = 1;
            if (MercenaryManager.Instance.Mercenaries[0].isUnlocked) i++;
            if (MercenaryManager.Instance.Mercenaries[1].isUnlocked) i++;
            UnlockMercSlotOption.transform.GetChild(0).GetComponent<TMP_Text>().text = (25 * i).ToString();
        }
    }

    public static MercenaryUnit mercSlotSelected;

    public void _Button_UnlockMercSlot()
    {
        int i = 1;
        if (MercenaryManager.Instance.Mercenaries[0].isUnlocked) i++;
        if (MercenaryManager.Instance.Mercenaries[1].isUnlocked) i++;

        if (GameManager.Instance.Gold >= 25 * i)
        {
            GameManager.Instance.GoldChange(-25 * i);

            SoundManager.Instance.PlayEffect(GameManager.Instance.CoinClicking);

            mercSlotSelected.isUnlocked = true;
            
            UnlockMercSlotOption.SetActive(false);
        }
        else
        {
            GameManager.Instance.NotEnoughGold();
        }
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
        if(isUnlocked)
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
        else
        {
            MercenaryGameobject.SetActive(false);
            HireMercenaryImage.SetActive(false);
            HireMercenaryButton.interactable = true;
        }
    }

    void OnDisable()
    {
        if (UnlockMercSlotOption.activeSelf)
            UnlockMercSlotOption.SetActive(false);

        mercSlotSelected = null;
    }
}
