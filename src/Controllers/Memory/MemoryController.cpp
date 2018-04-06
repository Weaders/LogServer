#include "MemoryController.h"

namespace Controllers {

    namespace Memory {

        MemoryController::MemoryController() {

        }

        std::shared_ptr<MemoryInfoCurrent> MemoryController::memoryDataAction() {

            auto action = std::make_shared<MemoryInfoCurrent>();
            return action;

        }

    }


}


