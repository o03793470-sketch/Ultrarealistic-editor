struct FluidParticle {
    float3 position;
    float3 velocity;
    float density;
    float pressure;
};

RWStructuredBuffer<FluidParticle> Particles : register(u0);

cbuffer Params : register(b0) {
    float dt;
};

[numthreads(256,1,1)]
void CSMain(uint id : SV_DispatchThreadID)
{
    FluidParticle p = Particles[id];
    p.velocity.y -= 9.81 * dt;
    p.position += p.velocity * dt;
    Particles[id] = p;
}