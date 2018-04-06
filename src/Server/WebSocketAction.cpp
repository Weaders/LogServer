#include "WebSocketAction.h"

namespace Server {

    WebSocketAction::WebSocketAction(WebSocketConn *conn) {
        this->conn = conn;
    }

    void WebSocketAction::sendFrame(const std::string &msg) {
        this->conn->sendFrame(msg);
    }

}