#pragma once

#include <string>
#include "WebSocketConn.h"

namespace Server {

    class WebSocketAction {

    public:

        WebSocketConn *conn;

        WebSocketAction(WebSocketConn *conn);

        virtual void onGetFrame(const std::string &msg) = 0;

        void sendFrame(const std::string &msg);

    };

}