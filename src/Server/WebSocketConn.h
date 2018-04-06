#pragma once

#include <string>
#include <evhttp.h>

namespace Server {

    class WebSocketConn {

    public:

        enum CB_TYPE {
            HANDSHAKE,

        };

        WebSocketConn(evhttp_request* req);
        ~WebSocketConn();

        std::string connection;
        std::string upgrade;
        std::string host;
        std::string origin;
        std::string secKey;
        std::string version;
        std::string protocol;

        void sendFrame(const std::string&);

    protected:
        evhttp_request* _req;
        evhttp_connection* _conn ;
        bufferevent* _buff;

    };

}