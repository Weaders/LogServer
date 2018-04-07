#pragma once

#include <memory>
#include "../../Server/Action.h"
#include "./GetLogsLevelsAction.h"

namespace Controllers {

    namespace LogsLevels {

        class LogsLevelsController {

        public:
            std::shared_ptr<Server::Action> getLogLevels();

        };

    }

}