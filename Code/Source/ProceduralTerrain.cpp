#include "ProceduralTerrain.h"

#include <AzCore/RTTI/BehaviorContext.h>

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

namespace ProceduralTerrain
{

void ProceduralTerrain::Activate(AZ::EntityId entityId)
{
//    m_noise=nullptr;

//    IEditor *editor;
//    CHeightmap *heigthMap;

//    AzToolsFramework::EditorRequests::Bus::BroadcastResult(editor, &AzToolsFramework::EditorRequests::GetEditor);
//    heightmap=editor->GetHeightmap();
//
//    m_cellSize=heightmap->GetUnitSize();
//    m_heightmapWidth=heightmap->GetWidth();
//    m_heightmapHeight=heightmap->GetHeight();   

//    m_noiseMap.resize(m_heightmapWidth*m_heightmapHeight);
//
//    FastNoise::NoiseSIMD::loadSimd("./");
//    size_t simdLevel=FastNoise::NoiseSIMD::GetFastestSIMD();
}

void ProceduralTerrain::Deactivate()
{
//    if(m_noise!=nullptr)
//        delete m_noise;
//    m_noise=nullptr;
}

void ProceduralTerrain::Reflect(AZ::ReflectContext* context)
{
    if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
    {
        serializeContext->Class<ProceduralTerrain>()
            ->Version(1)
            ->Field("NoiseSeed", &ProceduralTerrain::m_noiseSeed)
            ->Field("NoiseFrequency", &ProceduralTerrain::m_noiseFrequency
        );

        if(auto editContext=serializeContext->GetEditContext())
        {
            editContext->Class<ProceduralTerrain>("Procedural Terrain", "Generate Terrain using noise functions")
                
                ->ClassElement(AZ::Edit::ClassElements::Group, "Noise")
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ->DataElement(AZ::Edit::UIHandlers::SpinBox, &ProceduralTerrain::m_noiseSeed, "Seed", "")
                        ->Attribute(AZ::Edit::Attributes::Min, std::numeric_limits<size_t>::min())
                        ->Attribute(AZ::Edit::Attributes::Max, std::numeric_limits<size_t>::max())
                        ->Attribute(AZ::Edit::Attributes::Step, 1)
                    ->DataElement(AZ::Edit::UIHandlers::Slider, &ProceduralTerrain::m_noiseFrequency, "Frequency", "")
                        ->Attribute(AZ::Edit::Attributes::Min, 0.0f)
                        ->Attribute(AZ::Edit::Attributes::Max, 10.f)
                        ->Attribute(AZ::Edit::Attributes::Step, 0.01f)
            ;
        }

    }

    if (AZ::BehaviorContext* behaviorContext = azrtti_cast<AZ::BehaviorContext*>(context))
    {
//            behaviorContext->Class<ProceduralTerrain>()->RequestBus("RiverRequestBus");
    }
}

void ProceduralTerrain::UpdateNoise()
{
//    if(m_noise!=nullptr)
//        delete m_noise;
//
//    m_noise=FastNoise::NoiseSIMD::New(m_noiseSeed);
}

void ProceduralTerrain::UpdateTerrain()
{
//    IEditor *editor;
//    CHeightmap *heigthMap;
//
//    AzToolsFramework::EditorRequests::Bus::BroadcastResult(editor, &AzToolsFramework::EditorRequests::GetEditor);
//    heightmap=editor->GetHeightmap();
//
//    heightmap->RecordAzUndoBatchTerrainModify(0, 0, m_heightmapWidth, m_heightmapHeight);
//    
//    m_noise->
//
//    for(int y=0; y<m_heightmapHeight, y++)
//    {
//        for(int x=0; x<m_heightmapWidth, x++)
//        {
//
//        }
//    }
}

AZ_CLASS_ALLOCATOR_IMPL(ProceduralTerrain, AZ::SystemAllocator, 0);

}//namespace ProceduralTerrain
