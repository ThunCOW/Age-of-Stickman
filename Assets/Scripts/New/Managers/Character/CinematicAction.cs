using Spine;
using Spine.Unity;
using SpineControllerVersion;
using UnityEngine;

public class  CinematicAction: MonoBehaviour
{
    [HideInInspector] public SkeletonAnimation skelAnim;

    public Item SpearmasterSpear;

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

            case "Game Event/Spearmaster_Dead":
                GameManager.Instance.IsSpearmasterDead = true;
                break;
            case "Shadow Events/Shadow_Hide":
                ShadowObject.SetActive(false);
                break;
            case "Shadow Events/Shadow_Show":
                ShadowObject.SetActive(true);
                break;
            default:
                break;
        }
    }

    public SpeedDependantAnimation SpearmasterDead;
}