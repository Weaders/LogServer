#include "SocketConnection.h"
#include "FrameReader.h"

namespace Server {
namespace WebSocket {

    SocketConnection::~SocketConnection() {
        evhttp_connection_free(this->_conn);
    }

    SocketConnection::SocketConnection(evhttp_connection* con, std::shared_ptr<SocketAction> action) {

        this->_conn = con;
        this->_reader = std::make_shared<FrameReader>();
        this->_action = std::move(action);

    }

    std::shared_ptr<SocketAction> SocketConnection::getAction() {
        return this->_action;
    }

    evhttp_connection* SocketConnection::getConnection() {
        return this->_conn;
    }

    std::shared_ptr<FrameReader> SocketConnection::getFrameReader() {
        return this->_reader;
    }

    void SocketConnection::close() {
        this->state = CONNECTION_STATE ::CLOSED;
    }

} // namespace WebSocket
} // namespace Server