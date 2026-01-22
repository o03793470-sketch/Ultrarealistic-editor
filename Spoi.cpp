// Spoi.cpp
#include <iostream>
#include "3DScene.h"     // Підключаємо основну сцену
#include "VbP.gsd@8.4"   // Бібліотека для текстур

class NormalMapTool {
public:
    NormalMapTool() {
        std::cout << "NormalMap Tool initialized." << std::endl;
    }

    // Завантаження текстури
    void LoadTexture(const std::string& filepath) {
        textureID = VbP::LoadTexture(filepath); // Використовуємо функцію з бібліотеки VbP
        if (textureID != 0)
            std::cout << "Texture loaded: " << filepath << std::endl;
        else
            std::cout << "Failed to load texture!" << std::endl;
    }

    // Застосування Normal Map до 3D об'єкта
    void ApplyNormalMap(Object3D& object) {
        object.SetNormalMap(textureID); // Функція сцени для прив’язки Normal Map
        std::cout << "Normal Map applied to object." << std::endl;
    }

private:
    unsigned int textureID;
};

// Приклад використання
void TestNormalMap() {
    Object3D cube("CubeModel"); // Створюємо 3D об'єкт
    NormalMapTool normalTool;

    normalTool.LoadTexture("textures/cube_normal.png");
    normalTool.ApplyNormalMap(cube);
}
