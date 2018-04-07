#pragma once

#include "./../../Server/Action.h"
#include "./../../Server/Response.h"
#include "./../../Server/Request.h"
#include "./../../Services/MemoryInfo.h"
#include "./../../json/json.hpp"

namespace Controllers {

    namespace Memory {

        class MemoryInfoCurrent: public Server::Action {

        public:
            std::shared_ptr<Server::Response> run(const Server::Request&) override;

        };
    }

}