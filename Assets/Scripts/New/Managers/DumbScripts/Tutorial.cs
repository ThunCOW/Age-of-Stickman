using Spine.Unity;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;
using SpineControllerVersion;

public class Tutorial : MonoBehaviour
{
    [SerializeField] public SkeletonAnimation skelAnim;

    [SerializeField] List<MoveInGame> InGameMovements;

    void Start()
    {
        if(GameManager.Instance.Level == 0)
        {
            BasicControlsSelectionScreen();
        }
    }

    public void BasicControlsSelectionScreen()
    {
        foreach (MoveInGame action in InGameMovements)
        {
            StartCoroutine(action.MoveOnStart(GetComponent<Unit>(), skelAnim));
        }
    }

    [System.Serializable]
    public class MoveInGame
    {
        public float startingPoint;
        public float distance;
        private float endingPoint;

        public List<Button> DisabledGameObjects;
        public List<Image> Joystick;

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
            foreach (Image go in Joystick)
            {
                go.color = c;
                go.raycastTarget = false;
            }

            endingPoint = startingPoint + distance;

            unit.transform.position = new Vector2(startingPoint, unit.transform.position.y);

            skelAnim.state.SetAnimation(1, unit.activeAnimations.Movement.SpineAnimationReference, true);

            // Moving Right
            if (unit.transform.position.x < endingPoint)
            {
                int direction = 1;

                unit.transform.localScale = new Vector3(1, 1, 1);

                while (unit.transform.position.x < endingPoint)
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
            foreach (Image go in Joystick)
            {
                go.color = c;
                go.raycastTarget = true;
            }
        }
    }
}
