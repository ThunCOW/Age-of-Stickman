using SpineControllerVersion;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MercenaryManager : MonoBehaviour
{
    public static MercenaryManager Instance;
    
    public List<MercenaryByRace> AllMercenaries;
    //public Dictionary<UnitRace, List<Mercenary>> dictAllMercenaries = new Dictionary<UnitRace, List<Mercenary>>();
    
    public List<MercenaryByLevel> MercenariesByLevel;
    public Dictionary<int, List<Mercenary>> dictAllMercenariesByLevel = new Dictionary<int, List<Mercenary>>();

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

                    //List<Mercenary> tempList = dictAllMercenaries[_mercenarySave[i].UnitRace];
                    //_mercenarySave[i].IndexOfMercenary = tempList.IndexOf(Mercenaries[i].CurrentMercenary);

                    int index = 0;
                    if(Mercenaries[i].CurrentMercenary.UnitType == UnitType.Swordsman)
                    {
                        index = 0;
                    }
                    else if(Mercenaries[i].CurrentMercenary.UnitType == UnitType.Spearsman)
                    {
                        index = 1;
                    }
                    else if(Mercenaries[i].CurrentMercenary.UnitType == UnitType.Archer)
                    {
                        index = 2;
                    }
                    _mercenarySave[i].IndexOfMercenary = index;
                }
            }

            return _mercenarySave;
        }
        set
        {
            _mercenarySave = value;

            StartCoroutine(WaitForGameManager());
        }
    }

    public List<AllyController> MercenarySpawns;

    void Awake()
    {
        Instance = this;

        foreach (MercenaryByRace Mercenaries in AllMercenaries)
        {
            //dictAllMercenaries.Add(Mercenaries.UnitRace, Mercenaries.MercenaryList);
        }

        foreach(MercenaryByLevel Mercenaries in MercenariesByLevel)
        {
            dictAllMercenariesByLevel.Add(Mercenaries.Level, Mercenaries.MercenaryList);
        }

        foreach (MercenaryUnit mercenaryUnit in Mercenaries)
            _mercenarySave.Add(new MercenarySave());
    }

    public void MercenaryDead(MercenaryUnit mercenaryUnit, AllyController allyController)
    {
        int orderOfDead = 0;
        for(int i = 0; i < MercenarySpawns.Count; i++)
        {
            if (MercenarySpawns[i] == allyController)
            {
                orderOfDead = i;
                break;
            }
        }
        for(int i = orderOfDead + 1; i < MercenarySpawns.Count; i++)
        {
            MercenarySpawns[i].DistanceToPlayer *= (float)i / (i + 1);
        }
        MercenarySpawns.RemoveAt(orderOfDead);

        Mercenaries[Mercenaries.IndexOf(mercenaryUnit)].CurrentMercenary = null;
    }

    public void MercenaryUpdate(UnitType unitType)
    {
        foreach(MercenaryUnit merc in Mercenaries)
        {
            if (merc.CurrentMercenary == null)
                continue;

            if(merc.CurrentMercenary.UnitType == unitType)
            {
                int lvl = 0;
                int currentMercIndex = 0;  // currently holds the index of current mercenary unit on panel, which found in if statements below, then next mercenary index is given further down below
                if (merc.CurrentMercenary.UnitType == UnitType.Swordsman)
                {
                    lvl = GameManager.Instance.SwordsmanUnitLevel;
                    currentMercIndex = 0;
                }
                else if (merc.CurrentMercenary.UnitType == UnitType.Spearsman)
                {
                    lvl = GameManager.Instance.SpearsmanUnitLevel;
                    currentMercIndex = 1;
                }
                else if (merc.CurrentMercenary.UnitType == UnitType.Archer)
                {
                    lvl = GameManager.Instance.ArcherUnitLevel;
                    currentMercIndex = 2;
                }
                
                List<Mercenary> mercenaryList = dictAllMercenariesByLevel[lvl];

                merc.CurrentMercenary = mercenaryList[currentMercIndex];
                //merc.UpdateUnit();
            }
        }
    }

    public IEnumerator WaitForGameManager()
    {
        while(GameManager.Instance == null)
            yield return new WaitForEndOfFrame();

        yield return new WaitForEndOfFrame();

        for (int i = 0; i < Mercenaries.Count; i++)
        {
            if (_mercenarySave[i].IndexOfMercenary == -1)
            {
                Mercenaries[i].CurrentMercenary = null;
                continue;
            }

            /*int lvl = 0;
            int currentMercIndex = 0;  // currently holds the index of current mercenary unit on panel, which found in if statements below, then next mercenary index is given further down below
            if (Mercenaries[i].CurrentMercenary.UnitType == UnitType.Swordsman)
            {
                lvl = GameManager.Instance.SwordsmanUnitLevel;
                currentMercIndex = 0;
            }
            else if (Mercenaries[i].CurrentMercenary.UnitType == UnitType.Spearsman)
            {
                lvl = GameManager.Instance.SpearsmanUnitLevel;
                currentMercIndex = 1;
            }
            else if (Mercenaries[i].CurrentMercenary.UnitType == UnitType.Archer)
            {
                lvl = GameManager.Instance.ArcherUnitLevel;
                currentMercIndex = 2;
            }

            List<Mercenary> mercenaryList = dictAllMercenariesByLevel[lvl];*/

            //List<Mercenary> tempList = dictAllMercenaries[_mercenarySave[i].UnitRace];
            List<Mercenary> tempList = new List<Mercenary>();
            if (_mercenarySave[i].IndexOfMercenary == 0)
            {
                tempList = dictAllMercenariesByLevel[GameManager.Instance.SwordsmanUnitLevel];
            }
            else if (_mercenarySave[i].IndexOfMercenary == 1)
            {
                tempList = dictAllMercenariesByLevel[GameManager.Instance.SpearsmanUnitLevel];
            }
            else if (_mercenarySave[i].IndexOfMercenary == 2)
            {
                tempList = dictAllMercenariesByLevel[GameManager.Instance.ArcherUnitLevel];
            }
            Mercenaries[i].CurrentMercenary = tempList[_mercenarySave[i].IndexOfMercenary];
        }
    }
}

[System.Serializable]
public class MercenaryByRace
{
    public UnitRace UnitRace;
    public List<Mercenary> MercenaryList = new List<Mercenary>();
}
[System.Serializable]
public class MercenaryByLevel
{
    public int Level;
    public List<Mercenary> MercenaryList = new List<Mercenary>();
}

[System.Serializable]
public class Mercenary 
{
    public GameObject Unit;
    public int Level;
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