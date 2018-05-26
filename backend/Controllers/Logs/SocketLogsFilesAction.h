#pragma once

#include "../../Server/WebSocket/SocketAction.h"
#include "../../Services/LogsReader.h"

namespace Controllers {
namespace Logs {

    class SocketLogsFilesAction : public Server::WebSocket::SocketAction {

    public:
        SocketLogsFilesAction(const std::string&, std::shared_ptr<Server::WebSocket::SocketConnection>);
        void run(const std::string& msg) override;

    protected:
        std::shared_ptr<Services::LogsReader> _reader;
    };

} // namespace Logs
} // namespace Controllers