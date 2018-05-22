#include "SocketRoute.h"

namespace Server {

namespace WebSocket {

    SocketRoute::SocketRoute(const std::string& path, std::shared_ptr<SocketAction> action)
        : _path(path)
        , _action(action) {
    }

    std::string SocketRoute::getPath() {
        return this->_path;
    }
} // namespace WebSocket
} // namespace Server