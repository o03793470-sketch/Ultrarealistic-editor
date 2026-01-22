// ----------------------
// 3DScene.cpp
// ----------------------

// 1. Include і namespace
#include <d3d12.h>
#include <wrl.h>
#include <DirectXMath.h>
#include <vector>
using namespace DirectX;
using Microsoft::WRL::ComPtr;

// ----------------------
// 2. Структури даних
// ----------------------
struct FluidParticle { XMFLOAT3 position; XMFLOAT3 velocity; float density; float pressure; };
struct GasCell { XMFLOAT3 velocity; float density; float temperature; };
struct ClothVertex { XMFLOAT3 position; XMFLOAT3 velocity; };

// ----------------------
// 3. Клас сцени
// ----------------------
class Scene3D {
public:
    void Initialize(ID3D12Device* device);
    void Update(float dt);
    void Render(ID3D12GraphicsCommandList* cmd);

private:
    // Камера
    XMFLOAT3 cameraPos {0,2,-5};

    // Буфери для симуляцій
    ComPtr<ID3D12Resource> fluidBuffer;
    ComPtr<ID3D12Resource> gasBuffer;
    ComPtr<ID3D12Resource> clothBuffer;

    // Pipeline
    ComPtr<ID3D12PipelineState> computePSO;
    ComPtr<ID3D12PipelineState> graphicsPSO;
    ComPtr<ID3D12RootSignature> rootSignature;

    // Функції для ініціалізації
    void InitComputePipeline(ID3D12Device* device);
    void InitGraphicsPipeline(ID3D12Device* device);
};

// ----------------------
// 4. Реалізація
// ----------------------
void Scene3D::Initialize(ID3D12Device* device) {
    InitComputePipeline(device);
    InitGraphicsPipeline(device);

    // Створюємо буфери Fluid, Gas, Cloth тут
}

void Scene3D::Update(float dt) {
    // Update симуляцій, рухи об'єктів, камера
}

void Scene3D::Render(ID3D12GraphicsCommandList* cmd) {
    // Dispatch compute
    // Draw рендер
}