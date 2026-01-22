#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>

// Простий інтерпретатор мови Xouip
class XouipInterpreter {
public:
    XouipInterpreter() {}

    // Виконати скрипт
    void Execute(const std::string& code) {
        std::istringstream stream(code);
        std::string line;
        while (std::getline(stream, line)) {
            ExecuteLine(line);
        }
    }

private:
    // Карта змінних (для розширення)
    std::map<std::string, float> variables;

    // Виконання однієї строки
    void ExecuteLine(const std::string& line) {
        std::string cmd = Trim(line);

        if (cmd.empty() || cmd[0] == '#') return; // коментар

        // Розділити команду на слова
        std::istringstream ss(cmd);
        std::string token;
        ss >> token;

        if (token == "Character.Move") {
            float x, y, z;
            ss >> x >> y >> z;
            CharacterMove(x, y, z);
        }
        else if (token == "Character.Rotate") {
            float rx, ry, rz;
            ss >> rx >> ry >> rz;
            CharacterRotate(rx, ry, rz);
        }
        else if (token == "Character.Speak") {
            std::string message;
            std::getline(ss, message);
            TrimInPlace(message);
            CharacterSpeak(message);
        }
        else {
            std::cout << "Unknown Xouip command: " << token << std::endl;
        }
    }

    // --- Команди персонажа ---
    void CharacterMove(float x, float y, float z) {
        std::cout << "Moving character to (" << x << "," << y << "," << z << ")\n";
    }

    void CharacterRotate(float rx, float ry, float rz) {
        std::cout << "Rotating character by (" << rx << "," << ry << "," << rz << ")\n";
    }

    void CharacterSpeak(const std::string& msg) {
        std::cout << "Character says: " << msg << std::endl;
    }

    // --- Допоміжні функції ---
    static std::string Trim(const std::string& s) {
        const char* whitespace = " \t\n\r";
        size_t start = s.find_first_not_of(whitespace);
        if (start == std::string::npos) return "";
        size_t end = s.find_last_not_of(whitespace);
        return s.substr(start, end - start + 1);
    }

    static void TrimInPlace(std::string& s) {
        s = Trim(s);
        if (!s.empty() && s.front() == '"') s.erase(0, 1);
        if (!s.empty() && s.back() == '"') s.pop_back();
    }
};