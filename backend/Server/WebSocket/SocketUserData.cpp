#include "SocketUserData.h"

namespace Server {

namespace WebSocket {

    SocketUserData::SocketUserData(std::shared_ptr<Server::WebSocket::SocketConnection> conn,
        std::shared_ptr<Server::WebSocket::SocketAction> action)
        : _conn(conn)
        , _action(action) {
    }

    std::shared_ptr<SocketConnection> SocketUserData::getConn() {
        return this->_conn;
    }

    std::shared_ptr<SocketAction> SocketUserData::getAction() {
        return this->_action;
    }

} // namespace WebSocket

} // namespace Server