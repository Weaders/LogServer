#pragma once

#include <string>
#include "Action.h"
#include <vector>
#include <regex>

namespace Server {

    class WebSocketRoute {

    public:
        WebSocketRoute(const std::string&, std::shared_ptr<Action>);

        std::shared_ptr<Server::Action> action;

        RouteParams exec(const std::string &);
        bool check(const std::string &);

    protected:
        void _setRegex();

        std::string _sourceStr;
        std::regex _regex;
        std::vector<std::string> _params;


    };

}