using SpineControllerVersion;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ShopPanel : MonoBehaviour
{
    public List<Item> WeaponList;
    public List<Item> ShieldList;
    public List<Item> ArmorList;
    public Dictionary<ShopItemCategory, List<Item>> ItemUpgradeDict = new Dictionary<ShopItemCategory, List<Item>>();

    [Header("____________Slot Script Assignment_________")]
    public UpgradeScreen Weapon;
    public UpgradeScreen Shield;
    public UpgradeScreen Armor;
    public Dictionary<ShopItemCategory, UpgradeScreen> UpgradeScreenDict = new Dictionary<ShopItemCategory, UpgradeScreen>();

    [Header("____________Items List____________")]
    public List<ShopItemList> _WeaponList;
    public List<ShopItemList> _ShieldList;
    public List<ShopItemList> _ArmorList;
    public Dictionary<ShopItemCategory, List<ShopItemList>> _ItemUpgradeDict = new Dictionary<ShopItemCategory, List<ShopItemList>>();

    void Start()
    {
        ItemUpgradeDict.Add(ShopItemCategory.Weapon, WeaponList);
        ItemUpgradeDict.Add(ShopItemCategory.Shield, ShieldList);
        ItemUpgradeDict.Add(ShopItemCategory.Armor, ArmorList);

        UpgradeScreenDict.Add(ShopItemCategory.Weapon, Weapon);
        UpgradeScreenDict.Add(ShopItemCategory.Shield, Shield);
        UpgradeScreenDict.Add(ShopItemCategory.Armor, Armor);

        _ItemUpgradeDict.Add(ShopItemCategory.Weapon, _WeaponList);
        _ItemUpgradeDict.Add(ShopItemCategory.Armor, _ArmorList);
        _ItemUpgradeDict.Add(ShopItemCategory.Shield, _ShieldList);

        SetStartingItems();
    }

    public void ItemUpgrade(ShopItemCategory shopItemCategory)
    {
        var lastItemIndex = -1;

        //lastItemIndex = ItemUpgradeDict[shopItemCategory].IndexOf(UpgradeScreenDict[shopItemCategory].EquippedItemSlot.Item);
        
        for(int i = 0; i < _ItemUpgradeDict[shopItemCategory].Count; i++)
        {
            bool indexFound = false;
            for(int u = 0; u < _ItemUpgradeDict[shopItemCategory][i].Items.Count; u++)
            {
                if (_ItemUpgradeDict[shopItemCategory][i].Items[u] == UpgradeScreenDict[shopItemCategory].EquippedItemSlot.Item)
                {
                    indexFound = true;
                    break;
                }
            }
            if (indexFound)
            {
                lastItemIndex = i;
                break;
            }
        }
        //if(lastItemIndex == -1) lastItemIndex = 

        //for (int i = 0; i < _ArmorList.Count; i++)
        //{
        //    if (_ArmorList[i].Items.Contains(item))
        //    {
        //        lastItemIndex = i;
        //        break;
        //    }
        //}

        if (_ItemUpgradeDict[shopItemCategory].Count <= lastItemIndex + 2)
        {
            // TODO : max item upgrade reached
            UpgradeScreenDict[shopItemCategory].EquippedItemSlot.SetShopItem(_ItemUpgradeDict[shopItemCategory][lastItemIndex + 1], true);
            //UpgradeScreenDict[shopItemCategory].EquippedItemSlot.Item = ItemUpgradeDict[shopItemCategory][lastItemIndex + 1];
            //UpgradeScreenDict[shopItemCategory].EquippedItemSlot.ItemsList = _ItemUpgradeDict[shopItemCategory][lastItemIndex + 1].Items;
            UpgradeScreenDict[shopItemCategory].PurchasableItemSlot.GetComponent<Button>().enabled = false;
        }
        else
        {
            UpgradeScreenDict[shopItemCategory].EquippedItemSlot.SetShopItem(_ItemUpgradeDict[shopItemCategory][lastItemIndex + 1]);
            UpgradeScreenDict[shopItemCategory].PurchasableItemSlot.SetShopItem(_ItemUpgradeDict[shopItemCategory][lastItemIndex + 2]);
            //UpgradeScreenDict[shopItemCategory].EquippedItemSlot.Item = ItemUpgradeDict[shopItemCategory][lastItemIndex + 1];
            //UpgradeScreenDict[shopItemCategory].PurchasableItemSlot.Item = ItemUpgradeDict[shopItemCategory][lastItemIndex + 2];
            //
            //UpgradeScreenDict[shopItemCategory].EquippedItemSlot.ItemsList = _ItemUpgradeDict[shopItemCategory][lastItemIndex + 1].Items;
            //UpgradeScreenDict[shopItemCategory].PurchasableItemSlot.ItemsList = _ItemUpgradeDict[shopItemCategory][lastItemIndex + 2].Items;
        }

        for(int q = 0; q < UpgradeScreenDict[shopItemCategory].EquippedItemSlot.ItemsList.Count; q++)
        {
            bool newItem = true;
            // If there is an item in same slot just change it (did it this way cus dont wanna create another dict)
            for(int i = 0; i < GameManager.Instance.PlayerEquipments.Count; i++)
            {
                if(GameManager.Instance.PlayerEquipments[i].ItemSlot == UpgradeScreenDict[shopItemCategory].EquippedItemSlot.ItemsList[q].ItemSlot)
                {
                    newItem = false;
                    GameManager.Instance.PlayerEquipments[i] = UpgradeScreenDict[shopItemCategory].EquippedItemSlot.ItemsList[q];
                    break;
                }
            }
            if(newItem) GameManager.Instance.PlayerEquipments.Add(UpgradeScreenDict[shopItemCategory].EquippedItemSlot.ItemsList[q]);
        }
        GameManager.Instance.mainMenuPlayer.ChangeUnitEquipments(GameManager.Instance.mainMenuPlayer, GameManager.Instance.PlayerEquipments);
    }

    public void SetStartingItems()
    {
        foreach(Item item in GameManager.Instance.PlayerEquipments)
        {
            var lastItemIndex = 0;

            switch (item.ItemSlot)
            {
                case ItemSlot.Shoulder:
                    //UpgradeScreenDict[ShopItemCategory.Armor].EquippedItemSlot.Item = item;

                    for (int i = 0; i < _ArmorList.Count; i++)
                    {
                        if (_ArmorList[i].Items.Contains(item))
                        {
                            lastItemIndex = i;
                            break;
                        }
                    }
                    UpgradeScreenDict[ShopItemCategory.Armor].EquippedItemSlot.SetShopItem(_ItemUpgradeDict[ShopItemCategory.Armor][lastItemIndex]);

                    if (_ArmorList.Count == lastItemIndex + 1)
                    {
                        // Max item upgrade reached
                        UpgradeScreenDict[ShopItemCategory.Armor].PurchasableItemSlot.SetShopItem(_ItemUpgradeDict[ShopItemCategory.Armor][lastItemIndex], true);

                        //UpgradeScreenDict[ShopItemCategory.Armor].PurchasableItemSlot.Item = item;
                        UpgradeScreenDict[ShopItemCategory.Armor].PurchasableItemSlot.GetComponent<Button>().enabled = false;
                    }
                    else
                    {
                        UpgradeScreenDict[ShopItemCategory.Armor].PurchasableItemSlot.SetShopItem(_ItemUpgradeDict[ShopItemCategory.Armor][lastItemIndex + 1]);
                        //UpgradeScreenDict[ShopItemCategory.Armor].PurchasableItemSlot.Item = _ArmorList[lastItemIndex + 1].Items[0];
                        //UpgradeScreenDict[ShopItemCategory.Armor].PurchasableItemSlot.ItemsList = _ArmorList[lastItemIndex + 1].Items;
                    }

                    break;
                case ItemSlot.MainHand:
                    //UpgradeScreenDict[ShopItemCategory.Weapon].EquippedItemSlot.Item = item;

                    for (int i = 0; i < _WeaponList.Count; i++)
                    {
                        if (_WeaponList[i].Items.Contains(item))
                        {
                            lastItemIndex = i;
                            break;
                        }
                    }
                    UpgradeScreenDict[ShopItemCategory.Weapon].EquippedItemSlot.SetShopItem(_ItemUpgradeDict[ShopItemCategory.Weapon][lastItemIndex]);

                    if (_WeaponList.Count == lastItemIndex + 1)
                    {
                        // Max item upgrade reached
                        UpgradeScreenDict[ShopItemCategory.Weapon].PurchasableItemSlot.SetShopItem(_ItemUpgradeDict[ShopItemCategory.Weapon][lastItemIndex], true);

                        //UpgradeScreenDict[ShopItemCategory.Weapon].PurchasableItemSlot.Item = item;
                        UpgradeScreenDict[ShopItemCategory.Weapon].PurchasableItemSlot.GetComponent<Button>().enabled = false;
                    }
                    else
                    {
                        UpgradeScreenDict[ShopItemCategory.Weapon].PurchasableItemSlot.SetShopItem(_ItemUpgradeDict[ShopItemCategory.Weapon][lastItemIndex + 1]);
                        //UpgradeScreenDict[ShopItemCategory.Weapon].PurchasableItemSlot.Item = _WeaponList[lastItemIndex + 1].Items[0];
                        //UpgradeScreenDict[ShopItemCategory.Weapon].PurchasableItemSlot.ItemsList = _WeaponList[lastItemIndex + 1].Items;
                    }

                    break;
                case ItemSlot.Offhand:
                    //UpgradeScreenDict[ShopItemCategory.Shield].EquippedItemSlot.Item = item;

                    for (int i = 0; i < _ShieldList.Count; i++)
                    {
                        if (_ShieldList[i].Items.Contains(item))
                        {
                            lastItemIndex = i;
                            break;
                        }
                    }
                    UpgradeScreenDict[ShopItemCategory.Shield].EquippedItemSlot.SetShopItem(_ItemUpgradeDict[ShopItemCategory.Shield][lastItemIndex]);

                    if (_ShieldList.Count == lastItemIndex + 1)
                    {
                        // Max item upgrade reached
                        UpgradeScreenDict[ShopItemCategory.Shield].PurchasableItemSlot.SetShopItem(_ItemUpgradeDict[ShopItemCategory.Shield][lastItemIndex], true);
                        
                        //UpgradeScreenDict[ShopItemCategory.Shield].PurchasableItemSlot.Item = item;
                        UpgradeScreenDict[ShopItemCategory.Shield].PurchasableItemSlot.GetComponent<Button>().enabled = false;
                    }
                    else
                    {
                        UpgradeScreenDict[ShopItemCategory.Shield].PurchasableItemSlot.SetShopItem(_ItemUpgradeDict[ShopItemCategory.Shield][lastItemIndex + 1]);
                        //UpgradeScreenDict[ShopItemCategory.Shield].PurchasableItemSlot.Item = _ShieldList[lastItemIndex + 1].Items[0];
                        //UpgradeScreenDict[ShopItemCategory.Shield].PurchasableItemSlot.ItemsList = _ShieldList[lastItemIndex + 1].Items;
                    }

                    break;
                default:
                    break;
            }
        }
    }

    /*public void SetStartingItemsOld()
    {
        foreach (Item item in GameManager.Instance.PlayerEquipments)
        {
            var lastItemIndex = 0;

            switch (item.ItemSlot)
            {
                case ItemSlot.Shoulder:
                    UpgradeScreenDict[ShopItemCategory.Armor].EquippedItemSlot.Item = item;

                    lastItemIndex = ArmorList.IndexOf(item);
                    if (ArmorList.Count == lastItemIndex + 1)
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
    }*/
}

[System.Serializable]
public class UpgradeScreen
{
    public ShopItem EquippedItemSlot;
    public ShopItem PurchasableItemSlot;
}

[System.Serializable]
public class ShopItemList
{
    public List<Item> Items;
    public Sprite ItemSprite;
    public Sprite ItemQualitySprite;
    public int ItemPrice;
}