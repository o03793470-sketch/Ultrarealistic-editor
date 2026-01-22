#pragma once
#include <iostream>
#include <string>

struct LandscapeTool {
    void PaintTerrain(float x, float y, float height) {
        std::cout << "Painting terrain at (" << x << ", " << y << ") with height " << height << std::endl;
    }
};