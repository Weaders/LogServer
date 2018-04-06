#pragma once

#include <event2/buffer.h>
#include <event2/event.h>
#include <event2/http.h>

#include "common.h"

#include "Action.h"
#include "Route.h"
#include "WebSocketConn.h"
#include "WebSocketAction.h"
#include <map>
#include <string>

namespace Server {

class Server {

public:
    explicit Server();
    void start(uint16_t port);

    void route(const std::string& path, std::shared_ptr<Action> action, const HTTP_METHOD& = HTTP_METHOD::GET);
    void staticRoute(const std::string& path, const std::string& folder);
    void websocketRoute(const std::string&, WebSocketAction*);

    void addExtensionType(const std::string&, const std::string&);
    bool staticRouteFileName(const std::string&, std::string&);

    std::shared_ptr<Response> getFileResponse(const std::string&);
    std::shared_ptr<Response> get404Response();
    std::shared_ptr<Response> getHomePage();

    bool isReturnHomeOn404();

    void fileHomePage(const std::string&, bool returnOn404 = false);

    void sendResponse(evhttp_request*, std::shared_ptr<Response>);

    static HTTP_METHOD convertEvCmd(const evhttp_cmd_type &);

protected:

    std::map<std::string, std::string> extensions;
    std::vector<Route> routes;
    std::map<std::string, std::string> staticRoutes;

    std::string fileHomePagePath;
    bool returnHomeOn404 = false;
};

} // namespace Server