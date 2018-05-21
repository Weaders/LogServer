#pragma once

#include "memory"
#include "string"

#include "SocketAction.h"

namespace Server {
namespace WebSocket {

    class SocketRoute {
    public:
        SocketRoute(const std::string&, std::shared_ptr<SocketAction>);
        std::string exec(const std::string&);

        std::string getPath();

    protected:
        std::shared_ptr<SocketAction> _action = nullptr;
        std::string _path = "";
    };
} // namespace WebSocket
} // namespace Server