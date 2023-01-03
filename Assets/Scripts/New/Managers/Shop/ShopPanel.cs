using SpineControllerVersion;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Serialization;
using UnityEngine.UI;

namespace ShopPanel_V2
{
    public class ShopPanel : MonoBehaviour
    {
        [Header("____________Slot Script Assignment_________")]
        public ShopItem SwordUpgrade;
        public ShopItem ShieldUpgrade;
        public ShopItem SpearUpgrade;
        public ShopItem ArmorUpgrade;

        public ShopItem SwordsmanUpgrade;
        public ShopItem SpearsmanUpgrade;
        public ShopItem ArcherUpgrade;
        public Dictionary<ShopItemCategory, ShopItem> UpgradeScreenDict = new Dictionary<ShopItemCategory, ShopItem>();

        [Header("____________Items Variables________________")]
        public List<ShopItemVariables> SwordList;
        public List<ShopItemVariables> SpearList;
        public List<ShopItemVariables> _ShieldList;
        public List<ShopItemVariables> _ArmorList;

        public List<ShopItemVariables> _SwordsmanList;
        public List<ShopItemVariables> _SpearsmanList;
        public List<ShopItemVariables> _ArcherList;
        public Dictionary<ShopItemCategory, List<ShopItemVariables>> _ItemUpgradeDict = new Dictionary<ShopItemCategory, List<ShopItemVariables>>();


        void Start()
        {
            UpgradeScreenDict.Add(ShopItemCategory.Sword, SwordUpgrade);
            UpgradeScreenDict.Add(ShopItemCategory.Spear, SpearUpgrade);
            UpgradeScreenDict.Add(ShopItemCategory.Shield, ShieldUpgrade);
            UpgradeScreenDict.Add(ShopItemCategory.Armor, ArmorUpgrade);

            UpgradeScreenDict.Add(ShopItemCategory.Swordsman, SwordsmanUpgrade);
            UpgradeScreenDict.Add(ShopItemCategory.Spearsman, SpearsmanUpgrade);
            UpgradeScreenDict.Add(ShopItemCategory.Archer, ArcherUpgrade);

            _ItemUpgradeDict.Add(ShopItemCategory.Sword, SwordList);
            _ItemUpgradeDict.Add(ShopItemCategory.Spear, SpearList);
            _ItemUpgradeDict.Add(ShopItemCategory.Armor, _ArmorList);
            _ItemUpgradeDict.Add(ShopItemCategory.Shield, _ShieldList);

            _ItemUpgradeDict.Add(ShopItemCategory.Swordsman, _SwordsmanList);
            _ItemUpgradeDict.Add(ShopItemCategory.Spearsman, _SpearsmanList);
            _ItemUpgradeDict.Add(ShopItemCategory.Archer, _ArcherList);

            SetStartingItems();
        }

