using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ShopItem : MonoBehaviour
{
    public Image ItemImageUI;                                    // Reference to the image in main menu canvas
    public Image ItemQualityImageUI;                             // Reference to the quality of the item under item image
    public ShopItemCategory ItemCategory;
    public int ItemPrice;

    [SerializeField] private Item _item;                        // Item reference
    public Item Item
    {
        get { return _item; }
        set
        {
            _item = value;

            ItemImageUI.overrideSprite = _item.ItemSprite;
            ItemImageUI.SetNativeSize();

            ItemQualityImageUI.overrideSprite = _item.ItemQualitySprite;
            ItemQualityImageUI.SetNativeSize();

            ItemPrice = _item.ItemPrice;
        }
    }

    [HideInInspector] [SerializeField] private ShopPanel shopPanel;

    void OnValidate()
    {
        shopPanel = GetComponentInParent<ShopPanel>();    
    }

    public void UpgradeItem()
    {
        // TODO : Brings up if we want to buy page
        if(SpineControllerVersion.GameManager.Instance.Gold >= ItemPrice)
        {
            SpineControllerVersion.GameManager.Instance.GoldChange(-ItemPrice);

            shopPanel.ItemUpgrade(ItemCategory);
        }
    }
}

public enum ShopItemCategory
{
    Weapon,
    Shield,
    Armor
}
