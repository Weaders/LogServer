#include "SocketConnection.h"
#include "FrameFactory.h"
#include "FrameReader.h"
#include <evdns.h>

namespace Server {
namespace WebSocket {

    SocketConnection::~SocketConnection() {
        evhttp_connection_free(this->_conn);
    }

    SocketConnection::SocketConnection(evhttp_connection* con)
        : _conn(con) {

        this->_reader = std::make_shared<FrameReader>();
        this->_writer = std::make_shared<FrameWriter>();
    }

    evhttp_connection* SocketConnection::getConnection() {
        return this->_conn;
    }

    std::shared_ptr<FrameReader> SocketConnection::getFrameReader() {
        return this->_reader;
    }

    std::shared_ptr<FrameWriter> SocketConnection::getFrameWriter() {
        return this->_writer;
    }

    void SocketConnection::sendMsg(const std::string& msg) {

        auto textFrame = WebSocket::FrameFactory::textFrame(msg);
        this->_writeToBuffer(textFrame);
    }

    void SocketConnection::_writeToBuffer(const Server::WebSocket::Frame& frame) {

        auto writer = this->getFrameWriter();
        writer->setFrame(frame);

        auto output = writer->output();
        auto bev = evhttp_connection_get_bufferevent(this->getConnection());

        bufferevent_write(bev, output.c_str(), output.size());
    }

    evutil_socket_t SocketConnection::getFd() {

        auto connectBuffer = evhttp_connection_get_bufferevent(this->_conn);
        return bufferevent_getfd(connectBuffer);
    }

    void SocketConnection::close() {

        if (this->state != CONNECTION_STATE::CLOSED && this->state != CONNECTION_STATE::CLOSING) {

            this->state = CONNECTION_STATE::CLOSING;
            this->_writeToBuffer(WebSocket::FrameFactory::closeFrame());
        }
    }

} // namespace WebSocket
} // namespace Server