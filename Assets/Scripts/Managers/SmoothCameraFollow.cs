using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class SmoothCameraFollow : MonoBehaviour
{
    public Transform target;
    public Vector3 offset;
    public float damping;

    private Vector3 velocity = Vector3.zero;
    
    void Start()
    {
        if (SpineControllerVersion.GameManager.Instance != null)
            target = SpineControllerVersion.GameManager.Instance.Player.transform;
        else
            target = StickmanChampion.GameManager.Instance.Player.transform;
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        //Vector3 movePosition = target.position + offset;
        Vector3 movePosition = new Vector3(target.position.x + offset.x, transform.position.y, -10);
        transform.position = Vector3.SmoothDamp(transform.position, movePosition, ref velocity, damping);
    }
}