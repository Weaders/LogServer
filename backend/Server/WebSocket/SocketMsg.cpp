#include "SocketMsg.h"

namespace Server {
namespace WebSocket {

    SocketMsg::SocketMsg(const std::string& msg, std::shared_ptr<Server::WebSocket::SocketConnection> conn)
        : _msg(msg)
        , _conn(conn) {
    }

    std::shared_ptr<SocketConnection> SocketMsg::getConn() const {
        return this->_conn;
    }

    std::string SocketMsg::getMsg() const {
        return this->_msg;
    }

} // namespace WebSocket
} // namespace Server