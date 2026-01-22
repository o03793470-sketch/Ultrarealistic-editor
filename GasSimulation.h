#pragma once
#include "SimulationBase.h"
#include "SimulationTypes.h"

class GasSimulation : public SimulationBase {
public:
    void Initialize(ID3D12Device* device) override;
    void Dispatch(ID3D12GraphicsCommandList* cmd) override;
    void UpdateConstants(float dt) override;

private:
    ComPtr<ID3D12Resource> gridBuffer;
    ComPtr<ID3D12PipelineState> pso;
};