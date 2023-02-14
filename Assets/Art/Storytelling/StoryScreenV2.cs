using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class StoryScreenV2 : MonoBehaviour
{
    public RectTransform textGO;

    public float moveSpeed;
    public void FixedUpdate()
    {
        textGO.position = new Vector3(textGO.position.x, textGO.position.y + moveSpeed * Time.deltaTime, textGO.position.z);
    }

    public void _Button_SkipStory()
    {
        SceneLoader.Instance.canContinue = true;
    }
}
