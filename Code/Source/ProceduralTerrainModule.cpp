

#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include <ProceduralTerrainSystemComponent.h>
#include <ProceduralTerrain/ProceduralTerrainComponent.h>

namespace ProceduralTerrain
{

class ProceduralTerrainModule
    : public AZ::Module
{
public:
    AZ_RTTI(ProceduralTerrainModule, "{13E651F6-5CEA-40D1-B714-16BAD34FC46B}", AZ::Module);
    AZ_CLASS_ALLOCATOR(ProceduralTerrainModule, AZ::SystemAllocator, 0);

    ProceduralTerrainModule()
        : AZ::Module()
    {
        // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
        m_descriptors.insert(m_descriptors.end(), {
//            ProceduralTerrainSystemComponent::CreateDescriptor(),
            ProceduralTerrainComponent::CreateDescriptor()
        });
    }

    /**
        * Add required SystemComponents to the SystemEntity.
        */
    AZ::ComponentTypeList GetRequiredSystemComponents() const override
    {
        return AZ::ComponentTypeList{
            azrtti_typeid<ProceduralTerrainSystemComponent>(),
        };
    }
};

}//namespace ProceduralTerrain

// DO NOT MODIFY THIS LINE UNLESS YOU RENAME THE GEM
// The first parameter should be GemName_GemIdLower
// The second should be the fully qualified name of the class above
AZ_DECLARE_MODULE_CLASS(ProceduralTerrain_409f2a934d6742b1a258f0e69359de4f, ProceduralTerrain::ProceduralTerrainModule)
