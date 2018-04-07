#include "WebSocketConn.h"

namespace Server {

    WebSocketConn::WebSocketConn(evhttp_request *req) {

        auto headers = evhttp_request_get_input_headers(req);

        this->_req = req; // LogsReq
        this->_conn = evhttp_request_get_connection(req); // Connection
        this->_buff = evhttp_connection_get_bufferevent(this->_conn); // BufferEvent

        this->connection = std::string(evhttp_find_header(headers, "Connection"));
        this->upgrade  = std::string(evhttp_find_header(headers, "Upgrade"));
        this->host = std::string(evhttp_find_header(headers, "Host"));
        this->secKey = std::string(evhttp_find_header(headers, "Sec-WebSocket-Key"));
        this->version = std::string(evhttp_find_header(headers, "Sec-WebSocket-Version"));
        this->protocol = std::string(evhttp_find_header(headers, "Sec-WebSocket-Protocol"));
        this->origin = std::string(evhttp_find_header(headers, "Origin"));

    }

    void WebSocketConn::sendFrame(const std::string& str) {
        bufferevent_write(this->_buff, str.c_str(), str.size());
    }

}