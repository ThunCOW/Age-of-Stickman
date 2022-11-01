using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MercenaryManager : MonoBehaviour
{
    public List<MercenaryByRace> AllMercenaries;
    public Dictionary<UnitRace, List<Mercenary>> dictAllMercenaries = new Dictionary<UnitRace, List<Mercenary>>();

    public static MercenaryManager Instance;

    public List<MercenaryUnit> Mercenaries;

    private List<MercenarySave> _mercenarySave = new List<MercenarySave>();
    public List<MercenarySave> MercenarySave
    {
        get
        {
            for(int i = 0; i < Mercenaries.Count; i++)
            {
                if (Mercenaries[i].CurrentMercenary == null)
                {
                    _mercenarySave[i].UnitRace = 0;
                    _mercenarySave[i].IndexOfMercenary = -1;
                }
                else
                {
                    _mercenarySave[i].UnitRace = Mercenaries[i].CurrentMercenary.UnitRace;
                    List<Mercenary> tempList = dictAllMercenaries[_mercenarySave[i].UnitRace];
                    _mercenarySave[i].IndexOfMercenary = tempList.IndexOf(Mercenaries[i].CurrentMercenary);
                }
            }

            return _mercenarySave;
        }
        set
        {
            _mercenarySave = value;

            for (int i = 0; i < Mercenaries.Count; i++)
            {
                if (_mercenarySave[i].IndexOfMercenary == -1)
                {
                    Mercenaries[i].CurrentMercenary = null;
                    continue;
                }

                List<Mercenary> tempList = dictAllMercenaries[_mercenarySave[i].UnitRace];
                Mercenaries[i].CurrentMercenary = tempList[_mercenarySave[i].IndexOfMercenary];
            }
        }
    }


    void Awake()
    {
        Instance = this;

        foreach (MercenaryByRace Mercenaries in AllMercenaries)
        {
            dictAllMercenaries.Add(Mercenaries.UnitRace, Mercenaries.MercenaryList);
        }

        foreach (MercenaryUnit mercenaryUnit in Mercenaries)
            _mercenarySave.Add(new MercenarySave());
    }

    public void MercenaryDead(MercenaryUnit mercenaryUnit)
    {
        Mercenaries[Mercenaries.IndexOf(mercenaryUnit)].CurrentMercenary = null;
    }
}

[System.Serializable]
public class MercenaryByRace
{
    public UnitRace UnitRace;
    public List<Mercenary> MercenaryList = new List<Mercenary>();
}

[System.Serializable]
public class Mercenary 
{
    public GameObject Unit;
    public int UnitPrice;
    public UnitType UnitType;
    public UnitRace UnitRace;
    public BasicAnimation PanelIdleAnimation;
    public BasicAnimation MainMenuIdleAnimation;
}

// This class is used to serialize mercenaries by their indexes in dictionary
[System.Serializable]
public class MercenarySave
{
    public UnitRace UnitRace;
    public int IndexOfMercenary;
}

public enum UnitType
{
    Swordsman,
    Spearsman,
    Archer,
    DualWielder,

}

public enum UnitRace
{
    Human,
    Elven,
    Demon,
}