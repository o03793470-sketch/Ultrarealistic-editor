#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

// Простий каркас для роботи зі скриптами Xouip
struct ScriptManager {
    std::vector<std::string> scripts;  // Завантажені скрипти

    // Завантажує скрипт з файлу
    bool LoadScript(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) return false;

        std::string line;
        std::string code;
        while (std::getline(file, line)) {
            code += line + "\n";
        }
        scripts.push_back(code);
        file.close();
        return true;
    }

    // Виконує всі скрипти (поки що лише вивід на консоль)
    void ExecuteScripts() {
        for (auto& code : scripts) {
            std::cout << "Executing Xouip Script:\n" << code << std::endl;
            // Тут буде твій інтерпретатор Xouip
        }
    }
};