#pragma once

#include <event2/buffer.h>
#include <event2/event.h>
#include <event2/http.h>

#include "common.h"

#include "Action.h"
#include "Route.h"
#include "WebSocket/SocketAction.h"
#include "WebSocket/SocketRoute.h"
#include "boost/filesystem.hpp"
#include <map>
#include <string>

namespace Server {

class Server {

public:
    explicit Server();
    void start(unsigned port);

    void route(const std::string& path, std::shared_ptr<Action> action, const HTTP_METHOD& = HTTP_METHOD::GET);
    void staticRoute(const std::string& path, const std::string& folder);
    void websocketRoute(const std::string&, std::shared_ptr<WebSocket::SocketAction>, const HTTP_METHOD& = HTTP_METHOD::GET);

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
    std::vector<std::shared_ptr<WebSocket::SocketAction>> _socketActions;

    std::map<std::string, std::string> _staticRoutes;

    std::string fileHomePagePath;
    std::vector<std::string> homeRoutes;
};

} // namespace Server