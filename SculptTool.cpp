#pragma once
#include "EditableMesh.cpp"
#include <DirectXMath.h>
using namespace DirectX;

// Brush для скульптингу (push/pull/smooth)
struct SculptTool {
    XMFLOAT3 position;    // Центр кисті
    float radius;         // Радіус дії
    float strength;       // Сила впливу

    void Apply(EditableMesh& mesh) {
        for (auto& v : mesh.verticesCPU) {
            XMFLOAT3 dir = { v.x - position.x, v.y - position.y, v.z - position.z };
            float dist = sqrtf(dir.x*dir.x + dir.y*dir.y + dir.z*dir.z);
            if (dist < radius) {
                float influence = (1.0f - dist / radius) * strength;
                v.x += dir.x * influence;
                v.y += dir.y * influence;
                v.z += dir.z * influence;
            }
        }
        mesh.UpdateGPU();
    }
};