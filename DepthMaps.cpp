#pragma once
#include <iostream>
#include <string>
#include <vector>

// Створення карт глибин для сцени
struct DepthMaps {

    std::vector<std::string> depthTextures;

    void AddDepthMap(const std::string& mapName) {
        depthTextures.push_back(mapName);
        std::cout << "Added depth map: " << mapName << std::endl;
        // Можна використовувати для SSAO, DOF, трасування променів
    }

    void GenerateDepthMaps() {
        for (auto& map : depthTextures) {
            std::cout << "Generating depth map: " << map << std::endl;
            // Генерація глибинних карт сцени
        }
    }
};