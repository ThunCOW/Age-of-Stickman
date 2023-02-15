using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class AchUnlock : MonoBehaviour
{
    public TMP_Text Ach_Title;
    public Image Ach_Img;

    public void DeleteAfterAnimEnd()
    {
        Destroy(gameObject);
    }
}
