// Sowp.cs
using System;
using System.Collections.Generic;
using System.IO;

namespace GS6Tools
{
    public class Sowp
    {
        private List<string> loadedModels = new List<string>();

        // Імпорт 3D моделі (формат OBJ або GSD++)
        public void ImportModel(string filePath)
        {
            if (File.Exists(filePath))
            {
                loadedModels.Add(filePath);
                Console.WriteLine($"Model imported: {filePath}");
            }
            else
            {
                Console.WriteLine("File not found!");
            }
        }

        // Експорт 3D моделі
        public void ExportModel(string modelName, string exportPath)
        {
            string model = loadedModels.Find(m => Path.GetFileName(m) == modelName);
            if (!string.IsNullOrEmpty(model))
            {
                File.Copy(model, exportPath, true);
                Console.WriteLine($"Model exported to {exportPath}");
            }
            else
            {
                Console.WriteLine("Model not loaded!");
            }
        }

        // Показати усі імпортовані моделі
        public void ListModels()
        {
            Console.WriteLine("Loaded Models:");
            foreach (var model in loadedModels)
            {
                Console.WriteLine(model);
            }
        }
    }
}
