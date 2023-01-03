using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using SpineControllerVersion;

namespace ShopPanel_V2
{
    public class ShopItemPurchasable : ShopItem
    {
        public TMP_Text TextGold;
        public int _itemPrice;
        public int ItemPrice
        {
            get { return _itemPrice; }
            set
            {
                _itemPrice = value;

                TextGold.text = value.ToString() + " Gold";
            }
        }

        public List<AudioClip> ItemSound;

        [SerializeField] protected ShopPanel shopPanel;

        public override void SetShopItem(ShopItemVariables shopItemList, bool maxItemLevelReached = false)
        {
            base.SetShopItem(shopItemList, maxItemLevelReached);

            ItemPrice = shopItemList.ItemPrice;
        }

        public void UpgradeItem()
        {
            Debug.Log("Upgrade Item Clicked");

            // Brings up if we want to buy page
            if (GameManager.Instance.Gold >= ItemPrice)
            {
                GameManager.Instance.GoldChange(-ItemPrice);

                shopPanel.ItemUpgrade(ItemCategory);

                SoundManager.Instance.PlayEffect(ItemSound[Random.Range(0, ItemSound.Count)]);
            }
            else
            {
                GameManager.Instance.NotEnoughGold();
            }
        }

        public void UpgradeSpear()
        {
            Debug.Log("Upgrade Spear Clicked");

            // Brings up if we want to buy page
            if (GameManager.Instance.Gold >= ItemPrice)
            {
                GameManager.Instance.GoldChange(-ItemPrice);

                shopPanel.ItemUpgrade(ItemCategory);

                SoundManager.Instance.PlayEffect(ItemSound[Random.Range(0, ItemSound.Count)]);
            }
            else
            {
                GameManager.Instance.NotEnoughGold();
            }
        }

        public void UpgradeUnit()
        {
            Debug.Log("Upgrade Unit Clicked");

            // Brings up if we want to buy page
            if (GameManager.Instance.Gold >= ItemPrice)
            {
                GameManager.Instance.GoldChange(-ItemPrice);

                shopPanel.UnitUpgrade(ItemCategory);

                SoundManager.Instance.PlayEffect(ItemSound[Random.Range(0, ItemSound.Count)]);
            }
            else
            {
                GameManager.Instance.NotEnoughGold();
            }
        }
    }
}