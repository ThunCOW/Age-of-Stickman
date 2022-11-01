using Spine.Unity;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

[System.Serializable]
public class MercenaryUnit : MonoBehaviour
{
    public UnitHolder SpineUnitHolder;

    [Space]
    [SerializeField] Button HireMercenaryButton;

    [Space]
    Mercenary _currentMercenary = null;
    public Mercenary CurrentMercenary
    {
        get { return _currentMercenary; }
        set
        {
            _currentMercenary = value;

            if(CurrentMercenary == null)
            {
                HireMercenaryImage.SetActive(true);
                MercenaryGameobject.SetActive(false);
                HireMercenaryButton.interactable = true;
                
                return;
            }

            MercenaryGameobject.SetActive(true);
            HireMercenaryImage.SetActive(false);
            HireMercenaryButton.interactable = false;

            List<Item> mercenaryItems = CurrentMercenary.Unit.GetComponent<EquipmentManager>().startingItems;

            SpineUnitHolder.ChangeUnitEquipments(SpineUnitHolder, mercenaryItems);

            SpineUnitHolder.UnitObject.GetComponent<SkeletonGraphic>().AnimationState.SetAnimation(0, CurrentMercenary.PanelIdleAnimation.SpineAnimationReference, false);
        }
    }

    [Space]
    [SerializeField] GameObject HireMercenaryImage;
    [SerializeField] GameObject MercenaryGameobject;

    void Start()
    {
        if(CurrentMercenary == null)
        {
            HireMercenaryImage.SetActive(true);
            MercenaryGameobject.SetActive(false);
        }
        else
        {
            MercenaryGameobject.SetActive(true);
            HireMercenaryImage.SetActive(false);
        }
    }





    void OnEnable()
    {
        if(CurrentMercenary == null)
        {
            HireMercenaryImage.SetActive(true);
            MercenaryGameobject.SetActive(false);
            HireMercenaryButton.interactable = true;
        }
        else
        {
            MercenaryGameobject.SetActive(false);
            HireMercenaryImage.SetActive(true);
            HireMercenaryButton.interactable = false;

            List<Item> mercenaryItems = CurrentMercenary.Unit.GetComponent<EquipmentManager>().startingItems;

            SpineUnitHolder.ChangeUnitEquipments(SpineUnitHolder, mercenaryItems);

            SpineUnitHolder.UnitObject.GetComponent<SkeletonGraphic>().AnimationState.SetAnimation(0, CurrentMercenary.PanelIdleAnimation.SpineAnimationReference, false);
        }
    }
}
