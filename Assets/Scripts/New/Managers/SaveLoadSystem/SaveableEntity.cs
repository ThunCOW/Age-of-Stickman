using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SaveableEntity : MonoBehaviour
{
    [SerializeField] private string _id;
    public string id => _id;

    [ContextMenu("Generate ID")]
    private void GenerateId()
    {
        _id = Guid.NewGuid().ToString();
    }

    // Find all ISaveable component on current GameObject
    public object SaveState()
    {
        // Dictionary is being used here to store different saveable entity with key as their name
        var state = new Dictionary<string, object>();                       // String is the name of the component that implemented ISaveable class
        foreach(var saveable in GetComponents<ISaveable>())
        {
            state[saveable.GetType().ToString()] = saveable.SaveState();
        }

        return state;
    }

    public void LoadState(object state)
    {
        var stateDict = (Dictionary<string, object>)state;

        foreach (var saveable in GetComponents<ISaveable>())
        {
            string typeName = saveable.GetType().ToString();
            if(stateDict.TryGetValue(typeName, out object savedState))
            {
                saveable.LoadState(savedState);
            }
        }
    }
}
