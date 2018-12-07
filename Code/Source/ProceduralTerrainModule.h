
#include <IGem.h>

namespace ProceduralTerrain
{

class ProceduralTerrainModule
    :public CryHooksModule
{
public:
    AZ_RTTI(ProceduralTerrainModule, "{13E651F6-5CEA-40D1-B714-16BAD34FC46B}", CryHooksModule);
    AZ_CLASS_ALLOCATOR(ProceduralTerrainModule, AZ::SystemAllocator, 0);

    ProceduralTerrainModule();

    AZ::ComponentTypeList GetRequiredSystemComponents() const override;
    void OnCrySystemInitialized(ISystem& system, const SSystemInitParams& systemInitParams) override;
    
};

}//namespace ProceduralTerrain
