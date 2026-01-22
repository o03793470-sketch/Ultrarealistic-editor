#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

// Базовий інтерпретатор GSD++/Xouip
class XouipCore {
public:
    XouipCore() {}

    // Завантажити скрипт з файлу .gsd++
    bool LoadScript(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) return false;

        std::string line;
        while (std::getline(file, line)) {
            TrimInPlace(line);
            if (!line.empty() && line[0] != '#')
                scriptLines.push_back(line);
        }
        file.close();
        return true;
    }

    // Виконати всі рядки скрипта
    void ExecuteScript() {
        for (auto& line : scriptLines) {
            ExecuteLine(line);
        }
    }

private:
    std::vector<std::string> scriptLines;

    // Просте виконання рядка
    void ExecuteLine(const std::string& line) {
        std::istringstream ss(line);
        std::string cmd;
        ss >> cmd;

        if (cmd == "Character.Create") {
            std::string name;
            ss >> name;
            CharacterCreate(name);
        }
        else if (cmd == "Character.SetPosition") {
            float x, y, z;
            ss >> x >> y >> z;
            CharacterSetPosition(x, y, z);
        }
        else if (cmd == "World.Generate") {
            int seed;
            ss >> seed;
            WorldGenerate(seed);
        }
        else if (cmd == "Animal.Spawn") {
            std::string name;
            float x, y;
            ss >> name >> x >> y;
            AnimalSpawn(name, x, y);
        }
        else {
            std::cout << "Unknown GSD++ command: " << cmd << std::endl;
        }
    }

    // --- Команди ядра ---
    void CharacterCreate(const std::string& name) {
        std::cout << "Created character: " << name << std::endl;
    }

    void CharacterSetPosition(float x, float y, float z) {
        std::cout << "Set character position to (" << x << "," << y << "," << z << ")" << std::endl;
    }

    void WorldGenerate(int seed) {
        std::cout << "Generating world with seed " << seed << std::endl;
    }

    void AnimalSpawn(const std::string& name, float x, float y) {
        std::cout << "Spawning animal: " << name << " at (" << x << "," << y << ")" << std::endl;
    }

    // --- допоміжна функція ---
    static void TrimInPlace(std::string& s) {
        const char* whitespace = " \t\n\r";
        size_t start = s.find_first_not_of(whitespace);
        if (start == std::string::npos) { s.clear(); return; }
        size_t end = s.find_last_not_of(whitespace);
        s = s.substr(start, end - start + 1);
    }
};