using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class SmoothCameraFollow : MonoBehaviour
{
    public Transform target;
    public Vector3 offset;
    public float damping;

    private Vector3 velocity = Vector3.zero;

    public Transform LeftWallPosition;
    public Transform RightWallPosition;

    void OnValidate()
    {
        if(LeftWallPosition == null || RightWallPosition == null)
        {
            GameObject go = GameObject.FindGameObjectWithTag("LevelBorders");
            if(go != null)
            {
                LeftWallPosition = go.transform.GetChild(0);
                RightWallPosition = go.transform.GetChild(1);
            }
        }
    }

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
        if(gameObject.transform.position.x <= LeftWallPosition.position.x + 5)
        {
            if (target.transform.position.x >= LeftWallPosition.position.x + 5)
            {
                Vector3 movePosition = new Vector3(target.position.x + offset.x, transform.position.y, -10);
                transform.position = Vector3.SmoothDamp(transform.position, movePosition, ref velocity, damping);
            }
        }
        else if(gameObject.transform.position.x >= RightWallPosition.position.x -5)
        {
            if (target.transform.position.x <= RightWallPosition.position.x - 5)
            {
                Vector3 movePosition = new Vector3(target.position.x + offset.x, transform.position.y, -10);
                transform.position = Vector3.SmoothDamp(transform.position, movePosition, ref velocity, damping);
            }
        }
        else
        {
            //Vector3 movePosition = target.position + offset;
            Vector3 movePosition = new Vector3(target.position.x + offset.x, transform.position.y, -10);
            transform.position = Vector3.SmoothDamp(transform.position, movePosition, ref velocity, damping);
        }
    }
}