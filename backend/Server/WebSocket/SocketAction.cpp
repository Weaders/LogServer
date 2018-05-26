#include "SocketAction.h"

namespace Server {

namespace WebSocket {

    SocketAction::SocketAction(const std::string& path, std::shared_ptr<WebSocket::SocketConnection> conn)
        : _path(path)
        , _conn(conn) {
    }

} // namespace WebSocket

} // namespace Server