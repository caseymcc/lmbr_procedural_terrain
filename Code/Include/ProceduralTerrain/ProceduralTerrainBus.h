
#pragma once

#include <AzCore/EBus/EBus.h>

namespace ProceduralTerrain
{
    class ProceduralTerrainRequests
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static const AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////

        // Put your public methods here
    };
    using ProceduralTerrainRequestBus = AZ::EBus<ProceduralTerrainRequests>;
} // namespace ProceduralTerrain
