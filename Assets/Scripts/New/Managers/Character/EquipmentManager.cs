using Spine;
using Spine.Unity;
using SpineControllerVersion;
using System.Collections.Generic;
using UnityEngine;

public class EquipmentManager : MonoBehaviour
{
    public SpineAttachmentSO ArrowOnBody_Front;
    public SpineAttachmentSO ArrowOnBody_Back;

    private Unit unit;
    private SkeletonAnimation skelAnim;

    public List<Item> startingItems;
    public List<Item> equippedItemList;
    public Dictionary<ItemSlot, Item> equippedItems = new Dictionary<ItemSlot, Item>();

    public Item secondaryWeapon;

    public delegate void OnProjectileRelease();
    public OnProjectileRelease ProjectileRelease;

    // Start is called before the first frame update
    void Start()
    {
        unit = GetComponent<Unit>();
        skelAnim = GetComponentInChildren<SkeletonAnimation>();

        skelAnim.AnimationState.Event += HandleAnimationStateEvent;

        if(GetComponent<UnitController>() is PlayerController)
        {
            startingItems.Clear();
            startingItems.AddRange(GameManager.Instance.PlayerEquipments);
        }

        SetStartingItems();

        unit.unitController.ResetAttachments += ResetAttachments;
    }

    // Update is called once per frame
    void Update()
    {
        //ChangeItem();
    }

    private void SetStartingItems()
    {
        equippedItems.Add(ItemSlot.Head, null);
        equippedItems.Add(ItemSlot.Leg, null);
        equippedItems.Add(ItemSlot.MainHand, null);
        equippedItems.Add(ItemSlot.Offhand, null);
        equippedItems.Add(ItemSlot.Shoulder, null);
        equippedItems.Add(ItemSlot.TwoHanded, null);
        equippedItems.Add(ItemSlot.SecondaryWeapon, null);

        int i = 0;
        for (; i < startingItems.Count; i++)
        {
            EquipItems(startingItems[i].InitiateItem());
        }

        for (i = startingItems.Count - 1; i >= 0; i--)
        {
            startingItems.RemoveAt(i);
        }
    }

    public void PickupSecondary(ItemWeapon secondaryWeapon)
    {
        Item initializedWeapon = secondaryWeapon.InitiateItem();

        equippedItems[initializedWeapon.ItemSlot] = initializedWeapon;

        // Add attachments of newly equipped item
        for (int i = 0; i < equippedItems[initializedWeapon.ItemSlot].front.Count; i++)
        {
            skelAnim.skeleton.SetAttachment(equippedItems[initializedWeapon.ItemSlot].front[i].SlotName, equippedItems[initializedWeapon.ItemSlot].front[i].AttachmentName);
        }
    }

    /*public bool changeItemNow = false;
     void ChangeItem()
     {
         if (changeItemNow)
       {
           int i = 0;
           for (; i < startingItems.Count; i++)
           {
               EquipItems(startingItems[i].InitiateItem());
           }

           for (i = startingItems.Count - 1; i >= 0; i--)
           {
               startingItems.RemoveAt(i);
           }
           changeItemNow = false;
       }
     }*/


