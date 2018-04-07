#include "LogsLevelsController.h"

namespace Controllers {

    namespace LogsLevels {

        std::shared_ptr<Server::Action> LogsLevelsController::getLogLevels() {

            auto action = std::make_shared<GetLogsLevelsAction>();

            return action;

        }

    }

}