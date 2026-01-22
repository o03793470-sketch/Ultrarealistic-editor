#pragma once
#include "EditableMesh.cpp"
#include <DirectXMath.h>
using namespace DirectX;

enum GizmoMode { MOVE, ROTATE, SCALE };

// Інструмент Gizmo для переміщення, обертання, масштабу
struct GizmoTool {
    GizmoMode mode;
    XMFLOAT3 position;
    XMFLOAT3 rotation;
    XMFLOAT3 scale;

    void Apply(EditableMesh& mesh) {
        switch (mode) {
            case MOVE:
                for (auto& v : mesh.verticesCPU) {
                    v.x += position.x;
                    v.y += position.y;
                    v.z += position.z;
                }
                break;

            case SCALE:
                for (auto& v : mesh.verticesCPU) {
                    v.x *= scale.x;
                    v.y *= scale.y;
                    v.z *= scale.z;
                }
                break;

            case ROTATE: {
                XMMATRIX rot = XMMatrixRotationRollPitchYaw(
                    XMConvertToRadians(rotation.x),
                    XMConvertToRadians(rotation.y),
                    XMConvertToRadians(rotation.z)
                );
                for (auto& v : mesh.verticesCPU) {
                    XMVECTOR vert = XMLoadFloat3(&v);
                    vert = XMVector3Transform(vert, rot);
                    XMStoreFloat3(&v, vert);
                }
                break;
            }
        }
        mesh.UpdateGPU();
    }
};