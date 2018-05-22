#pragma once

#include <string>

namespace Server {

namespace WebSocket {

    class SocketAction {
    public:

        virtual std::string run(const std::string& msg) = 0;

    };

} // namespace WebSocket
} // namespace Server