#pragma once
#include <d3d12.h>
#include <wrl.h>

using Microsoft::WRL::ComPtr;

class SimulationBase {
public:
    virtual void Initialize(ID3D12Device* device) = 0;
    virtual void Dispatch(ID3D12GraphicsCommandList* cmd) = 0;
    virtual void UpdateConstants(float dt) = 0;
    virtual ~SimulationBase() {}
};