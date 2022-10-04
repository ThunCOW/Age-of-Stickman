using Spine;
using Spine.Unity;
using SpineControllerVersion;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EquipmentManager : MonoBehaviour
{
    private Unit unit;
    private SkeletonAnimation skelAnim;

    public List<Item> startingItems;
    public List<Item> equippedItemList;
    public Dictionary<ItemSlot, Item> equippedItems = new Dictionary<ItemSlot, Item>();

    // Start is called before the first frame update
    void Start()
    {
        unit = GetComponent<Unit>();
        skelAnim = GetComponentInChildren<SkeletonAnimation>();

        skelAnim.AnimationState.Event += HandleAnimationStateEvent;

        if(GetComponent<UnitController>() is PlayerController)
        {
            startingItems = new List<Item>();
            startingItems.AddRange(GameManager.Instance.PlayerEquipments);
        }

        SetStartingItems();
    }

    // Update is called once per frame
    void Update()
    {
        ChangeItem();
    }

    private void SetStartingItems()
    {
        equippedItems.Add(ItemSlot.Head, null);
        equippedItems.Add(ItemSlot.Leg, null);
        equippedItems.Add(ItemSlot.MainHand, null);
        equippedItems.Add(ItemSlot.Offhand, null);
        equippedItems.Add(ItemSlot.Shoulder, null);
        equippedItems.Add(ItemSlot.TwoHanded, null);

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

    public bool changeItemNow = false;
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
    }

    void ChangeItem(List<Item> newItems)
    {
        int i = 0;
        for (; i < newItems.Count; i++)
        {
            EquipItems(startingItems[i].InitiateItem());
        }
    }

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

        if (e.Data.Name == "MeleeAttack")
        {

        }
        if (e.Data.Name == "Armor Triggers/Shoulder_Front")
        {
            if (equippedItems[ItemSlot.Shoulder] != null)
            {
                SetAllAttachment(equippedItems[ItemSlot.Shoulder].front);
                SetAllAttachment(equippedItems[ItemSlot.Shoulder].side, true);
                SetAllAttachment(equippedItems[ItemSlot.Shoulder].back, true);
            }
        }
        if (e.Data.Name == "Armor Triggers/Shoulder_Side")
        {
            if (equippedItems[ItemSlot.Shoulder] != null)
            {
                skelAnim.skeleton.SetAttachment(equippedItems[ItemSlot.Shoulder].front[0].SlotName, null);
                SetAllAttachment(equippedItems[ItemSlot.Shoulder].side);
                SetAllAttachment(equippedItems[ItemSlot.Shoulder].back, true);
            }
        }
        if (e.Data.Name == "Armor Triggers/Shoulder_Back")
        {
            if (equippedItems[ItemSlot.Shoulder] != null)
            {
                skelAnim.skeleton.SetAttachment(equippedItems[ItemSlot.Shoulder].front[0].SlotName, null);
                SetAllAttachment(equippedItems[ItemSlot.Shoulder].side, true);
                SetAllAttachment(equippedItems[ItemSlot.Shoulder].back);
            }
        }
        if (e.Data.Name == "ProjectileRelease")
        {
            if (equippedItems.ContainsKey(ItemSlot.TwoHanded))
            {
                skelAnim.skeleton.SetAttachment(equippedItems[ItemSlot.TwoHanded].front[0].SlotName, null);
                skelAnim.skeleton.SetAttachment(equippedItems[ItemSlot.TwoHanded].front[1].SlotName, null);
                skelAnim.skeleton.SetAttachment(equippedItems[ItemSlot.TwoHanded].front[2].SlotName, null);
            }
            else Debug.LogError("Projectile could not be found, which should not have happened");
        }
        if (e.Data.Name == "ProjectileDraw")
        {
            if (equippedItems.ContainsKey(ItemSlot.TwoHanded))
            {
                if (equippedItems.ContainsKey(ItemSlot.TwoHanded))
                {
                    skelAnim.skeleton.SetAttachment(equippedItems[ItemSlot.TwoHanded].front[0].SlotName, equippedItems[ItemSlot.TwoHanded].front[0].AttachmentName);
                    skelAnim.skeleton.SetAttachment(equippedItems[ItemSlot.TwoHanded].front[1].SlotName, equippedItems[ItemSlot.TwoHanded].front[1].AttachmentName);
                    skelAnim.skeleton.SetAttachment(equippedItems[ItemSlot.TwoHanded].front[2].SlotName, equippedItems[ItemSlot.TwoHanded].front[2].AttachmentName);
                }
            }
            else Debug.LogError("Projectile could not be found, which should not have happened");
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

    void ResetAttachments()
    {
        // Shoulders
        SetAllAttachment(equippedItems[ItemSlot.Shoulder].side, true);
        SetAllAttachment(equippedItems[ItemSlot.Shoulder].back, true);

        SetAllAttachment(equippedItems[ItemSlot.Shoulder].front);

        // Shield

        // Weapon
    }
}
