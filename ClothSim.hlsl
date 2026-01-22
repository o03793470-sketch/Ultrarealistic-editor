RWStructuredBuffer<float3> Positions : register(u0);
RWStructuredBuffer<float3> Velocities : register(u1);

cbuffer Params : register(b0) {
    float dt;
};

[numthreads(256,1,1)]
void CSMain(uint id : SV_DispatchThreadID)
{
    float3 v = Velocities[id];
    float3 p = Positions[id];

    v.y -= 9.81 * dt;
    p += v * dt;

    Velocities[id] = v;
    Positions[id] = p;
}