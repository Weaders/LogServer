#pragma once

#include "../../Server/Action.h"
#include "./GetLogsLevelsAction.h"
#include <memory>

namespace Controllers {

namespace LogsLevels {

    class LogsLevelsController {

    public:
        std::shared_ptr<Server::Action> getLogLevels();
    };

} // namespace LogsLevels

} // namespace Controllers