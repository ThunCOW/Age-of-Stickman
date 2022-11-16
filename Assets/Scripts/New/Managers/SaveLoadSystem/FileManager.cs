using Newtonsoft.Json;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEngine;

public static class FileManager
{
    public static string SavePath => $"{Application.persistentDataPath}/saveJSON.dat";

    public static void WriteToFile(string state)
    {
        File.WriteAllText(SavePath, state);
    }

    public static bool LoadFromFile(out string json)
    {
        json = "";
        if (File.Exists(SavePath))
        {
            json = File.ReadAllText(SavePath);

            return true;
        }
        else
            return false;
    }
}
