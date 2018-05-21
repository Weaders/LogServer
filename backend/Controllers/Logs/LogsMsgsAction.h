#pragma once

#include "../../Server/Action.h"

namespace Controllers {

namespace Logs {

    class LogsMsgsAction : public Server::Action {

        std::shared_ptr<Server::Response> run(const Server::Request&) override;
    };

} // namespace Logs

} // namespace Controllers