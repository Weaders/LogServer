#include "GetLogsLevelsAction.h"
#include "../../Common/Config.h"

namespace Controllers {

namespace LogsLevels {

    std::shared_ptr<Server::Response> GetLogsLevelsAction::run(const Server::Request& req) {

        std::shared_ptr<Server::Response> response = std::make_shared<Server::Response>();

        auto levels = Common::Config::getInstance()->logLevels;
        auto j = nlohmann::json::array();

        for (auto& level : levels) {
            j.push_back(*level);
        }

        response->jsonResponse(j.dump());

        return response;
    }

} // namespace LogsLevels

} // namespace Controllers