#pragma once

#include "./../../Server/Action.h"
#include "./../../Server/Request.h"
#include "./../../Server/Response.h"
#include "./../../Services/MemoryInfo.h"
#include "../../ThirdParty/json.hpp"

namespace Controllers {

namespace Memory {

    class MemoryInfoCurrent : public Server::Action {

    public:
        std::shared_ptr<Server::Response> run(const Server::Request&) override;
    };
} // namespace Memory

} // namespace Controllers