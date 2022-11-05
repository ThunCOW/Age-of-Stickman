using SpineControllerVersion;
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

            ItemPrice = _item.ItemPrice;
        }
    }

    public List<AudioClip> ItemSound;

    // What is going on here is pretty much i wanted to make simple upgrade screen so a single upgrade item with Item as identifier(key)
    // is being used to work with load and save system while ItemList is being used to upgrade/add items to PlayerEquipments in GameManger
    [Header("Items It Contains")]
    public List<Item> ItemsList;

    [HideInInspector] [SerializeField] private ShopPanel shopPanel;

    void OnValidate()
    {
        shopPanel = GetComponentInParent<ShopPanel>();    
    }

    public void SetShopItem(ShopItemList shopItemList)
    {
        Item = shopItemList.Items[0];

        ItemImageUI.overrideSprite = shopItemList.ItemSprite;
        ItemImageUI.SetNativeSize();

        ItemQualityImageUI.overrideSprite = shopItemList.ItemQualitySprite;
        ItemQualityImageUI.SetNativeSize();
        
        ItemsList = shopItemList.Items;
    }

    public void UpgradeItem()
    {
        // TODO : Brings up if we want to buy page
        if(GameManager.Instance.Gold >= ItemPrice)
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

public enum ShopItemCategory
{
    Weapon,
    Shield,
    Armor
}
