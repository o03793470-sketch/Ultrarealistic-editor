#pragma once
#include <iostream>

// Реалістичний рендер сцени
struct RealisticRender {

    bool enableRealistic = false;

    void EnableRealisticMode() {
        enableRealistic = true;
        std::cout << "Realistic rendering enabled" << std::endl;
        // Підключення PBR, global illumination, HDR
    }

    void RenderScene() {
        if (!enableRealistic) {
            std::cout << "Rendering in standard mode..." << std::endl;
            return;
        }
        std::cout << "Rendering scene with realistic lighting, shadows and reflections..." << std::endl;
        // Тут можна застосувати реалістичний шейдер, текстури та карти глибин
    }
};