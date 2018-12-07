#pragma once

#include <AzCore/base.h>
#include <AzCore/Component/Component.h>
#include <AzCore/RTTI/BehaviorContext.h>

#include "ProceduralTerrain.h"

namespace ProceduralTerrain
{
    class ProceduralTerrainComponent
        : public AZ::Component
    {
    public:
        AZ_COMPONENT(ProceduralTerrainComponent, "{311F375E-7D16-42F4-B451-9E2F8AD3A35F}");
        ~ProceduralTerrainComponent() override = default;

        void Activate() override;
        void Deactivate() override;

        static void Reflect(AZ::ReflectContext* context);

        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);

    private:
        ProceduralTerrain m_terrain;
    };
}