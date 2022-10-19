using System.Collections;
using System.Collections.Generic;
using Spine;
using Spine.Unity;
using UnityEngine;

public class  CinematicAction: MonoBehaviour
{
    public static CinematicAction Instance;

    public bool GamePaused;

    private SkeletonAnimation skelAnim;

    public GameObject ShadowObject;
    public GameObject HealthBar;

    // Start is called before the first frame update
    void Start()
    {
        Instance = this;

        skelAnim = GetComponentInChildren<SkeletonAnimation>();

        skelAnim.AnimationState.Event += HandleAnimationStateEvent;

        skelAnim.state.SetAnimation(1, "Cinematic/Level_Entrance", false);
    }

    private void HandleAnimationStateEvent(TrackEntry trackEntry, Spine.Event e)
    {
        switch (e.Data.Name)
        {
            case "Game Event/Game_Pause":
                GamePaused = true;
                
                ShadowObject.SetActive(false);
                HealthBar.SetActive(false);
                break;
            case "Game Event/Game_Continue":
                GamePaused = false;

                ShadowObject.SetActive(true);
                HealthBar.SetActive(true);
                break;

            default:
                break;
        }
    }
}