    private void EquipItems(Item item)
    {
        unit.HealthMax += item.HealthBonus;
        unit.Damage += item.DamageBonus;

        //if(item.ItemSlot == ItemSlot.MainHand || item.ItemSlot == ItemSlot.Offhand || item.ItemSlot == ItemSlot.TwoHanded)
        if (item.ItemSlot == ItemSlot.TwoHanded)
        {
            ItemWeapon weapon = item as ItemWeapon;
            GetComponent<Unit>().animationList = weapon.AnimationList;

            UnequipItem(ItemSlot.MainHand);
            UnequipItem(ItemSlot.Offhand);
            UnequipItem(ItemSlot.TwoHanded);

            // Just to see list in editor
            equippedItemList.Add(item);

            equippedItems[item.ItemSlot] = item;

            // Add attachments of newly equipped item
            for (int i = 0; i < equippedItems[item.ItemSlot].front.Count; i++)
            {
                skelAnim.skeleton.SetAttachment(equippedItems[item.ItemSlot].front[i].SlotName, equippedItems[item.ItemSlot].front[i].AttachmentName);
            }
        }
        else if (item.ItemSlot == ItemSlot.Offhand)
        {
            if (equippedItems[ItemSlot.MainHand] != null)
            {
                if (item is ItemWeapon)
                {
                    ItemWeapon weapon = item as ItemWeapon;
                    GetComponent<Unit>().animationList = weapon.AnimationList;
                }
                else
                {
                    ItemWeapon weapon = equippedItems[ItemSlot.MainHand] as ItemWeapon;
                    GetComponent<Unit>().animationList = weapon.AnimationList;
                }

                UnequipItem(ItemSlot.Offhand);

                // Just to see list in editor
                equippedItemList.Add(item);

                equippedItems[item.ItemSlot] = item;

                // Add attachments of newly equipped item
                for (int i = 0; i < equippedItems[item.ItemSlot].front.Count; i++)
                {
                    skelAnim.skeleton.SetAttachment(equippedItems[item.ItemSlot].front[i].SlotName, equippedItems[item.ItemSlot].front[i].AttachmentName);
                }
            }
            else
            {
                // Equip a weapon first
            }
        }
        else if (item.ItemSlot == ItemSlot.MainHand)
        {
            if (equippedItems[ItemSlot.Offhand] != null && equippedItems[ItemSlot.Offhand] is ItemWeapon)
            {
            }
            else
            {
                ItemWeapon weapon = item as ItemWeapon;
                GetComponent<Unit>().animationList = weapon.AnimationList;
            }

            UnequipItem(ItemSlot.MainHand);
            UnequipItem(ItemSlot.TwoHanded);

            // Just to see list in editor
            equippedItemList.Add(item);

            equippedItems[item.ItemSlot] = item;

            // Add attachments of newly equipped item
            for (int i = 0; i < equippedItems[item.ItemSlot].front.Count; i++)
            {
                skelAnim.skeleton.SetAttachment(equippedItems[item.ItemSlot].front[i].SlotName, equippedItems[item.ItemSlot].front[i].AttachmentName);
            }
        }
        else if (item.ItemSlot == ItemSlot.SecondaryWeapon)
        {
            UnequipItem(item.ItemSlot);

            equippedItemList.Add(item);

            equippedItems[item.ItemSlot] = item;

            for (int i = 0; i < equippedItems[item.ItemSlot].front.Count; i++)
            {
                skelAnim.skeleton.SetAttachment(equippedItems[item.ItemSlot].front[i].SlotName, equippedItems[item.ItemSlot].front[i].AttachmentName);
            }
        }
        else
        {
            UnequipItem(item.ItemSlot);

            // Just to see list in editor
            equippedItemList.Add(item);

            equippedItems[item.ItemSlot] = item;

            // Add attachments of newly equipped item
            for (int i = 0; i < equippedItems[item.ItemSlot].front.Count; i++)
            {
                skelAnim.skeleton.SetAttachment(equippedItems[item.ItemSlot].front[i].SlotName, equippedItems[item.ItemSlot].front[i].AttachmentName);
            }
        }
    }

    private void UnequipItem(ItemSlot itemSlot)
    {
        // Means an item is equipped
        if (equippedItems.ContainsKey(itemSlot))
        {
            if (equippedItems[itemSlot] != null)
            {
                // Remove previous equipment attachment from skeleton
                for (int i = 0; i < equippedItems[itemSlot].front.Count; i++)
                {
                    skelAnim.skeleton.SetAttachment(equippedItems[itemSlot].front[i].SlotName, null);
                }

                if (equippedItems[itemSlot] != null)
                {
                    int index = equippedItemList.IndexOf(equippedItems[itemSlot]);
                    equippedItemList.RemoveAt(index);

                    equippedItems[itemSlot] = null;
                }
            }
        }
    }

