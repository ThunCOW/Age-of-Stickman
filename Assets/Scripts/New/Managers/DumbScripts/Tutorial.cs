using Spine.Unity;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;
using SpineControllerVersion;
using static UnityEngine.UI.CanvasScaler;
using UnityEngine.SceneManagement;

public class Tutorial : MonoBehaviour
{
    [Header("Unit Variables")]
    [SerializeField] public SkeletonAnimation skelAnim;
    [SerializeField] public Unit unit;
    private PlayerController playerController;

    [Header("Movement")]
    [SerializeField] MoveInGame OpeningMovement;

    void Start()
    {
        playerController = unit.unitController as PlayerController;

        if(SceneManager.GetActiveScene().name == "Level 1")
        {
            BasicControlsSelectionScreen();
        }
    }

    public void BasicControlsSelectionScreen()
    {
        
        StartCoroutine(MoveOnStart(OpeningMovement));
        
    }

    IEnumerator MoveOnStart(MoveInGame action)
    {
        GameManager.Instance.DisableControls = true;

        Color c = Color.white;
        c.a /= 3;
        ColorBlock colorBlock = ColorBlock.defaultColorBlock;
        colorBlock.normalColor = c;
        foreach (Button go in playerController.ControlButtons)
        {
            go.colors = colorBlock;
            go.interactable = false;
            go.GetComponent<EventTrigger>().enabled = false;
        }
        foreach (Image go in playerController.JoystickImages)
        {
            go.color = c;
            go.raycastTarget = false;
        }

        action.endingPoint = action.startingPoint + action.distance;
        unit.transform.position = new Vector2(action.startingPoint, unit.transform.position.y);

        skelAnim.state.SetAnimation(1, unit.activeAnimations.Movement.SpineAnimationReference, true);

        // Moving Right
        if (unit.transform.position.x < action.endingPoint)
        {
            int direction = 1;

            unit.transform.localScale = new Vector3(1, 1, 1);

            while (unit.transform.position.x < action.endingPoint)
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
            while (unit.transform.position.x > action.endingPoint)
            {
                unit.transform.position = new Vector3(unit.transform.position.x + direction * unit.unitController.speed * Time.deltaTime, unit.transform.position.y, unit.transform.position.z);
                yield return new WaitForFixedUpdate();
            }
        }
        skelAnim.state.SetAnimation(1, unit.activeAnimations.idle.SpineAnimationReference, true);
        GameManager.Instance.DisableControls = false;
        c.a *= 3;
        colorBlock.normalColor = c;
        foreach (Button go in playerController.ControlButtons)
        {
            go.colors = colorBlock;
        }
        foreach (Image go in playerController.JoystickImages)
        {
            go.color = c;
        }

        SettingsManager.Instance.OpenChangeControlMenu();
    }

    [System.Serializable]
    public class MoveInGame
    {
        public float startingPoint;
        public float distance;
        [HideInInspector] public float endingPoint;
    }
}
