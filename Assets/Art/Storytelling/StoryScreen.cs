using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class StoryScreen : MonoBehaviour
{
    public string TextContext;

    public TMP_Text Text;

    public Image TransitionImage;
    

    public void Start()
    {
        StartCoroutine(Appear());
    }

    IEnumerator Appear()
    {
        Color c = TransitionImage.color;

        float countDownStart = 2f;
        float countDown = 0;
        while (countDown < countDownStart)
        {
            countDown += Time.deltaTime;

            c.a = countDown / countDownStart;

            TransitionImage.color = c;

            yield return new WaitForFixedUpdate();
        }
        c.a = 1;
        TransitionImage.color = c;

        StartCoroutine(Disappear());
    }
    IEnumerator Disappear()
    {
        yield return new WaitForSeconds(1.2f);

        Color c = TransitionImage.color;

        float countDownStart = 0.8f;
        float countDown = countDownStart;
        while(countDown > 0)
        {
            countDown -= Time.deltaTime;

            c.a = countDown / countDownStart;

            TransitionImage.color = c;

            if(countDown > 0.6f && Text.text == "")
            {
                StartCoroutine(DisplayLine(TextContext));
            }
            yield return new WaitForFixedUpdate();
        }
        c.a = 0f;
        TransitionImage.color = c;
    }

    IEnumerator DisplayLine(string line)
    {
        float typingSpeed = 0.03f;
        Text.text = "";

        foreach (char letter in line.ToCharArray())
        {
            if(letter == 'X')
            {
                Text.text += "\n\n";
                yield return new WaitForSeconds(typingSpeed);
                continue;
            }
            Text.text += letter;

            yield return new WaitForSeconds(typingSpeed);
        }
    }
}