        public void ItemUpgrade(ShopItemCategory shopItemCategory)
        {
            // Equip items
            for (int q = 0; q < UpgradeScreenDict[shopItemCategory].ItemsList.Count; q++)
            {
                bool newItem = true;
                // If there is an item in same slot just change it (did it this way cus dont wanna create another dict)
                for (int i = 0; i < GameManager.Instance.PlayerEquipments.Count; i++)
                {
                    if (GameManager.Instance.PlayerEquipments[i].ItemSlot == UpgradeScreenDict[shopItemCategory].ItemsList[q].ItemSlot)
                    {
                        newItem = false;
                        GameManager.Instance.PlayerEquipments[i] = UpgradeScreenDict[shopItemCategory].ItemsList[q];
                        break;
                    }
                }
                if (newItem) GameManager.Instance.PlayerEquipments.Add(UpgradeScreenDict[shopItemCategory].ItemsList[q]);
            }
            GameManager.Instance.mainMenuPlayer.ChangeUnitEquipments(GameManager.Instance.mainMenuPlayer, GameManager.Instance.PlayerEquipments);

            // Update Shop
            var lastItemIndex = -1;

            // Find index of item(next/upgrade)
            for (int i = 0; i < _ItemUpgradeDict[shopItemCategory].Count; i++)
            {
                bool indexFound = false;
                for (int u = 0; u < _ItemUpgradeDict[shopItemCategory][i].Items.Count; u++)
                {
                    if (_ItemUpgradeDict[shopItemCategory][i].Items[u] == UpgradeScreenDict[shopItemCategory].Item)
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

            if (_ItemUpgradeDict[shopItemCategory].Count <= lastItemIndex + 1)
            {
                // max item upgrade reached
                UpgradeScreenDict[shopItemCategory].GetComponent<Button>().enabled = false;
                UpgradeScreenDict[shopItemCategory].SetShopItem(_ItemUpgradeDict[shopItemCategory][lastItemIndex], true);
            }
            else
            {
                UpgradeScreenDict[shopItemCategory].SetShopItem(_ItemUpgradeDict[shopItemCategory][lastItemIndex + 1]);
            }

            if(shopItemCategory == ShopItemCategory.Spear)
            {
                GameManager.Instance.SpearUpgradeLevel++;

                if (GameManager.Instance.SpearUpgradeLevel >= SpearList.Count)
                {
                    // max item upgrade reached
                    SpearUpgrade.GetComponent<Button>().enabled = false;
                    SpearUpgrade.SetShopItem(SpearList[GameManager.Instance.SpearUpgradeLevel - 1], true);
                }
                else
                {
                    SpearUpgrade.SetShopItem(_ItemUpgradeDict[shopItemCategory][GameManager.Instance.SpearUpgradeLevel]);
                }
            }

            if(shopItemCategory == ShopItemCategory.Sword)
            {
                // since there is 5 weapon but 3 sword upgrade, sword lvl will be increased for certain upgrades only
                if(lastItemIndex == 2 || lastItemIndex == 3)
                    GameManager.Instance.SwordUpgradeLevel++;
            }
        }
        public void UnitUpgrade(ShopItemCategory shopItemCategory)
        {
            switch (shopItemCategory)
            {
                case ShopItemCategory.Swordsman:
                    GameManager.Instance.SwordsmanUnitLevel++;

                    if (GameManager.Instance.SwordsmanUnitLevel >= _SwordsmanList.Count)
                    {
                        // max item upgrade reached
                        UpgradeScreenDict[shopItemCategory].GetComponent<Button>().enabled = false;
                        UpgradeScreenDict[shopItemCategory].SetShopItem(_ItemUpgradeDict[shopItemCategory][GameManager.Instance.SwordsmanUnitLevel - 1], true);
                    }
                    else
                    {
                        UpgradeScreenDict[shopItemCategory].SetShopItem(_ItemUpgradeDict[shopItemCategory][GameManager.Instance.SwordsmanUnitLevel]);
                    }

                    break;
                case ShopItemCategory.Spearsman:
                    GameManager.Instance.SpearsmanUnitLevel++;

                    if (GameManager.Instance.SpearsmanUnitLevel >= _SpearsmanList.Count)
                    {
                        // max item upgrade reached
                        UpgradeScreenDict[shopItemCategory].GetComponent<Button>().enabled = false;
                        UpgradeScreenDict[shopItemCategory].SetShopItem(_ItemUpgradeDict[shopItemCategory][GameManager.Instance.SpearsmanUnitLevel - 1], true);
                    }
                    else
                    {
                        UpgradeScreenDict[shopItemCategory].SetShopItem(_ItemUpgradeDict[shopItemCategory][GameManager.Instance.SpearsmanUnitLevel]);
                    }

                    break;
                case ShopItemCategory.Archer:
                    GameManager.Instance.ArcherUnitLevel++;

                    if (GameManager.Instance.ArcherUnitLevel >= _ArcherList.Count)
                    {
                        // max item upgrade reached
                        UpgradeScreenDict[shopItemCategory].GetComponent<Button>().enabled = false;
                        UpgradeScreenDict[shopItemCategory].SetShopItem(_ItemUpgradeDict[shopItemCategory][GameManager.Instance.ArcherUnitLevel - 1], true);
                    }
                    else
                    {
                        UpgradeScreenDict[shopItemCategory].SetShopItem(_ItemUpgradeDict[shopItemCategory][GameManager.Instance.ArcherUnitLevel]);
                    }

                    break;
            }

            
        }
        public void SetStartingItems()
        {
            foreach (Item item in GameManager.Instance.PlayerEquipments)
            {
                var lastItemIndex = 0;

                switch (item.ItemSlot)
                {
                    case ItemSlot.Shoulder:

                        for (int i = 0; i < _ArmorList.Count; i++)
                        {
                            if (_ArmorList[i].Items.Contains(item))
                            {
                                lastItemIndex = i;
                                break;
                            }
                        }
                        ArmorUpgrade.SetShopItem(_ItemUpgradeDict[ShopItemCategory.Armor][lastItemIndex]);

                        if (_ArmorList.Count == lastItemIndex + 1)
                        {
                            // Max item upgrade reached
                            ArmorUpgrade.GetComponent<Button>().enabled = false;
                            ArmorUpgrade.SetShopItem(_ItemUpgradeDict[ShopItemCategory.Armor][lastItemIndex], true);
                        }
                        else
                        {
                            ArmorUpgrade.SetShopItem(_ItemUpgradeDict[ShopItemCategory.Armor][lastItemIndex + 1]);
                        }

                        break;
                    case ItemSlot.MainHand:
                        //UpgradeScreenDict[ShopItemCategory.Weapon].EquippedItemSlot.Item = item;

                        for (int i = 0; i < SwordList.Count; i++)
                        {
                            if (SwordList[i].Items.Contains(item))
                            {
                                lastItemIndex = i;
                                break;
                            }
                        }

                        if (SwordList.Count == lastItemIndex + 1)
                        {
                            // Max item upgrade reached
                            SwordUpgrade.GetComponent<Button>().enabled = false;
                            SwordUpgrade.SetShopItem(_ItemUpgradeDict[ShopItemCategory.Sword][lastItemIndex], true);
                        }
                        else
                        {
                            SwordUpgrade.SetShopItem(_ItemUpgradeDict[ShopItemCategory.Sword][lastItemIndex + 1]);
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

                        if (_ShieldList.Count == lastItemIndex + 1)
                        {
                            // Max item upgrade reached
                            ShieldUpgrade.GetComponent<Button>().enabled = false;
                            ShieldUpgrade.SetShopItem(_ItemUpgradeDict[ShopItemCategory.Shield][lastItemIndex], true);
                        }
                        else
                        {
                            ShieldUpgrade.SetShopItem(_ItemUpgradeDict[ShopItemCategory.Shield][lastItemIndex + 1]);
                        }

                        break;
                    default:
                        break;
                }
            }

            if (GameManager.Instance.SpearUpgradeLevel >= SpearList.Count)
            {
                // max item upgrade reached
                SpearUpgrade.GetComponent<Button>().enabled = false;
                SpearUpgrade.SetShopItem(SpearList[GameManager.Instance.SpearUpgradeLevel - 1], true);
            }
            else
            {
                SpearUpgrade.SetShopItem(SpearList[GameManager.Instance.SpearUpgradeLevel]);
            }

            SetStartingUnits();
        }

        public void SetStartingUnits()
        {
            //** Swordsman
            if (GameManager.Instance.SwordsmanUnitLevel >= _SwordsmanList.Count)
            {
                // max item upgrade reached
                SwordsmanUpgrade.GetComponent<Button>().enabled = false;
                SwordsmanUpgrade.SetShopItem(_ItemUpgradeDict[ShopItemCategory.Swordsman][GameManager.Instance.SwordsmanUnitLevel - 1], true);
            }
            else
            {
                SwordsmanUpgrade.SetShopItem(_ItemUpgradeDict[ShopItemCategory.Swordsman][GameManager.Instance.SwordsmanUnitLevel]);
            }

            //** Spearsman
            if (GameManager.Instance.SpearsmanUnitLevel >= _SpearsmanList.Count)
            {
                // max item upgrade reached
                SpearsmanUpgrade.GetComponent<Button>().enabled = false;
                SpearsmanUpgrade.SetShopItem(_ItemUpgradeDict[ShopItemCategory.Spearsman][GameManager.Instance.SpearsmanUnitLevel- 1], true);
            }
            else
            {
                SpearsmanUpgrade.SetShopItem(_ItemUpgradeDict[ShopItemCategory.Spearsman][GameManager.Instance.SpearsmanUnitLevel]);
            }

            //** Archer
            if (GameManager.Instance.ArcherUnitLevel >= _ArcherList.Count)
            {
                // max item upgrade reached
                ArcherUpgrade.GetComponent<Button>().enabled = false;
                ArcherUpgrade.SetShopItem(_ItemUpgradeDict[ShopItemCategory.Archer][GameManager.Instance.ArcherUnitLevel - 1], true);
            }
            else
            {
                ArcherUpgrade.SetShopItem(_ItemUpgradeDict[ShopItemCategory.Archer][GameManager.Instance.ArcherUnitLevel]);
            }
        }
    }

    [System.Serializable]
    public class ShopItemVariables
    {
        public List<Item> Items;
        public Sprite ItemSprite;
        public Sprite ItemQualitySprite;
        public int ItemPrice;
    }
}