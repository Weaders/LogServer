#pragma once

#include "./../../Server/Action.h"
#include "./../../Server/Request.h"
#include "./../../Server/Response.h"
#include "./../../Services/LogsReader.h"
#include "../../ThirdParty/json.hpp"

namespace Controllers {

namespace Logs {

    class LogsFilesAction : public Server::Action {

    public:
        LogsFilesAction(std::shared_ptr<Services::LogsReader> reader);

        std::shared_ptr<Server::Response> run(const Server::Request&) override;

    protected:
        std::shared_ptr<Services::LogsReader> reader;
    };

} // namespace Logs

} // namespace Controllers