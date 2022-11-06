using StickmanChampion;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class FpsController : MonoBehaviour
{
    public Text fpsText;
    public float deltaTime;

    void OnValidate()
    {
        if (fpsText == null)
            fpsText = GetComponent<Text>();
    }

    void Start()
    {  
        StartCoroutine(FPSCounter());
    }

    void Update()
    {
        deltaTime += (Time.deltaTime - deltaTime) * 0.1f;
    }

    IEnumerator FPSCounter()
    {
        yield return new WaitForSeconds(1.5f);

        float fps = 1.0f / deltaTime;
        fpsText.text = "FPS: " + Mathf.Ceil(fps).ToString();

        StartCoroutine(FPSCounter());
    }
}
