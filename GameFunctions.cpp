#pragma once
#include <iostream>
#include <string>

// Основні функції для запуску гри та створення елементів UI/персонажів
struct GameFunctions {

    void StartGame() {
        std::cout << "Game is starting..." << std::endl;
        // Тут можна ініціалізувати сцену, камеру, основний цикл
    }

    void CreateUI(const std::string& uiName) {
        std::cout << "Creating UI: " << uiName << std::endl;
        // Можна створювати меню, кнопки, контролери
    }

    void CreateCharacter(const std::string& name) {
        std::cout << "Creating character: " << name << std::endl;
        // Створення персонажа з mesh, rig, animation chain
    }
};