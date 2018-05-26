#pragma once

#include "SocketConnection.h"
#include <string>

namespace Server {
namespace WebSocket {

    class SocketMsg {

    public:
        SocketMsg(const std::string&, std::shared_ptr<SocketConnection>);

        /**
         * Get msg that come from client
         * @return
         */
        std::string getMsg() const;

        /**
         * Return connection
         * @return
         */
        std::shared_ptr<SocketConnection> getConn() const;

    protected:
        std::string _msg;
        std::shared_ptr<SocketConnection> _conn;
    };

} // namespace WebSocket
} // namespace Server