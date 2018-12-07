#pragma once

#include <AzCore/RTTI/RTTI.h>
#include <AzCore/RTTI/ReflectContext.h>

#include <AzCore/Memory/Memory.h>
#include <AzCore/Component/Component.h>

#include <FastNoiseSIMD/FastNoiseSIMD.h>

namespace ProceduralTerrain
{
    class ProceduralTerrain
    {
    public:
        AZ_RTTI(ProceduralTerrain, "{BF003199-CA47-4AAD-9643-AAF5218A31FB}");
        AZ_CLASS_ALLOCATOR_DECL

        virtual ~ProceduralTerrain() = default;
        static void Reflect(AZ::ReflectContext* context);

        virtual void Activate(AZ::EntityId entityId);
        virtual void Deactivate();

    private:
        void UpdateNoise();
        void UpdateTerrain();

        FastNoise::NoiseSIMD *m_noise;
        int m_noiseSeed;
        float m_noiseFrequency;

        int m_cellSize;
        int m_heightmapWidth;
        int m_heightmapHeight;

        std::vector<float> m_noiseMap;
    };
}