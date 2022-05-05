using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;

[CustomEditor(typeof(Skill))]
public class SkillEditor : Editor
{
    /*public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();

        SerializedObject so = new SerializedObject(target);
        SerializedProperty listIndx = so.FindProperty("listIndx");
        SerializedProperty animList = so.FindProperty("animList2");
        string[] test = animList.array;
        GUIContent arrayList = new GUIContent("animList2");
        listIndx = EditorGUILayout.Popup(arrayList, listIndx, animList);
        //bool test = EditorGUILayout.Foldout(true, "animList2", false);
    }*/
}
