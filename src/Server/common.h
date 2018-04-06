#pragma once

#include <map>

typedef std::map<std::string, std::string> RouteParams;

namespace Server {

    enum class HTTP_METHOD {
        GET,
        POST,
        OPTIONS,
        PUT,
        DELETE,
        HEAD,
        CONNECT,
        PATCH,
        TRACE
    };

}