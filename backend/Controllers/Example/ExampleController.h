#pragma once

#include "./../../Server/WebSocket/SocketAction.h"
#include "./ExmapleEchoAction.cpp"
#include <memory>

namespace Controllers {
namespace Example {

    typedef SocAction Server::WebSocket::SocketAction;

    class ExampleController {
    public:
        ExampleController();

        SocAction getEchoAction();

    protected:
        std::shared_ptr<SocAction> _action;
    };

} // namespace Example
} // namespace Controllers