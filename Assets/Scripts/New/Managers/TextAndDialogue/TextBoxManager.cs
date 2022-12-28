using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class TextBoxManager : MonoBehaviour
{
    public float BoxCentre;
    public float BoxSize;
    public string TextContext;
    public TMP_Text Text;
    private Color textColor;
    public float TextSize;

    public List<Image> ImageList;
    private Color imageColor;

    public AnimationCurve SmoothMovement;

    // AIController reads to know when text is completely spawned so can calculate time
    public bool IsEnded = false;
    void Awake()
    {
        GetComponent<Canvas>().worldCamera = Camera.main;        
    }

    public void ShowText(string context)
    {
        TextContext = context;
        Text.text = TextContext;
        float textDistanceToBoxBeginning = 1f;

        ImageList[0].rectTransform.sizeDelta = new Vector2(Text.preferredWidth + 100, ImageList[0].rectTransform.sizeDelta.y);

        ImageList[0].transform.position = new Vector3(ImageList[0].transform.position.x - (ImageList[0].rectTransform.sizeDelta.x * (20f / 2160)) / 2, ImageList[0].transform.position.y, 0);
        Text.transform.position = new Vector3((ImageList[0].transform.position.x - (ImageList[0].rectTransform.sizeDelta.x * (20f / 2160)) / 2) + textDistanceToBoxBeginning, Text.transform.position.y, 0);
        
        imageColor = ImageList[0].color;
        textColor = Text.color;

        imageColor.a = 0;
        textColor.a = 0;

        foreach (Image img in ImageList)
            img.color = imageColor;

        Text.color = textColor;

        StartCoroutine(TextBoxAppear());
    }
    
    IEnumerator TextBoxAppear()
    {
        StartCoroutine(DisplayLine(TextContext));

        float countdown = 0;
        float requiredTime = 1f;
        while (countdown < requiredTime)
        {
            countdown += Time.deltaTime;
            imageColor.a = (countdown / requiredTime);
            textColor.a = (countdown / requiredTime);

            foreach (Image img in ImageList)
                img.color = imageColor;

            Text.color = textColor;

            yield return new WaitForFixedUpdate();
        }
    }

    IEnumerator DisplayLine(string line)
    {
        float typingSpeed = 0.05f;
        Text.text = "";

        foreach(char letter in line.ToCharArray())
        {
            Text.text += letter;

            yield return new WaitForSeconds(typingSpeed);
        }

        yield return new WaitForSeconds(2.5f);

        StartCoroutine(TextBoxDisappear());
    }

    IEnumerator TextBoxDisappear()
    {
        IsEnded = true;

        StartCoroutine(TextBoxMovement(1, 1, 2));

        float countdown = 0;
        float requiredTime = 1f;
        while (countdown < requiredTime)
        {
            countdown += Time.deltaTime;
            imageColor.a = 1 - (countdown / requiredTime);
            textColor.a = 1 - (countdown / requiredTime);

            foreach (Image img in ImageList)
                img.color = imageColor;

            Text.color = textColor;

            yield return new WaitForFixedUpdate();
        }
    }

    IEnumerator TextBoxMovement(float travelingDist, float requiredTimeForMovement, float requiredTimeForScaleChange)
    {
        GameObject childObject = transform.GetChild(0).gameObject;
        float startingScale = childObject.transform.localScale.x;

        float startPosY = transform.position.y;


        float countdown = 0;
        while(countdown < requiredTimeForMovement)
        {
            countdown += Time.deltaTime;

            transform.position = new Vector3(transform.position.x, startPosY + (travelingDist * SmoothMovement.Evaluate(countdown / requiredTimeForMovement)), transform.position.z);
            childObject.transform.localScale = new Vector3(1 - (countdown / requiredTimeForScaleChange), 1 - (countdown / requiredTimeForScaleChange), 1) * startingScale;

            yield return new WaitForFixedUpdate();
        }

        Destroy(gameObject);
    }

    public void ShowTextBox(string context, int direction)
    {
        Text.text = context;
    }

    public void PopulateTextBox()
    {

    }

    public void HideTextBox()
    {

    }
}
