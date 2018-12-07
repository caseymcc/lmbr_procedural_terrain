#include "StdAfx.h"

#include "ProceduralTerrainEditorComponent.h"
#include <AzCore/Serialization/SerializeContext.h>

#include <AzCore/Serialization/EditContext.h>

#include "EditorDefs.h"
#include <AzToolsFramework/API/ToolsApplicationAPI.h>
#include <AzToolsFramework/API/EditorVegetationRequestsBus.h>

#include <IEditor.h>
#include "Terrain/Heightmap.h"


namespace ProceduralTerrain
{

void ProceduralTerrainEditorComponent::Activate()
{
//    m_editor=nullptr;
//    m_noise=nullptr;
//
//    AzToolsFramework::EditorRequests::Bus::BroadcastResult(m_editor, &AzToolsFramework::EditorRequests::GetEditor);
//    m_heightmap=m_editor->GetHeightmap();
//
//    m_cellSize=heightmap->GetUnitSize();
//    m_heighmapWidth=heightmap->GetWidth();
//    m_heighmapHeight=heightmap->GetHeight();
//
//    m_noiseMap.resize(m_heightmapWidth*m_heightmapHeight);
//
//    NoiseSIMD::loadSimd("./");
//    size_t simdLevel=NoiseSIMD::GetFastestSIMD();
    m_terrain.Activate(GetEntityId());
}

void ProceduralTerrainEditorComponent::Deactivate()
{
//    if(m_noise != nullptr)
//        delete m_noise;
//    m_noise=nullptr;
    m_terrain.Activate(GetEntityId());
}

void ProceduralTerrainEditorComponent::Reflect(AZ::ReflectContext* context)
{
    if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
    {
        serializeContext->Class<ProceduralTerrainEditorComponent, AZ::Component>()
            ->Version(1)
            ->Field("Terrain", &ProceduralTerrainEditorComponent::m_terrain)
            ;

        if(auto editContext=serializeContext->GetEditContext())
        {
            editContext->Class<EditorRoadComponent>("Procedural Terrain", "Generate Terrain using noise functions")
                ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                ->Attribute(AZ::Edit::Attributes::Category, "Terrain")
                ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("Game", 0x232b318c))
                ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                ->DataElement(AZ::Edit::UIHandlers::Default, &EditorRoadComponent::m_terrain, "Terrain", "")
                ->Attribute(AZ::Edit::Attributes::Visibility, AZ::Edit::PropertyVisibility::ShowChildrenOnly)
                ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                ;
        }

    }

    if (AZ::BehaviorContext* behaviorContext = azrtti_cast<AZ::BehaviorContext*>(context))
    {
//            behaviorContext->Class<ProceduralTerrainEditorComponent>()->RequestBus("RiverRequestBus");
    }
}

void ProceduralTerrainEditorComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
{
//        required.push_back(AZ_CRC("SplineService"));
//        required.push_back(AZ_CRC("TransformService"));
}

}//namespace ProceduralTerrain
