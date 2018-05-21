#pragma once

#include "Action.h"
#include "common.h"
#include <iostream>
#include <map>
#include <regex>
#include <string>

namespace Server {

class Route {

public:
    Route(const std::string&, std::shared_ptr<Action>, const HTTP_METHOD&);

    std::shared_ptr<Server::Action> action;

    RouteParams exec(const std::string&);
    bool check(std::string, const HTTP_METHOD&);

protected:
    void _setRegex();

    std::string _sourceStr;
    std::regex _regex;
    std::vector<std::string> _params;
    HTTP_METHOD _method;
};

} // namespace Server