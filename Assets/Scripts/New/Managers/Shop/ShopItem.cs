using SpineControllerVersion;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class ShopItem : MonoBehaviour
{
    public Image ItemImageUI;                                    // Reference to the image in main menu canvas
    public Image ItemQualityImageUI;                             // Reference to the quality of the item under item image
    public GameObject MaxTextGameObject;

    [Space]
    public ShopItemCategory ItemCategory;

    [Space]
    [SerializeField] private Item _item;                        // Item reference
    public Item Item
    {
        get { return _item; }
        set
        {
            _item = value;
        }
    }

    // What is going on here is pretty much i wanted to make simple upgrade screen so a single upgrade item box with Item as identifier(key)
    // is being used to work with load and save system while ItemList is being used to upgrade/add items to PlayerEquipments in GameManager
    [Header("Items It Contains")]
    public List<Item> ItemsList;

    public virtual void SetShopItem(ShopItemList shopItemList, bool maxItemLevelReached = false)
    {
        Item = shopItemList.Items[0];

        ItemImageUI.overrideSprite = shopItemList.ItemSprite;
        ItemImageUI.SetNativeSize();

        ItemQualityImageUI.overrideSprite = shopItemList.ItemQualitySprite;
        ItemQualityImageUI.SetNativeSize();
        
        ItemsList = shopItemList.Items;

        if (maxItemLevelReached)
            MaxTextGameObject.SetActive(true);
    }
}

public enum ShopItemCategory
{
    Weapon,
    Shield,
    Armor
}
