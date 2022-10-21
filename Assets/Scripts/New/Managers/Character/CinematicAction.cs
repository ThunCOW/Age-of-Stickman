using Spine;
using Spine.Unity;
using UnityEngine;

public class  CinematicAction: MonoBehaviour
{
    [HideInInspector] public SkeletonAnimation skelAnim;

    public GameObject ShadowObject;
    public GameObject HealthBar;

    void OnValidate()
    {
        if (skelAnim == null) skelAnim = GetComponentInChildren<SkeletonAnimation>();
        
    }
    // Start is called before the first frame update
    void Start()
    {

        skelAnim.AnimationState.Event += HandleAnimationStateEvent;

        //skelAnim.state.SetAnimation(1, "Cinematic/Level_Entrance", false);
    }

    private void HandleAnimationStateEvent(TrackEntry trackEntry, Spine.Event e)
    {
        switch (e.Data.Name)
        {
            case "Game Event/Game_Pause":
                SpineControllerVersion.GameManager.Instance.GamePaused = true;

                Debug.Log(gameObject.name);
                ShadowObject.SetActive(false);
                HealthBar.SetActive(false);
                break;
            case "Game Event/Game_Continue":
                SpineControllerVersion.GameManager.Instance.GamePaused = false;

                ShadowObject.SetActive(true);
                HealthBar.SetActive(true);
                break;

            default:
                break;
        }
    }

    public SpeedDependantAnimation SpearmasterDead;
}