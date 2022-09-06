using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ReachDistance : MonoBehaviour
{
    public bool FindDistance;
    private void OnValidate()
    {
        gameObject.name = (transform.localScale.x / 2).ToString();
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
