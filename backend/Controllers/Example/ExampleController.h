#pragma once

#include "./../../Server/WebSocket/SocketAction.h"
#include "./ExampleEchoAction.h"
#include <memory>

namespace Controllers {
namespace Example {

    class ExampleController {
    public:
        ExampleController();

        std::shared_ptr<Server::WebSocket::SocketAction> getEchoAction();

    protected:
        std::shared_ptr<Server::WebSocket::SocketAction> _action;
    };

} // namespace Example
} // namespace Controllers