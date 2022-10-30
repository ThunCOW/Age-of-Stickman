using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MercenaryManager : MonoBehaviour
{
    public List<MercenaryByRace> AllMercenaries;
    public Dictionary<UnitRace, List<Mercenary>> dictAllMercenaries = new Dictionary<UnitRace, List<Mercenary>>();

    public List<MercenaryUnit> Mercenaries;

    void Awake()
    {
        foreach (MercenaryByRace Mercenaries in AllMercenaries)
        {
            dictAllMercenaries.Add(Mercenaries.UnitRace, Mercenaries.MercenaryList);
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    public void HireMercenary()
    {

    }
}

[System.Serializable]
public class MercenaryByRace
{
    public UnitRace UnitRace;
    public List<Mercenary> MercenaryList;
}

[System.Serializable]
public class Mercenary 
{
    public GameObject Unit;
    public int UnitPrice;
    public UnitType UnitType;
    public BasicAnimation UnitIdleAnimation;
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