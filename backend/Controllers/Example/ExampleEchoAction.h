#pragma once
#include <string>
#include "./../../Server/WebSocket/SocketAction.h"

namespace Controllers {
    namespace Example {

        class ExampleEchoAction : public Server::WebSocket::SocketAction {
        public:
            explicit ExampleEchoAction() = default;

            std::string run(const std::string &msg) override;


        };

    }
}