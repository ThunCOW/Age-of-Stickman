using SpineControllerVersion;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EndlessLevelManager : MonoBehaviour
{
    public List<Item> PlayerEquipments;

    void Awake()
    {
        GameManager.Instance.PlayerEquipments = PlayerEquipments;
    }
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
