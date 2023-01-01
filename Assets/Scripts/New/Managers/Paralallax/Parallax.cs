using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[ExecuteInEditMode]
public class Parallax : MonoBehaviour
{
    public GameObject cam;

    public float parallaxEffect;
    
    
    void Update()
    {
        float temp = (cam.transform.position.x * (1 - parallaxEffect));
        float dist = (cam.transform.position.x * parallaxEffect);

        transform.position = new Vector3(- dist, transform.position.y, transform.position.z);
    }
}
