using System.Collections;
using System.Collections.Generic;
using UnityEngine.Serialization;
using UnityEngine;
using UnityEngine.SceneManagement;

[ExecuteInEditMode]
public class ParallaxGroup : MonoBehaviour
{
    // When pressed on editor it will reset background image positions relative to the order they are set as child
    public bool ResetPosition;
    [Space]

    public GameObject Cam;
    private float length, startPos;
    public float ParallaxEffect;
    
    public List<GameObject> ParallaxObjects = new List<GameObject>();


    void OnValidate()
    {
        if (ResetPosition)
        {
            ParallaxObjects.Clear();
            foreach(SpriteRenderer sr in transform.GetComponentsInChildren<SpriteRenderer>())
            {
                Transform obj = sr.transform;

                ParallaxObjects.Add(obj.gameObject);

                Debug.Log(ParallaxObjects.Count - 1 - (transform.childCount / 2));
                obj.position = new Vector3((ParallaxObjects.Count - 1 - (transform.childCount / 2)) * 19.2f, 0.3f, 0);
            }
            ResetPosition = false;
        }

        /*if(Cam == null)
        {
            foreach(Camera cam in FindObjectsOfType<Camera>())
            {
                if (cam.tag == "MainCamera")
                {
                    this.Cam = cam.gameObject;
                    break;
                }
            }
            if (Cam == null)
                Debug.LogError("Main Camera is missing in scene " + SceneManager.GetActiveScene().name);
        }*/

        if(ParallaxObjects.Count == 0)
        {
            for(int i = 0; i < transform.childCount; i++)
            {
                ParallaxObjects.Add(transform.GetChild(i).gameObject);
            }
        }
    }

    void Start()
    {
        length = ParallaxObjects[0].GetComponent<SpriteRenderer>().bounds.size.x;

        if (Cam == null)
        {
            foreach (Camera cam in FindObjectsOfType<Camera>())
            {
                if (cam.tag == "MainCamera")
                {
                    this.Cam = cam.gameObject;
                    break;
                }
            }
            if (Cam == null)
                Debug.LogError("Main Camera is missing in scene " + SceneManager.GetActiveScene().name);
        }
    }

    private int order, cycleTime;

    void Update()
    {
        float dist = (Cam.transform.position.x * ParallaxEffect);

        transform.position = new Vector3(-dist, transform.position.y, transform.position.z);
        
        if(Cam.transform.position.x + dist > length + (length * cycleTime))
        {
            ParallaxObjects[0].transform.position = new Vector3(  ParallaxObjects[0].transform.position.x + 
                                                                    length * ParallaxObjects.Count,
                                                                    ParallaxObjects[0].transform.position.y,
                                                                    ParallaxObjects[0].transform.position.z);
            
            List<GameObject> tempList = new List<GameObject>();
            for(int i = 1; i < ParallaxObjects.Count; i++)
            {
                tempList.Add(ParallaxObjects[i]);
            }
            tempList.Add(ParallaxObjects[0]);
            
            ParallaxObjects = tempList;
            
            cycleTime++;
        }
        else if(Cam.transform.position.x + dist < -length + (length * cycleTime))
        {
            ParallaxObjects[ParallaxObjects.Count - 1].transform.position = new Vector3(ParallaxObjects[ParallaxObjects.Count - 1].transform.position.x - 
                                                                    length * ParallaxObjects.Count,
                                                                    ParallaxObjects[ParallaxObjects.Count - 1].transform.position.y,
                                                                    ParallaxObjects[ParallaxObjects.Count - 1].transform.position.z);
            
            List<GameObject> tempList = new List<GameObject>();
            for(int i = 0; i < ParallaxObjects.Count - 1; i++)
            {
                tempList.Add(ParallaxObjects[i]);
            }
            tempList.Insert(0, ParallaxObjects[ParallaxObjects.Count - 1]);
            
            ParallaxObjects = tempList;
            
            cycleTime--;
        }
    }
}