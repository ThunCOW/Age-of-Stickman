using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class StoryScreenV2 : MonoBehaviour
{
    public RectTransform textGO;

    public float moveSpeed;
    public void FixedUpdate()
    {
        textGO.anchoredPosition = new Vector3(textGO.anchoredPosition.x, textGO.anchoredPosition.y + moveSpeed * Time.deltaTime);
    }

    public void _Button_SkipStory()
    {
        SceneLoader.Instance.canContinue = true;
    }
}
