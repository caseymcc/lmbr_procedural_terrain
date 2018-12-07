
#include <platform_impl.h>

#include <AzCore/Memory/SystemAllocator.h>
//#include <AzCore/Module/Module.h>

#include <ProceduralTerrainModule.h>
#include <ProceduralTerrainSystemComponent.h>
#include <ProceduralTerrainComponent.h>
#ifdef EDITOR_MODULE
#include <ProceduralTerrainEditorComponent.h>
#endif

namespace ProceduralTerrain
{

ProceduralTerrainModule::ProceduralTerrainModule()
    : CryHooksModule()
{
    // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
    m_descriptors.insert(m_descriptors.end(), {
//            ProceduralTerrainSystemComponent::CreateDescriptor(),
        ProceduralTerrainComponent::CreateDescriptor()
    });

#ifdef EDITOR_MODULE
    m_descriptors.insert(m_descriptors.end(), {
        ProceduralTerrainEditorComponent::CreateDescriptor()
    });
#endif//EDITOR_MODULE
}

/**
    * Add required SystemComponents to the SystemEntity.
    */
AZ::ComponentTypeList ProceduralTerrainModule::GetRequiredSystemComponents() const
{
    return AZ::ComponentTypeList{
        azrtti_typeid<ProceduralTerrainSystemComponent>(),
    };
}

void ProceduralTerrainModule::OnCrySystemInitialized(ISystem& system, const SSystemInitParams& systemInitParams)
{
    CryHooksModule::OnCrySystemInitialized(system, systemInitParams);
}

}//namespace ProceduralTerrain

// DO NOT MODIFY THIS LINE UNLESS YOU RENAME THE GEM
// The first parameter should be GemName_GemIdLower
// The second should be the fully qualified name of the class above
AZ_DECLARE_MODULE_CLASS(ProceduralTerrain_409f2a934d6742b1a258f0e69359de4f, ProceduralTerrain::ProceduralTerrainModule)
