using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using UnityEngine;

public class SaveLoadManager : MonoBehaviour
{
    public string SavePath => $"{Application.persistentDataPath}/save.txt";

    public static SaveLoadManager Instance;

    void Awake()
    {
        if (Instance == null)
        {
            Instance = this;
        }
        else
            Destroy(this.gameObject);
    }

    [ContextMenu("Save")]
    void Save()
    {
        var state = LoadFile();
        SaveGame(state);
        SaveFile(state);
    }

    [ContextMenu("Load")]
    void Load()
    {
        var state = LoadFile();
        LoadGame(state);
    }

    void SaveFile(object state)
    {
        using (var stream = File.Open(SavePath, FileMode.Create))
        {
            var formatter = new BinaryFormatter();
            formatter.Serialize(stream, state);
        }
    }

    Dictionary<string, object> LoadFile()
    {
        if(!File.Exists(SavePath))
        {
            Debug.Log("No save file found!");
            return new Dictionary<string, object>();
        }

        using (FileStream stream = File.Open(SavePath, FileMode.Open))
        {
            var formatter = new BinaryFormatter();
            return (Dictionary<string, object>)formatter.Deserialize(stream);
        }
    }

    public void NewGame()
    {

    }

    public void SaveGame(Dictionary<string, object> state)
    {
        // Every GameObject with SaveableEntity and their ID is used to store in a dictionary
        foreach(var saveable in FindObjectsOfType<SaveableEntity>())
        {
            state[saveable.id] = saveable.SaveState();
        }
    }

    public void LoadGame(Dictionary<string, object> state)
    {
        foreach (var saveable in FindObjectsOfType<SaveableEntity>())
        {
            if(state.TryGetValue(saveable.id, out object savedState))
            {
                saveable.LoadState(savedState);
            }
        }
    }

    void OnApplicationQuit()
    {
        //SaveGame();    
    }
}
