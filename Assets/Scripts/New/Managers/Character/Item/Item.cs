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
    [Space]
    public int HealthBonus;
    public int DamageBonus;
    [Space]
    public int ItemPrice;
    public ItemSlot ItemSlot;
    public Sprite ItemSprite;
    public Sprite ItemQualitySprite;

    public List<SpineAttachment> front;
    public List<SpineAttachment> side;
    public List<SpineAttachment> back;
    public List<SpineAttachment> back2;

    void OnValidate()
    {
#if UNITY_EDITOR
        string path = AssetDatabase.GetAssetPath(this);
        id = AssetDatabase.AssetPathToGUID(path);
#endif
    }

    public Item InitiateItem()
    {
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