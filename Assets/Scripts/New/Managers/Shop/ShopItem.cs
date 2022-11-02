using SpineControllerVersion;
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
    public List<AudioClip> ItemSound;

    [HideInInspector] [SerializeField] private ShopPanel shopPanel;

    void OnValidate()
    {
        shopPanel = GetComponentInParent<ShopPanel>();    
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
