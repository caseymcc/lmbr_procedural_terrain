#include "StdAfx.h"
#include "ProceduralTerrain/ProceduralTerrainComponent.h"

namespace ProceduralTerrain
{
    void ProceduralTerrainComponent::Activate()
    {
    }

    void ProceduralTerrainComponent::Deactivate()
    {
    }

    void ProceduralTerrainComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<ProceduralTerrainComponent, AZ::Component>()
                ->Version(1)
                ->Field("River", &ProceduralTerrainComponent::m_river);
        }

        if (AZ::BehaviorContext* behaviorContext = azrtti_cast<AZ::BehaviorContext*>(context))
        {
            behaviorContext->Class<ProceduralTerrainComponent>()->RequestBus("RiverRequestBus");
        }
    }

    void ProceduralTerrainComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        required.push_back(AZ_CRC("SplineService"));
        required.push_back(AZ_CRC("TransformService"));
    }
}
