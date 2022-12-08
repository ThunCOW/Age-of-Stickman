using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Spine.Unity;
using UnityEngine.Serialization;
using UnityEditor;
using System.IO;

[CreateAssetMenu(menuName = "Spine Animation/Animation Info/Base Animation")]
[System.Serializable]
public class BasicAnimation : ScriptableObject
{
    public string Prefix;                                               // The folder name where animations are in Spine
    public string AnimationName;                                        // Animation name to find auto
    public AnimationReferenceAsset SpineAnimationReference;             // Animation Reference
    public AnimationClip ShadowAnimation;                               // Adding shadow animations here

    [SerializeField]
    [HideInInspector]
    string _PrefixChangeCheck, _AnimationNameChangeCheck;

    void OnValidate()
    {
        AnimationReferenceAsset tempObj;
        
        //AssetDatabase.RenameAsset(AssetDatabase.GetAssetPath(this), Prefix + "_" + AnimationName);
        //AssetDatabase.Refresh();
        //this.name = Prefix + "_" + AnimationName;

        //tempObj = Resources.Load("ReferenceAssets/" + Prefix + "_" + AnimationName, typeof(AnimationReferenceAsset)) as AnimationReferenceAsset;
        //SpineAnimationReference = tempObj;

        if (_PrefixChangeCheck != Prefix || _AnimationNameChangeCheck != AnimationName)
        {
            AnimationReferenceAsset tempObj2 = Resources.Load("ReferenceAssets/"+ Prefix  + "_" + AnimationName, typeof(AnimationReferenceAsset)) as AnimationReferenceAsset;
            if (tempObj2 == null)
            {
                Debug.LogError("Animation Reference Asset is NOT found for ");
            }
            else
            {
                SpineAnimationReference = tempObj2;
                Debug.Log("Animation Reference Set");
            }

            _PrefixChangeCheck = Prefix;
            _AnimationNameChangeCheck = AnimationName;
        }
        if(SpineAnimationReference == null)
        {
            tempObj = Resources.Load("ReferenceAssets/" + Prefix + "_" + AnimationName, typeof(AnimationReferenceAsset)) as AnimationReferenceAsset;
            SpineAnimationReference = tempObj;
        }
    }

    void Reset()
    {
        Debug.Log("does this work");
    }

    public BasicAnimation InitializeSO()
    {
        return Instantiate(this);
    }
}

public enum AttackType
{
    Casual,
    Kick,
    Shield
}

public enum HitRegion
{
    High,
    Mid,
    Low,
    SpearThrowHead,
    SpearThrowBody,
    Arrow
}

public enum AnimationMovementType
{
    Stationary,
    NonStationary
}