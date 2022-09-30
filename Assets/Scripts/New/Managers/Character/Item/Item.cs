using System.Collections.Generic;
using UnityEditor;
using UnityEngine;

[CreateAssetMenu(menuName = "Items/Armor")]
public class Item : ScriptableObject
{
    [Header("Item Properties")]
    [SerializeField] string id;
    public string ID { get { return id; } }

    public string ItemName;
    public int ItemPrice;
    public ItemSlot ItemSlot;
    public Sprite ItemSprite;
    public Sprite ItemQualitySprite;

    public List<SpineAttachment> front;
    public List<SpineAttachment> side;
    public List<SpineAttachment> back;

    void OnValidate()
    {
#if UNITY_EDITOR
        string path = AssetDatabase.GetAssetPath(this);
        id = AssetDatabase.AssetPathToGUID(path);
#endif
    }

    public Item InitiateItem()
    {
        Debug.LogWarning("New Item Initiated");
        return Instantiate(this);
    }
}


[System.Serializable]
public class SpineAttachment
{
    public string SlotName;
    public string AttachmentName;
}

public enum ItemSlot
{
    Head,
    Shoulder,
    Leg,
    MainHand,
    Offhand,
    TwoHanded,
}

[System.Serializable]
public class SaveItem
{
    public string ID;

    public string ItemName;
    public int ItemPrice;
    public ItemSlot ItemSlot;
    public Sprite ItemSprite;
    public Sprite ItemQualitySprite;

    public List<SpineAttachment> front;
    public List<SpineAttachment> side;
    public List<SpineAttachment> back;

    public SaveItem(Item item)
    {
        ID = item.ID;

        ItemName = item.ItemName;
        ItemPrice = item.ItemPrice;
        ItemSlot = item.ItemSlot;
        ItemSprite = item.ItemSprite;
        ItemQualitySprite = item.ItemQualitySprite;

    }
}