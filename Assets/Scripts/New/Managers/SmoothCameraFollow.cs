using SpineControllerVersion;
using System.Collections;
using UnityEngine;


public class SmoothCameraFollow : MonoBehaviour
{
    private Camera gameCam;

    public Transform cameraTarget;

    public Vector3 offset;
    public float damping;

    private Vector3 velocity = Vector3.zero;

    private Transform LeftWallPosition;
    private Transform RightWallPosition;

    bool canMoveCam;

    bool BossCameraActivated;
    bool WideBossScreenActivated;

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
        gameCam = GetComponent<Camera>();

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

        SpawnManager.Instance.SpawnBossEvent += BossSpawn;
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        if(canMoveCam)
            CameraMovement();
    }
    void OnDestroy()
    {
        GameManager.Instance.SceneViewBordersParent = null;    
    }


    void CameraMovement()
    {
        if(WideBossScreenActivated)
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
        else if(BossCameraActivated)
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
                    Vector3 movePosition = new Vector3(cameraTarget.position.x, transform.position.y, -10);
                    transform.position = Vector3.SmoothDamp(transform.position, movePosition, ref velocity, damping);
                }
            }
            else if (gameObject.transform.position.x >= RightWallPosition.position.x - RightWallCheckAtEnd)
            {
                if (cameraTarget.transform.position.x <= RightWallPosition.position.x - RightWallCheckAtEnd)
                {
                    Vector3 movePosition = new Vector3(cameraTarget.position.x, transform.position.y, -10);
                    transform.position = Vector3.SmoothDamp(transform.position, movePosition, ref velocity, damping);
                }
            }
            else
            {
                //Vector3 movePosition = target.position + offset;
                Vector3 movePosition = new Vector3(cameraTarget.position.x, transform.position.y, -10);
                transform.position = Vector3.SmoothDamp(transform.position, movePosition, ref velocity, damping);
            }
        }
    }

    void BossSpawn(string BossTag)
    {
        switch (BossTag)
        {
            case GameManager.BIG_DEMON_SPAWN_TAG:
                StartCoroutine(MoveAllyUnitsRight());
                StartCoroutine(WideCameraSetup());
                break;
            case GameManager.DOUBLEAXEDEMON_SPAWN_TAG:
                StartCoroutine(MoveAllyUnitsRight());
                StartCoroutine(WalkTowardsBoss());
                break;
            default:
                StartCoroutine(InitialCameraSlide());
                break;
        }
    }
    IEnumerator WalkTowardsBoss()
    {
        canMoveCam = false;

        float offset = 14.4f + 6.7f;
        Vector3 movePosition = new Vector3(cameraTarget.position.x + offset, transform.position.y, -10);
        float targetY = transform.position.y;

        float waitFor = 10;
        while (waitFor >= 0)
        {
            waitFor -= Time.deltaTime;

            float s = 0f;

            transform.position = new Vector3(Vector3.SmoothDamp(transform.position, movePosition, ref velocity, 3).x,
                Mathf.SmoothDamp(transform.position.y, targetY, ref s, 0.6f), transform.position.z);

            yield return new WaitForFixedUpdate();
        }
        canMoveCam = true;

        BossCameraActivated = true;

        damping = 0.5f;
    }

    IEnumerator WideCameraSetup()
    {
        canMoveCam = false;

        float offset = 14.4f + 6.7f;
        Vector3 movePosition = new Vector3(cameraTarget.position.x + offset, transform.position.y, -10);
        float targetY = transform.position.y + this.offset.y;

        float waitFor = 10;
        while (waitFor >= 0)
        {
            waitFor -= Time.deltaTime;

            //Vector3.SmoothDamp(transform.position, movePosition, ref velocity, damping);

            float s = 0f;
            gameCam.orthographicSize = Mathf.SmoothDamp(gameCam.orthographicSize, 6.5f, ref s, 0.3f);

            transform.position = new Vector3(Vector3.SmoothDamp(transform.position, movePosition, ref velocity, 3).x, 
                Mathf.SmoothDamp(transform.position.y, targetY, ref s, 0.6f), transform.position.z);

            yield return new WaitForFixedUpdate();
        }
        canMoveCam = true;

        WideBossScreenActivated = true;
    }

    IEnumerator MoveAllyUnitsRight()
    {
        int direction = 1;
        int speed = 2;

        foreach (Unit unit in GameManager.Instance.AllyUnits)
        {
            unit.unitController.spineSkeletonAnimation.AnimationState.SetAnimation(1, unit.activeAnimations.Movement.SpineAnimationReference, true);
            Debug.Log("START POS : " + unit.transform.position.x);
        }
        float walkTime = 7;
        while(walkTime > 0)
        {
            walkTime -= Time.deltaTime;
            // Move Ally units towards where boss is going to be
            foreach (Unit unit in GameManager.Instance.AllyUnits)
            {
                unit.transform.position = new Vector3(unit.transform.position.x + ((int)direction * speed) * Time.deltaTime, unit.transform.position.y, unit.transform.position.z);
            }
            yield return new WaitForFixedUpdate();
        }

        foreach (Unit unit in GameManager.Instance.AllyUnits)
        {
            unit.unitController.spineSkeletonAnimation.AnimationState.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true);
            Debug.Log("END POS : " + unit.transform.position.x);
        }

        yield return new WaitForSeconds(7);
    }

    IEnumerator InitialCameraSlide()
    {
        canMoveCam = false;

        damping = 2;

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









    ///
    //********************************************* Wall Checks
    ///



    // With this float we create a illusion of how close player is to end, once we reach end we change this distance so camera stays in one place and player can move around more
    float RightWallCheckAtEnd = 5;
    IEnumerator WaitUntilPlayerReachesEnd()
    {
        while (gameObject.transform.position.x < RightWallPosition.position.x - RightWallCheckAtEnd)
        {
            yield return new WaitForFixedUpdate();
        }

        Debug.Log("Player has reached end");

        //RightWallPosition.position = new Vector2(RightWallPosition.transform.position.x - 4, RightWallPosition.transform.position.y);
        RightWallCheckAtEnd += 4;

        (GameManager.Instance.Player.unitController as PlayerController).hasPlayerReachedEndOfLevel = true;

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

        (GameManager.Instance.Player.unitController as PlayerController).hasPlayerReachedEndOfLevel = false;

        StartCoroutine(WaitUntilPlayerReachesEnd());
    }

}