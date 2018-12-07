#pragma once

#include <AzCore/base.h>
#include <AzCore/Component/Component.h>
#include <AzCore/RTTI/BehaviorContext.h>

#include "ProceduralTerrain.h"

namespace ProceduralTerrain
{
    class ProceduralTerrainEditorComponent
        : public AZ::Component
    {
    public:
        AZ_COMPONENT(ProceduralTerrainEditorComponent, "{9E4F68C1-5D51-4F1B-BAD5-6243D1D407B5}");
        ~ProceduralTerrainEditorComponent() override = default;

        void Activate() override;
        void Deactivate() override;

        static void Reflect(AZ::ReflectContext* context);

        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);

    private:
        //IEditor *m_editor;
        //CHeightMap *m_heigthMap;
        //
        //FastNoise::NoiseSIMD *m_noise;
        //int m_noiseSeed;
        //float m_noiseFrequency
        //
        //int m_cellSize;
        //int m_heighmapWidth;
        //int m_heighmapHeight;
        //
        //std::vector<float> m_noiseMap;
        ProceduralTerrain m_terrain;
    };
}