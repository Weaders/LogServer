#pragma once

#include "./../../Server/Action.h"
#include "./../../Server/Response.h"
#include "./../../Server/Request.h"
#include "./../../json/json.hpp"
#include "./../../Services/LogsReader.h"

namespace Controllers {

    namespace Logs {

        class LogsFilesAction: public Server::Action {

        public:

            LogsFilesAction(std::shared_ptr<Services::LogsReader> reader);

            std::shared_ptr<Server::Response> run(const Server::Request&) override;

        protected:
            std::shared_ptr<Services::LogsReader> reader;

        };

    }

}