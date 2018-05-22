#pragma once

#include "../../Server/Server.h"
#include "./MemoryInfoCurrent.h"

namespace Controllers {

namespace Memory {

    class MemoryController {

    public:
        MemoryController();
        std::shared_ptr<MemoryInfoCurrent> memoryDataAction();
    };

} // namespace Memory

} // namespace Controllers