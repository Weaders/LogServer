#pragma once

#include "FrameReader.h"
#include "FrameWriter.h"
#include <event2/http.h>
#include <memory>

namespace Server {

namespace WebSocket {

    class SocketConnection {
    public:
        enum CONNECTION_STATE {
            CLOSED,
            CLOSING,
            OPENED
        };

        SocketConnection(evhttp_connection*);

        ~SocketConnection();

        CONNECTION_STATE state = CONNECTION_STATE::OPENED;

        evhttp_connection* getConnection();

        void sendMsg(const std::string& msg);

        std::shared_ptr<FrameReader> getFrameReader();
        std::shared_ptr<FrameWriter> getFrameWriter();

        evutil_socket_t getFd();

        void close();

    protected:
        void _writeToBuffer(const Frame&);

        evhttp_connection* _conn = nullptr;
        std::shared_ptr<FrameReader> _reader = nullptr;
        std::shared_ptr<FrameWriter> _writer = nullptr;
    };

} // namespace WebSocket

} // namespace Server