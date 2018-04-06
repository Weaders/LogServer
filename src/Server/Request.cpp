#include <event2/keyvalq_struct.h>
#include "Request.h"
#include "Server.h"
#include "common.h"

namespace Server {

    Request::Request(evhttp_request *req, const RouteParams &params) : _params(params) {

        this->_req = req;
    }

    const char *Request::getUri() const {
        return evhttp_request_get_uri(this->_req);
    }

    const char *Request::getBody() const {

        auto buffer = evhttp_request_get_input_buffer(this->_req);
        auto len = evbuffer_get_length(buffer);
        char *data = (char *) malloc(len);

        evbuffer_copyout(buffer, data, len);

        return data;
    }


    std::map<std::string, std::string> Request::getHeaders() const {

        auto headers = evhttp_request_get_input_headers(this->_req);

        auto tqh = headers->tqh_first;

        std::map<std::string, std::string> headersMap;

        while (tqh != nullptr) {

            headersMap.insert(std::make_pair(std::string(tqh->key), std::string(tqh->value)));
            tqh = tqh->next.tqe_next;

        }

        return headersMap;

    };

    const char *Request::getHeader(const std::string &headerKey) const {

        auto headers = evhttp_request_get_input_headers(this->_req);

        auto header = evhttp_find_header(headers, headerKey.c_str());

        return header;
    }

    HTTP_METHOD Request::getMethod() const {

        auto cmd = evhttp_request_get_command(this->_req);

        switch (cmd) {
            case EVHTTP_REQ_GET:
                return HTTP_METHOD::GET;
            case EVHTTP_REQ_POST:
                return HTTP_METHOD::POST;
        }

        return HTTP_METHOD::GET;
    }

    const char *Request::getParam(const std::string &param) const {

        auto it = this->_params.find(param);

        if (it != this->_params.end()) {
            return it->second.c_str();
        }

        return nullptr;
    }

    const char *Request::getQueryParam(const std::string &qName) const {

        auto uri = this->getUri();

        struct evkeyvalq query;

        evhttp_parse_query_str(uri, &query);

        return evhttp_find_header(&query, qName.c_str());

    }

    evhttp_request *Request::getReq() const {
        return this->_req;
    }
}