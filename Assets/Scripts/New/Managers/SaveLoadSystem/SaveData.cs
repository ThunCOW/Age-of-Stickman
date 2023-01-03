using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[System.Serializable]
public class SaveData
{
    public List<int> equippedItemIndexs;

    public int PlayerLives;
    public int Gold;
    public int Level;
    public bool IsSpearmasterDead;

    public PlayerControls PlayerControls;

    //public List<Mercenary> Mercenaries = new List<Mercenary>();
    public List<MercenarySave> mercenarySaves;


    public int MusicVolume;
    public int SFXVolume;

    // might be temporary
    public int SwordUpgradeLevel;
    public int SpearUpgradeLevel;
    
    public int SwordsmanUnitLevel;
    public int SpearsmanUnitLevel;
    public int ArcherUnitLevel;
    //public static SaveData saveData = new SaveData();

    public string ToJson()
    {
        return JsonUtility.ToJson(this);
    }

    public void LoadFromJson(string a_Json)
    {
        JsonUtility.FromJsonOverwrite(a_Json, this);
    }

}

public interface ISaveableJson
{
    bool PopulateSaveData(SaveData a_SaveData);
    void LoadFromSaveData(SaveData a_SaveData);
}
