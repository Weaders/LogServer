#include "ExampleController.h"
#include "ExampleEchoAction.h"

namespace Controllers {

namespace Example {

    ExampleController::ExampleController() {
        this->_action = std::make_shared<ExampleEchoAction>();
    }

    std::shared_ptr<Server::WebSocket::SocketAction> ExampleController::getEchoAction() {
        return this->_action;
    }

} // namespace Example

} // namespace Controllers