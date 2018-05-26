#pragma once

#include <event2/buffer.h>
#include <event2/event.h>
#include <event2/http.h>

#include "common.h"

#include "Action.h"
#include "Route.h"
#include "WebSocket/SocketAction.h"
#include "WebSocket/SocketActionGenerator.h"
#include "WebSocket/SocketRoute.h"
#include "boost/filesystem.hpp"
#include <map>
#include <string>
#include <type_traits>

namespace Server {

class Server {

public:
    explicit Server();
    void start(unsigned port);

    void route(const std::string& path, std::shared_ptr<Action> action, const HTTP_METHOD& = HTTP_METHOD::GET);
    void staticRoute(const std::string& path, const std::string& folder);

    template <class T>
    void webSocketRoute(const std::string& path, const HTTP_METHOD& method = HTTP_METHOD::GET) {

        static_assert(std::is_convertible<T*, WebSocket::SocketAction*>::value, "Hi");

        this->_socketRoutes.emplace_back(Route(path, method));
        auto socketGenerator = WebSocket::SocketActionGenerator();
        socketGenerator.setGenerateCb([](const std::string& path, std::shared_ptr<WebSocket::SocketConnection> conn) -> std::shared_ptr<WebSocket::SocketAction> {
            return std::make_shared<T>(path, conn);
        });

        this->_socketActions.emplace_back(socketGenerator);
    }

    void addExtensionType(const std::string&, const std::string&);
    bool staticRouteFileName(const std::string&, std::string&);

    void processWebSocketReq(const Request&);
    void processSimpleReq(const Request&);

    std::shared_ptr<Response> getFileResponse(const std::string&);
    std::shared_ptr<Response> get404Response();
    std::shared_ptr<Response> getHomePage();

    void fileHomePage(const std::string&);
    void homeOn(const std::vector<std::string>&);

    void sendResponse(evhttp_request*, std::shared_ptr<Response>);

    static HTTP_METHOD convertEvCmd(const evhttp_cmd_type&);

    bool isReturnHome(const std::string& path);

protected:
    std::map<std::string, std::string> _extensions;

    std::vector<Route> _simpleReqRoutes;
    std::vector<Route> _socketRoutes;

    std::vector<std::shared_ptr<Action>> _simpleActions;
    std::vector<WebSocket::SocketActionGenerator> _socketActions;

    std::map<std::string, std::string> _staticRoutes;
    std::map<evutil_socket_t, std::shared_ptr<WebSocket::SocketAction>> _socketConnections;

    std::string fileHomePagePath;
    std::vector<std::string> homeRoutes;
};

} // namespace Server