#pragma once

#include "../../Server/Action.h"
#include "../../json/json.hpp"

namespace Controllers {

namespace LogsLevels {

    class GetLogsLevelsAction : public Server::Action {

        std::shared_ptr<Server::Response> run(const Server::Request&) override;
    };

} // namespace LogsLevels

} // namespace Controllers