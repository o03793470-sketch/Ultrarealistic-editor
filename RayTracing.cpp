#pragma once
#include <iostream>

// Простий каркас для трасування променів
struct RayTracing {

    void EnableRayTracing() {
        std::cout << "Ray tracing enabled" << std::endl;
        // Тут можна підключити DX12 Raytracing (DXR)
    }

    void TraceScene() {
        std::cout << "Tracing scene rays..." << std::endl;
        // Тут будуть промені для відображення реалістичного світла
    }
};