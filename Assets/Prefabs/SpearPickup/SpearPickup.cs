using SpineControllerVersion;
using System.Collections;
using UnityEngine;

public class SpearPickup : MonoBehaviour
{
    [HideInInspector] public Unit parentUnit;         // The unit that dropped the spear

    public ItemWeapon Spear;
    [Space]
    public float DefaultAlpha;
    [Space]
    public GameObject SpearProjectilePrefab;

    GameObject PickupIcon;

    bool _isShown = false;
    public bool IsShown
    {
        get { return _isShown; }
        set 
        {
            _isShown = value;
            
            if(!_isShown)
            {
                ShownAlpha.a = 0;
                StopAllCoroutines();

                sr.color = ShownAlpha;
                
                PickupIcon.SetActive(false);
            }
            else
            {
                ShownAlpha.a = DefaultAlpha;
                StartCoroutine(ChangeAlpha());
                
                PickupIcon.SetActive(true);
            }
            
        }
    }


    // Alpha change
    SpriteRenderer sr;
    Color ShownAlpha = Color.white;
    float waitForAlphaIncreaseAndDecrease = 5f;
    //float waitForNextChange = 5;

    // Clicking n Touching
    int _touchCount;
    int touchCount
    {
        get { return _touchCount; }
        set
        {
            // if bigger, that means a new touch happened, if smaller, that means touch is released
            if(value > touchCount)
            {
                Ray ray = Camera.main.ScreenPointToRay(Input.GetTouch(touchCount - 1).position);
                RaycastHit2D hit = Physics2D.GetRayIntersection(ray, 20);
                if (hit.collider != null)
                {
                    if (IsShown)
                    {
                        if (hit.transform.gameObject.tag == GameManager.SPEAR_PICKUP_TAG)
                        {
                            PickSpear();
                        }
                    }
                }
            }
            _touchCount = value;
        }
    }
    void Start()
    {
        sr = GetComponent<SpriteRenderer>();

        PickupIcon = transform.GetChild(0).gameObject;

        IsShown = false;

        transform.parent = null;
    }

    void Update()
    {
        if (Input.GetMouseButtonDown(0))
        {
            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
            RaycastHit2D hit = Physics2D.GetRayIntersection(ray, 20);
            if (hit.collider != null)
            {
                if (IsShown)
                {
                    if (hit.transform.gameObject.CompareTag(GameManager.SPEAR_PICKUP_TAG))
                    {
                        PickSpear();
                    }
                }
            }
        }

        if (touchCount != Input.touchCount)
        {
            touchCount = Input.touchCount;
        }
    }

    void PickSpear()
    {
        (GameManager.Instance.Player.unitController as PlayerController).PickupSpear();

        // Remove spear from parent unit's mainhand slot
        if (parentUnit != null)
            parentUnit.unitController.spineSkeletonAnimation.skeleton.SetAttachment(parentUnit.unitInventory.equippedItems[ItemSlot.MainHand].front[0].SlotName, null);
        else
            Debug.LogError("parent unit is not set");

        Destroy(gameObject);
    }

    IEnumerator ChangeAlpha()
    {
        float tempCountdown = 0;

        while(tempCountdown < waitForAlphaIncreaseAndDecrease / 2)
        {
            tempCountdown += Time.deltaTime;

            float a = tempCountdown / (waitForAlphaIncreaseAndDecrease / 2);
            a = (a + DefaultAlpha) > 1 ? 1 : a + DefaultAlpha;
            ShownAlpha.a = a;

            sr.color = ShownAlpha;

            yield return new WaitForFixedUpdate();
        }

        tempCountdown = waitForAlphaIncreaseAndDecrease / 2;
        while(tempCountdown >= 0)
        {
            tempCountdown -= Time.deltaTime;

            float a = tempCountdown / (waitForAlphaIncreaseAndDecrease / 2);
            a = a <= DefaultAlpha ? DefaultAlpha : a;
            ShownAlpha.a = a;

            sr.color = ShownAlpha;

            yield return new WaitForFixedUpdate();
        }
        
        //yield return new WaitForSeconds();
        
        StartCoroutine(ChangeAlpha());
    }
}
