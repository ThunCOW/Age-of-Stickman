using SpineControllerVersion;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ShopPanel : MonoBehaviour
{
    public List<Item> WeaponList;
    public List<Item> ShieldList;
    public List<Item> ArmorList;
    public Dictionary<ShopItemCategory, List<Item>> ItemUpgradeDict = new Dictionary<ShopItemCategory, List<Item>>();

    public UpgradeScreen Weapon;
    public UpgradeScreen Shield;
    public UpgradeScreen Armor;
    public Dictionary<ShopItemCategory, UpgradeScreen> UpgradeScreenDict = new Dictionary<ShopItemCategory, UpgradeScreen>();

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

    public void ItemUpgrade(ShopItemCategory shopItemCategory)
    {
        var lastItemIndex = 0;

        lastItemIndex = ItemUpgradeDict[shopItemCategory].IndexOf(UpgradeScreenDict[shopItemCategory].EquippedItemSlot.Item);

        if (ItemUpgradeDict[shopItemCategory].Count <= lastItemIndex + 2)
        {
            // TODO : max item upgrade reached
            UpgradeScreenDict[shopItemCategory].EquippedItemSlot.Item = ItemUpgradeDict[shopItemCategory][lastItemIndex + 1];
            UpgradeScreenDict[shopItemCategory].PurchasableItemSlot.GetComponent<Button>().enabled = false;
        }
        else
        {
            UpgradeScreenDict[shopItemCategory].EquippedItemSlot.Item = ItemUpgradeDict[shopItemCategory][lastItemIndex + 1];
            UpgradeScreenDict[shopItemCategory].PurchasableItemSlot.Item = ItemUpgradeDict[shopItemCategory][lastItemIndex + 2];
        }

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
        foreach(Item item in GameManager.Instance.PlayerEquipments)
        {
            var lastItemIndex = 0;

            switch (item.ItemSlot)
            {
                case ItemSlot.Shoulder:
                    UpgradeScreenDict[ShopItemCategory.Armor].EquippedItemSlot.Item = item;

                    lastItemIndex = ArmorList.IndexOf(item);
                    if(ArmorList.Count == lastItemIndex + 1)
                    {
                        // Max item upgrade reached
                        UpgradeScreenDict[ShopItemCategory.Armor].PurchasableItemSlot.Item = item;
                        UpgradeScreenDict[ShopItemCategory.Armor].PurchasableItemSlot.GetComponent<Button>().enabled = false;
                    }
                    else
                        UpgradeScreenDict[ShopItemCategory.Armor].PurchasableItemSlot.Item = ArmorList[lastItemIndex + 1];

                    break;
                case ItemSlot.MainHand:
                    UpgradeScreenDict[ShopItemCategory.Weapon].EquippedItemSlot.Item = item;

                    lastItemIndex = WeaponList.IndexOf(item);
                    if (WeaponList.Count == lastItemIndex + 1)
                    {
                        // Max item upgrade reached

                        UpgradeScreenDict[ShopItemCategory.Weapon].PurchasableItemSlot.Item = item;
                        UpgradeScreenDict[ShopItemCategory.Weapon].PurchasableItemSlot.GetComponent<Button>().enabled = false;
                    }
                    else
                        UpgradeScreenDict[ShopItemCategory.Weapon].PurchasableItemSlot.Item = WeaponList[lastItemIndex + 1];

                    break;
                case ItemSlot.Offhand:
                    UpgradeScreenDict[ShopItemCategory.Shield].EquippedItemSlot.Item = item;

                    lastItemIndex = ShieldList.IndexOf(item);
                    if (ShieldList.Count == lastItemIndex + 1)
                    {
                        // Max item upgrade reached

                        UpgradeScreenDict[ShopItemCategory.Shield].PurchasableItemSlot.Item = item;
                        UpgradeScreenDict[ShopItemCategory.Shield].PurchasableItemSlot.GetComponent<Button>().enabled = false;
                    }
                    else
                        UpgradeScreenDict[ShopItemCategory.Shield].PurchasableItemSlot.Item = ShieldList[lastItemIndex + 1];

                    break;
                default:
                    break;
            }
        }
    }

    public void SetItem(ShopItemCategory shopItemCategory, ItemSlot itemSlot)
    {
        UpgradeScreenDict[shopItemCategory].EquippedItemSlot.Item = GameManager.Instance.Player.unitInventory.equippedItems[itemSlot];

        UpgradeScreenDict[shopItemCategory].PurchasableItemSlot.Item = GameManager.Instance.Player.unitInventory.equippedItems[itemSlot];
    }
}

[System.Serializable]
public class UpgradeScreen
{
    public ShopItem EquippedItemSlot;
    public ShopItem PurchasableItemSlot;
}