    private void HandleAnimationStateEvent(TrackEntry trackEntry, Spine.Event e)
    {
        //Debug.Log("Event fired! " + e.Data.Name);

        switch (e.Data.Name)
        {
            case "MeleeAttack":
                break;
            case "Armor Triggers/Shoulder_Front":
                if (equippedItems[ItemSlot.Shoulder] != null)
                {
                    SetAllAttachment(equippedItems[ItemSlot.Shoulder].front);
                    SetAllAttachment(equippedItems[ItemSlot.Shoulder].side, true);
                    SetAllAttachment(equippedItems[ItemSlot.Shoulder].back, true);
                }
                break;
            case "Armor Triggers/Shoulder_Side":
                if (equippedItems[ItemSlot.Shoulder] != null)
                {
                    skelAnim.skeleton.SetAttachment(equippedItems[ItemSlot.Shoulder].front[0].SlotName, null);
                    SetAllAttachment(equippedItems[ItemSlot.Shoulder].side);
                    SetAllAttachment(equippedItems[ItemSlot.Shoulder].back, true);
                }
                break;
            case "Armor Triggers/Shoulder_Back":
                if (equippedItems[ItemSlot.Shoulder] != null)
                {
                    skelAnim.skeleton.SetAttachment(equippedItems[ItemSlot.Shoulder].front[0].SlotName, null);
                    SetAllAttachment(equippedItems[ItemSlot.Shoulder].side, true);
                    SetAllAttachment(equippedItems[ItemSlot.Shoulder].back);
                }
                break;
            case "ProjectileRelease":
                if (equippedItems[ItemSlot.TwoHanded] != null)
                {
                    ProjectileRelease();
                    skelAnim.skeleton.SetAttachment(equippedItems[ItemSlot.TwoHanded].front[0].SlotName, null);
                    skelAnim.skeleton.SetAttachment(equippedItems[ItemSlot.TwoHanded].front[1].SlotName, null);
                    skelAnim.skeleton.SetAttachment(equippedItems[ItemSlot.TwoHanded].front[2].SlotName, null);
                }
                else Debug.LogError("Projectile could not be found, which should not have happened");
                break;
            case "ProjectileDraw":
                if (equippedItems[ItemSlot.TwoHanded] != null)
                {
                    skelAnim.skeleton.SetAttachment(equippedItems[ItemSlot.TwoHanded].front[0].SlotName, equippedItems[ItemSlot.TwoHanded].front[0].AttachmentName);
                    skelAnim.skeleton.SetAttachment(equippedItems[ItemSlot.TwoHanded].front[1].SlotName, equippedItems[ItemSlot.TwoHanded].front[1].AttachmentName);
                    skelAnim.skeleton.SetAttachment(equippedItems[ItemSlot.TwoHanded].front[2].SlotName, equippedItems[ItemSlot.TwoHanded].front[2].AttachmentName);
                }
                else Debug.LogError("Projectile could not be found, which should not have happened");
                break;
            case "Shield Triggers/Shield_Side":
                if (equippedItems[ItemSlot.Offhand] != null)
                {
                    skelAnim.skeleton.SetAttachment(equippedItems[ItemSlot.Offhand].front[0].SlotName, equippedItems[ItemSlot.Offhand].front[0].AttachmentName);
                    skelAnim.skeleton.SetAttachment(equippedItems[ItemSlot.Offhand].side[0].SlotName, null);
                }
                break;
            case "Shield Triggers/Shield_Front":
                if (equippedItems[ItemSlot.Offhand] != null)
                {
                    skelAnim.skeleton.SetAttachment(equippedItems[ItemSlot.Offhand].front[0].SlotName, null);
                    skelAnim.skeleton.SetAttachment(equippedItems[ItemSlot.Offhand].side[0].SlotName, equippedItems[ItemSlot.Offhand].side[0].AttachmentName);
                }
                break;
            case "Weapon Triggers/Weapon_Hide_Front":
                if(equippedItems[ItemSlot.TwoHanded] != null)
                {
                    skelAnim.skeleton.SetAttachment(equippedItems[ItemSlot.TwoHanded].front[0].SlotName, null);
                }
                else
                {
                    skelAnim.skeleton.SetAttachment(equippedItems[ItemSlot.MainHand].front[0].SlotName, null);
                }
                break;
            case "Weapon Triggers/WeaponSecondary_Hide_Front":
                if (equippedItems[ItemSlot.MainHand] != null)
                {
                    //if(equippedItems[ItemSlot.MainHand].front.Count > 1)
                    //    skelAnim.skeleton.SetAttachment(equippedItems[ItemSlot.MainHand].front[1].SlotName, null);
                }
                else
                {
                    skelAnim.skeleton.SetAttachment(equippedItems[ItemSlot.MainHand].front[1].SlotName, null);
                }
                break;
            case "Weapon Triggers/WeaponSecondary_Show_Front":
                if (equippedItems[ItemSlot.MainHand] != null)
                {
                    skelAnim.skeleton.SetAttachment(equippedItems[ItemSlot.MainHand].front[1].SlotName, equippedItems[ItemSlot.MainHand].front[1].AttachmentName);
                }
                break;
            case "Weapon Triggers/Weapon_Show_Front":
                if (equippedItems[ItemSlot.TwoHanded] != null)
                {
                    skelAnim.skeleton.SetAttachment(equippedItems[ItemSlot.TwoHanded].front[0].SlotName, equippedItems[ItemSlot.TwoHanded].front[0].AttachmentName);
                }
                else
                {
                    skelAnim.skeleton.SetAttachment(equippedItems[ItemSlot.MainHand].front[0].SlotName, equippedItems[ItemSlot.MainHand].front[0].AttachmentName);
                }
                break;
            case "Weapon Triggers/Weapon_Throw":
                ProjectileRelease();
                break;
            case "Weapon Triggers/Weapon_Front":
                if (equippedItems[ItemSlot.TwoHanded] != null)
                {
                    SetAllAttachment(equippedItems[ItemSlot.TwoHanded].front);
                    SetAllAttachment(equippedItems[ItemSlot.TwoHanded].side, true);
                }
                break;
            case "Weapon Triggers/Weapon_Side":
                if (equippedItems[ItemSlot.TwoHanded] != null)
                {
                    SetAllAttachment(equippedItems[ItemSlot.TwoHanded].side);
                    SetAllAttachment(equippedItems[ItemSlot.TwoHanded].front, true);
                }
                break;
            case "Weapon Triggers/Weapon_Back":
                if (equippedItems[ItemSlot.TwoHanded] != null)
                {
                    SetAllAttachment(equippedItems[ItemSlot.TwoHanded].front, true);
                    SetAllAttachment(equippedItems[ItemSlot.TwoHanded].back);
                }
                break;
            case "Weapon Triggers/Weapon_Back_2":
                if (equippedItems[ItemSlot.TwoHanded] != null)
                {
                    SetAllAttachment(equippedItems[ItemSlot.TwoHanded].front, true);
                    SetAllAttachment(equippedItems[ItemSlot.TwoHanded].back2);
                }
                break;
            //unit.unitController.currentAttack
            default:
                break;
        }
    }

