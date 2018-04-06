#pragma once

#include "common.h"
#include "Action.h"
#include <iostream>
#include <regex>
#include <map>
#include <string>

namespace Server {

class Route {

public:
  Route(const std::string&, std::shared_ptr<Action>);

  std::shared_ptr<Server::Action> action;

  RouteParams exec(const std::string &);
  bool check(const std::string &);

protected:
  void _setRegex();

  std::string _sourceStr;
  std::regex _regex;
  std::vector<std::string> _params;

};

} // namespace Server