#include "ProceduralTerrainComponent.h"
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

namespace ProceduralTerrain
{

void ProceduralTerrainComponent::Activate()
{
    m_terrain.Activate(GetEntityId());
}

void ProceduralTerrainComponent::Deactivate()
{
    m_terrain.Deactivate();
}

void ProceduralTerrainComponent::Reflect(AZ::ReflectContext* context)
{
    if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
    {
        serializeContext->Class<ProceduralTerrainComponent, AZ::Component>()
            ->Version(1)
            ->Field("Terrain", &ProceduralTerrainComponent::m_terrain)
        ;

        if(auto editContext=serializeContext->GetEditContext())
        {
            editContext->Class<ProceduralTerrainComponent>("Procedural Terrain", "Generate Terrain using noise functions")
                ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    ->Attribute(AZ::Edit::Attributes::Category, "Terrain")
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("Game", 0x232b318c))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                ->DataElement(AZ::Edit::UIHandlers::Default, &ProceduralTerrainComponent::m_terrain, "Terrain", "")
                    ->Attribute(AZ::Edit::Attributes::Visibility, AZ::Edit::PropertyVisibility::ShowChildrenOnly)
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
            ;
        }

    }

    if (AZ::BehaviorContext* behaviorContext = azrtti_cast<AZ::BehaviorContext*>(context))
    {
//            behaviorContext->Class<ProceduralTerrainComponent>()->RequestBus("RiverRequestBus");
    }
}

void ProceduralTerrainComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
{
//        required.push_back(AZ_CRC("SplineService"));
//        required.push_back(AZ_CRC("TransformService"));
}

}//namespace ProceduralTerrain
