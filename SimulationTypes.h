#pragma once
#include <DirectXMath.h>

using namespace DirectX;

// ===== FLUID =====
struct FluidParticle {
    XMFLOAT3 position;
    XMFLOAT3 velocity;
    float density;
    float pressure;
};

// ===== GAS =====
struct GasCell {
    XMFLOAT3 velocity;
    float density;
    float temperature;
};

// ===== CLOTH =====
struct ClothVertex {
    XMFLOAT3 position;
    XMFLOAT3 velocity;
};