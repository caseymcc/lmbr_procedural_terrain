

#include <ProceduralTerrainSystemComponent.h>

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

namespace ProceduralTerrain
{

void ProceduralTerrainSystemComponent::Reflect(AZ::ReflectContext* context)
{
    if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
    {
        serialize->Class<ProceduralTerrainSystemComponent, AZ::Component>()
            ->Version(0)
            ;

        if (AZ::EditContext* ec = serialize->GetEditContext())
        {
            ec->Class<ProceduralTerrainSystemComponent>("ProceduralTerrain", "[Description of functionality provided by this System Component]")
                ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                ;
        }
    }
}

void ProceduralTerrainSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
{
    provided.push_back(AZ_CRC("ProceduralTerrainService"));
}

void ProceduralTerrainSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
{
    incompatible.push_back(AZ_CRC("ProceduralTerrainService"));
}

void ProceduralTerrainSystemComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
{
    AZ_UNUSED(required);
}

void ProceduralTerrainSystemComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
{
    AZ_UNUSED(dependent);
}

void ProceduralTerrainSystemComponent::Init()
{
}

void ProceduralTerrainSystemComponent::Activate()
{
    ProceduralTerrainRequestBus::Handler::BusConnect();
}

void ProceduralTerrainSystemComponent::Deactivate()
{
    ProceduralTerrainRequestBus::Handler::BusDisconnect();
}

}//namespace ProceduralTerrain
