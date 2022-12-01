using Spine;
using Spine.Unity;
using SpineControllerVersion;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;

public class  CinematicAction: MonoBehaviour
{
    [HideInInspector] public SkeletonAnimation skelAnim;

    public GameObject ShadowObject;
    public GameObject HealthBar;

    [SerializeField] List<MoveInGame> InGameMovements;



    [Header("Specific Animation Actions")]
    public SpeedDependantAnimation SpearmasterDead;
    public SpeedDependantAnimation SycthemasterDead;

    // Start is called before the first frame update
    void Start()
    {
        //skelAnim.AnimationState.Event += HandleAnimationStateEvent;

        //foreach(MoveInGame action in InGameMovements)
        //{
        //    if (action.activateWhen == Activate.OnStart)
        //        StartCoroutine(action.MoveOnStart(GetComponent<Unit>(), skelAnim));
        //}
    }

    [System.Serializable]
    public class MoveInGame
    {
        public float startingPoint;
        public float distance;
        private float endingPoint;
        public Activate activateWhen;

        public List<Button> DisabledGameObjects;

        public IEnumerator MoveOnStart(Unit unit, SkeletonAnimation skelAnim)
        {
            GameManager.Instance.DisableControls = true;

            Color c = Color.white;
            c.a /= 3;
            ColorBlock colorBlock = ColorBlock.defaultColorBlock;
            colorBlock.normalColor = c;
            foreach (Button go in DisabledGameObjects)
            {
                go.colors = colorBlock;
                go.interactable = false;
                go.GetComponent<EventTrigger>().enabled = false;
            }

            endingPoint = startingPoint + distance;

            unit.transform.position = new Vector2(startingPoint, unit.transform.position.y);

            skelAnim.state.SetAnimation(1, unit.activeAnimations.Movement.SpineAnimationReference, true);

            // Moving Right
            if(unit.transform.position.x < endingPoint)
            {
                int direction = 1;

                unit.transform.localScale = new Vector3(1, 1, 1);

                while(unit.transform.position.x < endingPoint)
                {
                    unit.transform.position = new Vector3(unit.transform.position.x + direction * unit.unitController.speed * Time.deltaTime, unit.transform.position.y, unit.transform.position.z);
                    
                    yield return new WaitForFixedUpdate();
                }
            }
            // Moving Left
            else
            {
                int direction = 1;

                unit.transform.localScale = new Vector3(-1, 1, 1);

                while (unit.transform.position.x > endingPoint)
                {
                    unit.transform.position = new Vector3(unit.transform.position.x + direction * unit.unitController.speed * Time.deltaTime, unit.transform.position.y, unit.transform.position.z);

                    yield return new WaitForFixedUpdate();
                }
            }

            skelAnim.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true);

            GameManager.Instance.DisableControls = false;

            c.a *= 3;
            colorBlock.normalColor = c;
            foreach (Button go in DisabledGameObjects)
            {
                go.colors = colorBlock;
                go.interactable = true;
                go.GetComponent<EventTrigger>().enabled = true;
            }
        }
    }

    //private void HandleAnimationStateEvent(TrackEntry trackEntry, Spine.Event e)
    //{
    //    switch (e.Data.Name)
    //    {
    //        case "Game Event/Game_Pause":
    //            GameManager.Instance.DisableControls = true;
    //            break;
    //        case "Game Event/Game_Continue":
    //            GameManager.Instance.DisableControls = false;
    //            break;
    //        case "Shadow Events/Shadow_Hide":
    //            ShadowObject.SetActive(false);
    //            break;
    //        case "Shadow Events/Shadow_Show":
    //            ShadowObject.SetActive(true);
    //            break;
    //        default:
    //            break;
    //    }
    //}

    public enum Activate
    {
        OnStart,
    }
}