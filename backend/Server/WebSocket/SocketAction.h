#pragma once
#include "SocketMsg.h"
#include <string>

namespace Server {

namespace WebSocket {

    class SocketAction {
    public:
        explicit SocketAction(const std::string&, std::shared_ptr<WebSocket::SocketConnection>);
        virtual void run(const std::string&) = 0;

    protected:
        std::string _path;
        std::shared_ptr<WebSocket::SocketConnection> _conn;
    };

} // namespace WebSocket
} // namespace Server