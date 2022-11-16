using System.Collections;
using System.Collections.Generic;
using System.Xml;
using UnityEngine;

[CreateAssetMenu(menuName = "Spine Animation/Animation Info/Animation With Speed")]
[System.Serializable]
public class SpeedDependantAnimation : BasicAnimation, ISerializationCallbackReceiver
{
    public AnimationCurve speedCurve;
    public List<int> Keys = new List<int>();
    public List<float> Values = new List<float>();
    private Dictionary<int, float> KeyFrameDict = new Dictionary<int, float>();
    public bool SetupKeys;
    public void OnBeforeSerialize()
    {
        if (SetupKeys)
            return;
        Keys.Clear();
        Values.Clear();

        foreach(var keyframe in KeyFrameDict)
        {
            Keys.Add(keyframe.Key);
            Values.Add(keyframe.Value);
        }
    }

    public void OnAfterDeserialize()
    {
        if (SetupKeys)
            return;
        KeyFrameDict = new Dictionary<int, float>();

        for(int key = 0; key < Keys.Count; key++)
        {
            try
            {
                KeyFrameDict.Add(Keys[key], Values[key]);
            }
            catch { }
        }
    }
}
