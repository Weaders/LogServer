#include "MemoryInfoCurrent.h"

namespace Controllers {

    namespace Memory {

        std::shared_ptr<Server::Response> MemoryInfoCurrent::run(const Server::Request &req) {

            auto response = std::make_shared<Server::Response>();

            Services::MemoryInfo memInfo;

            nlohmann::json j = memInfo;

            response->jsonResponse(j.dump());

            return response;

        }

    }

}