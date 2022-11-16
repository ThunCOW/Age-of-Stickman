using SpineControllerVersion;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using static UnityEngine.GraphicsBuffer;


public class SmoothCameraFollow : MonoBehaviour
{
    public Transform cameraTarget;

    public Vector3 offset;
    public float damping;

    private Vector3 velocity = Vector3.zero;

    private Transform LeftWallPosition;
    private Transform RightWallPosition;

    bool canMoveCam;

    bool BossCameraActivated;

    void OnValidate()
    {
        /*if(LeftWallPosition == null || RightWallPosition == null)
        {
            GameObject go = GameObject.FindGameObjectWithTag("LevelBorders");
            if(go != null)
            {
                LeftWallPosition = go.transform.GetChild(0);
                RightWallPosition = go.transform.GetChild(1);
            }
        }*/
    }

    void Awake()
    {
        GameManager.Instance.SceneViewBordersParent = transform.GetChild(0).gameObject;
    }

    void Start()
    {
        LeftWallPosition = GameManager.Instance.LevelBordersParent.transform.GetChild(0);
        RightWallPosition = GameManager.Instance.LevelBordersParent.transform.GetChild(1);

        canMoveCam = true;

        if (GameManager.Instance != null)
        {
            cameraTarget = GameManager.Instance.Player.transform;
        }
        else
            cameraTarget = StickmanChampion.GameManager.Instance.Player.transform;

        StartCoroutine(WaitUntilPlayerReachesEnd());

        SpawnManager.SpearmasterSpawn += SpearmasterSpawn;
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        if(canMoveCam)
            CameraMovement();
    }

    // With this float we create a illusion of how close player is to end, once we reach end we change this distance so camera stays in one place and player can move around more
    float RightWallCheckAtEnd = 5;
    IEnumerator WaitUntilPlayerReachesEnd()
    {
        while(gameObject.transform.position.x < RightWallPosition.position.x - RightWallCheckAtEnd)
        {
            yield return new WaitForFixedUpdate();
        }

        Debug.Log("Player has reached end");

        //RightWallPosition.position = new Vector2(RightWallPosition.transform.position.x - 4, RightWallPosition.transform.position.y);
        RightWallCheckAtEnd += 4;

        PlayerController.hasPlayerReachedEndOfLevel = true;

        StartCoroutine(IsPlayerWaitingAtEnd());
    }
    
    IEnumerator IsPlayerWaitingAtEnd()
    {
        while (gameObject.transform.position.x >= RightWallPosition.position.x - RightWallCheckAtEnd)
        {
            yield return new WaitForFixedUpdate();
        }

        Debug.Log("Player has left end");

        //RightWallPosition.position = new Vector2(RightWallPosition.transform.position.x + 4, RightWallPosition.transform.position.y);
        RightWallCheckAtEnd -= 4;

        PlayerController.hasPlayerReachedEndOfLevel = false;

        StartCoroutine(WaitUntilPlayerReachesEnd());
    }

    void OnDestroy()
    {
        GameManager.Instance.SceneViewBordersParent = null;    
    }


    void CameraMovement()
    {
        if(BossCameraActivated)
        {
            if (GameManager.Instance.Player.target == null)
                return;
            Vector3 bossPos = GameManager.Instance.Player.target.transform.position;
            Vector3 cameraTargetPos = cameraTarget.transform.position;
            //float bossOffset = cameraTargetPos.x > bossPos.x ? bossPos.x - cameraTargetPos.x :  
            float bossOffset = bossPos.x - cameraTargetPos.x;

            Vector3 movePosition = new Vector3(cameraTarget.position.x + bossOffset / 2, transform.position.y, -10);
            transform.position = Vector3.SmoothDamp(transform.position, movePosition, ref velocity, damping);
        }
        else
        {
            //if(cameraTarget)
            if (gameObject.transform.position.x <= LeftWallPosition.position.x + 5)
            {
                if (cameraTarget.transform.position.x >= LeftWallPosition.position.x + 5)
                {
                    Vector3 movePosition = new Vector3(cameraTarget.position.x + offset.x, transform.position.y, -10);
                    transform.position = Vector3.SmoothDamp(transform.position, movePosition, ref velocity, damping);
                }
            }
            else if (gameObject.transform.position.x >= RightWallPosition.position.x - RightWallCheckAtEnd)
            {
                if (cameraTarget.transform.position.x <= RightWallPosition.position.x - RightWallCheckAtEnd)
                {
                    Vector3 movePosition = new Vector3(cameraTarget.position.x + offset.x, transform.position.y, -10);
                    transform.position = Vector3.SmoothDamp(transform.position, movePosition, ref velocity, damping);
                }
            }
            else
            {
                //Vector3 movePosition = target.position + offset;
                Vector3 movePosition = new Vector3(cameraTarget.position.x + offset.x, transform.position.y, -10);
                transform.position = Vector3.SmoothDamp(transform.position, movePosition, ref velocity, damping);
            }
        }
    }

    void SpearmasterSpawn()
    {
        StartCoroutine(SpearmasterSpawnInitialCameraMovement());
    }

    IEnumerator SpearmasterSpawnInitialCameraMovement()
    {
        canMoveCam = false;

        damping = 2;

        Vector3 cameraTargetPos = cameraTarget.position;
        float offset = 6.7f;
        Vector3 movePosition = new Vector3(cameraTarget.position.x + offset, transform.position.y, -10);

        float waitFor = 10;
        while(waitFor >= 0)
        {
            waitFor -= Time.deltaTime;
            transform.position = Vector3.SmoothDamp(transform.position, movePosition, ref velocity, damping);

            yield return new WaitForFixedUpdate();
        }
        canMoveCam = true;

        BossCameraActivated = true;

        damping = 0.5f;
    }
}