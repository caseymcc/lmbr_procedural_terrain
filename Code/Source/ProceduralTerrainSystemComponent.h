
#pragma once

#include <AzCore/Component/Component.h>

#include <ProceduralTerrain/ProceduralTerrainBus.h>

namespace ProceduralTerrain
{
    class ProceduralTerrainSystemComponent
        : public AZ::Component
        , protected ProceduralTerrainRequestBus::Handler
    {
    public:
        AZ_COMPONENT(ProceduralTerrainSystemComponent, "{3144D6BA-1226-43F6-BDDB-C9BA047E8C30}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

    protected:
        ////////////////////////////////////////////////////////////////////////
        // ProceduralTerrainRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
