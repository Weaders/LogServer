#include "SocketLogsFilesAction.h"
#include <iostream>

namespace Controllers {
namespace Logs {

    SocketLogsFilesAction::SocketLogsFilesAction(const std::string& path, std::shared_ptr<Server::WebSocket::SocketConnection> conn)
        : SocketAction(path, std::move(conn))
    {
//        this->_reader = std::make_shared(Ser)

    }

    void SocketLogsFilesAction::run(const std::string& msg) {

        if (msg == "close") {
            this->_conn->close();
        } else {

            this->_conn->sendMsg("TEST MSG");

        }

    }
} // namespace Logs
} // namespace Controllers
