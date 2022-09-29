using SpineControllerVersion;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ShopPanel : MonoBehaviour
{
    public List<Item> WeaponList;
    public List<Item> ShieldList;
    public List<Item> ArmorList;
    public Dictionary<ShopItemCategory, List<Item>> ItemUpgradeDict;

    public UpgradeScreen Weapon;
    public UpgradeScreen Shield;
    public UpgradeScreen Armor;
    public Dictionary<ShopItemCategory, UpgradeScreen> UpgradeScreenDict;

    void Start()
    {
        ItemUpgradeDict.Add(ShopItemCategory.Weapon, WeaponList);
        ItemUpgradeDict.Add(ShopItemCategory.Shield, ShieldList);
        ItemUpgradeDict.Add(ShopItemCategory.Armor, ArmorList);

        UpgradeScreenDict.Add(ShopItemCategory.Weapon, Weapon);
        UpgradeScreenDict.Add(ShopItemCategory.Shield, Shield);
        UpgradeScreenDict.Add(ShopItemCategory.Armor, Armor);

        SetStartingItems();
    }

    public void ChangeItem(ShopItemCategory shopItemCategory)
    {
        var lastItemIndex = 0;
        lastItemIndex = ItemUpgradeDict[shopItemCategory].IndexOf(UpgradeScreenDict[shopItemCategory].EquippedItemSlot.Item);

        if (ItemUpgradeDict[shopItemCategory].Count <= lastItemIndex + 1)
        {
            // TODO : max item upgrade reached
        }
        else
            UpgradeScreenDict[shopItemCategory].PurchasableItemSlot.Item = ItemUpgradeDict[shopItemCategory][lastItemIndex + 2];

        /*switch (shopItemCategory)
        {
            case ShopItemCategory.Weapon:
                lastItemIndex = WeaponList.IndexOf(Weapon.EquippedItemSlot.Item);
                Weapon.EquippedItemSlot.Item = WeaponList[lastItemIndex + 1];

                if(WeaponList.Count <= lastItemIndex + 1)
                {
                    // TODO : max item upgrade reached
                }
                else
                    Weapon.PurchasableItemSlot.Item = WeaponList[lastItemIndex + 2];

                break;
            case ShopItemCategory.Shield:
                lastItemIndex = ShieldList.IndexOf(Shield.EquippedItemSlot.Item);
                Shield.EquippedItemSlot.Item = ShieldList[lastItemIndex + 1];

                if(ShieldList.Count <= lastItemIndex + 1)
                {

                }
                else
                    Shield.PurchasableItemSlot.Item = ShieldList[lastItemIndex + 2];

                break;
            case ShopItemCategory.Armor:
                lastItemIndex = ArmorList.IndexOf(Armor.EquippedItemSlot.Item);
                Armor.EquippedItemSlot.Item = ArmorList[lastItemIndex + 1];

                if (ArmorList.Count <= lastItemIndex + 1)
                {

                }
                else
                    Armor.PurchasableItemSlot.Item = ArmorList[lastItemIndex + 2];

                break;
            default:
                break;
        }*/
    }

    public void SetStartingItems()
    {
        UpgradeScreenDict[ShopItemCategory.Weapon].EquippedItemSlot.Item = GameManager.Instance.Player.unitInventory.equippedItems[ItemSlot.MainHand];
        UpgradeScreenDict[ShopItemCategory.Weapon].PurchasableItemSlot.Item = GameManager.Instance.Player.unitInventory.equippedItems[ItemSlot.MainHand];

        UpgradeScreenDict[ShopItemCategory.Shield].EquippedItemSlot.Item = GameManager.Instance.Player.unitInventory.equippedItems[ItemSlot.MainHand];
        UpgradeScreenDict[ShopItemCategory.Shield].PurchasableItemSlot.Item = GameManager.Instance.Player.unitInventory.equippedItems[ItemSlot.MainHand];

        UpgradeScreenDict[ShopItemCategory.Armor].EquippedItemSlot.Item = GameManager.Instance.Player.unitInventory.equippedItems[ItemSlot.MainHand];
        UpgradeScreenDict[ShopItemCategory.Armor].PurchasableItemSlot.Item = GameManager.Instance.Player.unitInventory.equippedItems[ItemSlot.MainHand];
    }
}

public class UpgradeScreen
{
    public ShopItem EquippedItemSlot;
    public ShopItem PurchasableItemSlot;
}
