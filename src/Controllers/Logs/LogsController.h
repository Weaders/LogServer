#pragma once

#include <string>
#include "./../../Services/LogsReader.h"
#include "./../../Server/Action.h"
#include "./../../Common/Config.h"
#include "LogsFilesAction.h"
#include "LogsMsgsAction.h"

namespace Controllers {

    namespace Logs {

        class LogsController {

        public:
            LogsController(const std::string&, const std::string&);
            std::shared_ptr<Server::Action> getLogsFiles();
            std::shared_ptr<Server::Action> getLogsMsgs();

        protected:
            std::shared_ptr<Services::LogsReader> logsReader = nullptr;
            std::shared_ptr<Server::Action> logsFilesAction = nullptr;
            std::shared_ptr<Server::Action> logsMsgsAction = nullptr;

        };

    }

}