    void SetAllAttachment(List<SpineAttachment> SpineAttachment, bool remove = false)
    {
        for (int i = 0; i < SpineAttachment.Count; i++)
        {
            if (remove)
                skelAnim.skeleton.SetAttachment(SpineAttachment[i].SlotName, null);
            else
                skelAnim.skeleton.SetAttachment(SpineAttachment[i].SlotName, SpineAttachment[i].AttachmentName);
        }
    }

    void DisableControls()
    {
        //ResetAttachments();
    }

    public void ResetAttachments()
    {
        // Shoulders
        if (equippedItems[ItemSlot.Shoulder] != null)
        {
            SetAllAttachment(equippedItems[ItemSlot.Shoulder].side, true);
            SetAllAttachment(equippedItems[ItemSlot.Shoulder].back, true);

            SetAllAttachment(equippedItems[ItemSlot.Shoulder].front);
        }

        // Shield
        if (equippedItems[ItemSlot.Offhand] != null)
        {
            SetAllAttachment(equippedItems[ItemSlot.Offhand].front);

            SetAllAttachment(equippedItems[ItemSlot.Offhand].side, true);
        }

        // Weapon
    }

    public void ArrowOnBody(bool isHitBehind)
    {
        // entered from behind
        if(isHitBehind)
        {
            int randArrow = Random.Range(0, ArrowOnBody_Back.SpineAttachmentList.Count);

            skelAnim.skeleton.SetAttachment(ArrowOnBody_Back.SpineAttachmentList[randArrow].SlotName, ArrowOnBody_Back.SpineAttachmentList[randArrow].AttachmentName);
        }
        // entered from front
        else
        {
            int randArrow = Random.Range(0, ArrowOnBody_Front.SpineAttachmentList.Count);

            skelAnim.skeleton.SetAttachment(ArrowOnBody_Front.SpineAttachmentList[randArrow].SlotName, ArrowOnBody_Front.SpineAttachmentList[randArrow].AttachmentName);
        }
    }

    public void SpearOnBody(bool isHitBehind)
    {

    }

    public void SpearDead(bool isHitBehind, bool isHeadShot, SpineAttachment spearAttachment)
    {
        skelAnim.skeleton.SetAttachment("Weapon/SpearThrow", spearAttachment.AttachmentName);
        
        if(isHeadShot)
        {

        }
    }
}
