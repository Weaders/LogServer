#pragma once

#include "../../Server/Server.h"
#include "../../Server/WebSocket/SocketAction.h"
#include "./../../Common/Config.h"
#include "./../../Server/Action.h"
#include "./../../Services/LogsReader.h"
#include "LogsFilesAction.h"
#include "LogsMsgsAction.h"
#include "SocketLogsFilesAction.h"
#include <string>

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
        std::shared_ptr<Server::WebSocket::SocketAction> socketFilesAction = nullptr;
    };

} // namespace Logs

} // namespace Controllers