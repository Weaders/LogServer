#pragma once

#include "SocketAction.h"
#include "SocketConnection.h"
#include <memory>

namespace Server {

namespace WebSocket {

    class SocketUserData {
    public:
        SocketUserData(std::shared_ptr<SocketConnection>, std::shared_ptr<SocketAction>);

        std::shared_ptr<SocketAction> getAction();
        std::shared_ptr<SocketConnection> getConn();

    protected:
        std::shared_ptr<SocketAction> _action;
        std::shared_ptr<SocketConnection> _conn;
    };

} // namespace WebSocket
} // namespace Server