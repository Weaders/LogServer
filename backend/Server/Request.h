#pragma once

#include "common.h"
#include "map"
#include "string"
#include <evhttp.h>

namespace Server {

class Request {

public:
    Request(evhttp_request* reg, const RouteParams&);

    HTTP_METHOD getMethod() const;

    const char* getParam(const std::string&) const;

    const char* getHeader(const std::string&) const;

    const char* getQueryParam(const std::string&) const;

    const char* getBody() const;

    const char* getUri() const;

    std::map<std::string, std::string> getHeaders() const;

    evhttp_request* getReq() const;

protected:
    struct evhttp_request* _req;
    RouteParams _params;
};
} // namespace Server
