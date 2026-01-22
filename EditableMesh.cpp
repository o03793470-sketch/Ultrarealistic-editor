#pragma once
#include <d3d12.h>
#include <wrl.h>
#include <DirectXMath.h>
#include <vector>

using namespace DirectX;
using Microsoft::WRL::ComPtr;

// Editable Mesh для редагування 3D об'єктів
struct EditableMesh {
    ComPtr<ID3D12Resource> vertexBuffer;      // GPU буфер
    std::vector<XMFLOAT3> verticesCPU;        // CPU вертекси для редагування
    D3D12_VERTEX_BUFFER_VIEW vbView;          // DX12 view
    UINT vertexCount;

    // Оновлення GPU буфера після змін на CPU
    void UpdateGPU() {
        void* mappedData = nullptr;
        vertexBuffer->Map(0, nullptr, &mappedData);
        memcpy(mappedData, verticesCPU.data(), vertexCount * sizeof(XMFLOAT3));
        vertexBuffer->Unmap(0, nullptr);
    }
};