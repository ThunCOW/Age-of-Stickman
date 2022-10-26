using Spine;
using Spine.Unity;
using SpineControllerVersion;
using UnityEngine;

public class  CinematicAction: MonoBehaviour
{
    [HideInInspector] public SkeletonAnimation skelAnim;

    public GameObject ShadowObject;
    public GameObject HealthBar;





    [Header("Specific Animation Actions")]
    public SpeedDependantAnimation SpearmasterDead;




    void OnValidate()
    {
        if (skelAnim == null) skelAnim = GetComponentInChildren<SkeletonAnimation>();
        
    }
    // Start is called before the first frame update
    void Start()
    {
        GameManager.DisableAllControls += DisableControls;
        GameManager.EnableAllControls += EnableControls;

        skelAnim.AnimationState.Event += HandleAnimationStateEvent;

        //skelAnim.state.SetAnimation(1, "Cinematic/Level_Entrance", false);
    }

    private void HandleAnimationStateEvent(TrackEntry trackEntry, Spine.Event e)
    {
        switch (e.Data.Name)
        {
            case "Game Event/Game_Pause":
                GameManager.Instance.DisableControls = true;
                break;
            case "Game Event/Game_Continue":
                GameManager.Instance.DisableControls = false;
                break;

            case "Game Event/Spearmaster_Dead":
                GameManager.Instance.IsSpearmasterDead = true;
                GameManager.Instance.Player.GetComponent<EquipmentManager>().ShowSecondaryWeapon();
                GameManager.Instance.Player.currentStance = StanceList.Stand_B;

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

    void DisableControls()
    {
        HealthBar.SetActive(false);
    }

    void EnableControls()
    {
        if(GetComponent<Unit>().Health > 0)
            HealthBar.SetActive(true);
    }
}