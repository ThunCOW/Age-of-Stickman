using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;
using Spine.Unity;

[CreateAssetMenu(fileName = "Data", menuName = "SpineData/Spine Attachment", order = 1)]
public class SpineAnimationCustom : ScriptableObject
{
    public string AnimationName;
    public AnimationReferenceAsset AnimationReferenceAsset;

    public List<SpineAnimationAttachmentChange> SpineAttachmentChangeInformation;

    public List<SpineAnimationAttachmentChange> AfterAnimationAttachmentChangeInformation;

    void OnValidate()
    {
        if(AnimationReferenceAsset == null)
        {
            AnimationReferenceAsset tempObj = Resources.Load("ReferenceAssets/" + AnimationName, typeof(AnimationReferenceAsset)) as AnimationReferenceAsset;
            if(tempObj == null)
            {
                Debug.LogError("Animation Reference Asset is NOT found");
            }
            else
            {
                AnimationReferenceAsset = tempObj;
            }
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}

[System.Serializable]
public class SpineAnimationAttachmentChange
{
    // When an event is called, program will cycle through list of SpineAnimationAttachmentChange and check if EventName matches, if yes it will change

    public string EventName;            // Event name from animation
    public string SlotName;             // ItemSlot name
    public string AttachmentName;       // This will be filled with equipped item
    public bool IsRemovingAttachment;   // Is it removing the attachment
}