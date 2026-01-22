struct GasCell {
    float3 velocity;
    float density;
    float temperature;
};

RWStructuredBuffer<GasCell> Grid : register(u0);

cbuffer Params : register(b0) {
    float dt;
};

[numthreads(8,8,8)]
void CSMain(uint3 id : SV_DispatchThreadID)
{
    uint index = id.x + id.y * 64 + id.z * 64 * 64;
    GasCell c = Grid[index];
    c.density *= 0.995;
    Grid[index] = c;
}