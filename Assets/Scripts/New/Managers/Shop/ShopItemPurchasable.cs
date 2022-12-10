using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using SpineControllerVersion;

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

            TextGold.text = value.ToString();
        }
    }

    public List<AudioClip> ItemSound;

    [SerializeField] protected ShopPanel shopPanel;

    public override void SetShopItem(ShopItemList shopItemList, bool maxItemLevelReached = false)
    {
        base.SetShopItem(shopItemList, maxItemLevelReached);

        ItemPrice = shopItemList.ItemPrice;
    }

    public void UpgradeItem()
    {
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
}
