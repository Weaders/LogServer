#include "SocketConnection.h"
#include "FrameReader.h"

namespace Server {
namespace WebSocket {

    SocketConnection::SocketConnection(evhttp_connection* con) {

        this->_conn = con;
        this->_reader = std::make_shared<FrameReader>();
    }

    evhttp_connection* SocketConnection::getConnection() {
        return this->_conn;
    }

    std::shared_ptr<FrameReader> SocketConnection::getFrameReader() {
        return this->_reader;
    }

    void SocketConnection::close() {
        // evhttp_connection_free(this->_conn);
    }

} // namespace WebSocket
} // namespace Server