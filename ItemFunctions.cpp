#pragma once
#include <iostream>
#include <string>

// Створення об'єктів, блокінг і взаємодія
struct ItemFunctions {

    void CreateItem(const std::string& itemName) {
        std::cout << "Creating item: " << itemName << std::endl;
        // Створення об'єкта у сцені
    }

    void CreateBlockingArea(const std::string& areaName) {
        std::cout << "Creating blocking area: " << areaName << std::endl;
        // Створення зон блокування для персонажів
    }
};