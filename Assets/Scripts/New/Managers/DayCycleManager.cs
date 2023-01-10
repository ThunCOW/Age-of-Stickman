using SpineControllerVersion;
using System.Collections.Generic;
using System.Linq;
using TMPro;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class DayCycleManager : MonoBehaviour
{
    public static DayCycleManager Instance;

    [SerializeField] Day day_A;
    [SerializeField] Day day_B;
    [SerializeField] Day day_C;
    [SerializeField] Day day_D;

    [Space]
    [SerializeField] RectTransform swordPointer_rect;

    int[] bossLevels = { 7, 18, 20, 25 };
    List<Day> days= new List<Day>();

    Color transparent;
    Color lit;
    // Start is called before the first frame update
    void Awake()
    {
        Instance = this;
    }
    
    void Start()
    {
        days.Add(day_A); 
        days.Add(day_B);
        days.Add(day_C);
        days.Add(day_D);

        transparent = day_A.DayValue_Text.color;
        lit = day_B.DayValue_Text.color;

        transparent.a = 0.49f;
        lit.a = 0.82f;

        SetCycle();
    }

    public void MoveCycle()
    {
        SetCycle();
    }

    public void SetCycle()
    {
        int i = 0;
        int dayVal = GameManager.Instance.Level;

        Debug.Log(dayVal + " " + SceneLoader.Instance.Levels.Count);
        if(dayVal + 3 > SceneLoader.Instance.Levels.Count)
        {
            i = SceneLoader.Instance.Levels.Count - 3;
            foreach(Day day in days)
            {
                day.DayValue_Text.text = i.ToString();

                if (bossLevels.Contains(i))
                    day.Day_Text.text = "(Boss) Day";
                else
                    day.Day_Text.text = "Day";
                i++;
            }

            int dif = (dayVal + 3) % SceneLoader.Instance.Levels.Count;
            Debug.Log(dif);

            days[dif - 1].Day_Text.color = transparent;
            days[dif - 1].DayValue_Text.color = transparent;
            days[dif].Day_Text.color = transparent;
            days[dif].DayValue_Text.color = transparent;
            days[dif + 1].Day_Text.color = lit;
            days[dif + 1].DayValue_Text.color = lit;

            float swordPosY = swordPointer_rect.anchoredPosition.y;
            swordPointer_rect.parent = days[dif + 1].DayValue_Text.transform.parent;
            swordPointer_rect.anchoredPosition = new Vector2(swordPointer_rect.anchoredPosition.x, swordPosY);
            // means hit the last day mark
            if(dif == 2)
            {
                swordPointer_rect.anchoredPosition = new Vector2(-300, swordPointer_rect.anchoredPosition.y);
            }
        }
        else
        {
            foreach (Day day in days)
            {
                // (Level)Day 0 will be hidden
                if(i == 0)
                {
                    if (GameManager.Instance.Level == 0)
                    {
                        day.DayValue_Text.transform.parent.gameObject.SetActive(false);
                    }
                    else
                    {
                        day.DayValue_Text.transform.parent.gameObject.SetActive(true);
                    }
                }
                else if(i == 1)
                {
                    day.Day_Text.color = lit;
                    day.DayValue_Text.color = lit;
                }
                else
                {
                    day.Day_Text.color = transparent;
                    day.DayValue_Text.color = transparent;
                }


                day.DayValue_Text.text = dayVal.ToString();
                if (bossLevels.Contains(dayVal))
                {
                    day.Day_Text.text = "(Boss) Day";
                    if (i == 1)
                    {
                        swordPointer_rect.anchoredPosition = new Vector2(-300, swordPointer_rect.anchoredPosition.y);
                    }
                }
                else
                {
                    day.Day_Text.text = "Day";
                    if (i == 1)
                    {
                        swordPointer_rect.anchoredPosition = new Vector2(-110, swordPointer_rect.anchoredPosition.y);
                    }
                }

                i++;
                dayVal++;
            }
        }
    }

    [System.Serializable]
    private class Day
    {
        public TMP_Text Day_Text;
        public TMP_Text DayValue_Text;
    }
}