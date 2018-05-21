#include "LogsMsgsAction.h"
#include "../../Common/Config.h"
#include "../../Services/LogFile.h"

namespace Controllers {

namespace Logs {

    std::shared_ptr<Server::Response> LogsMsgsAction::run(const Server::Request& req) {

        auto file = std::string(req.getParam("file"));
        auto c = Common::Config::getInstance();

        if (file.substr(0, 1) == "/") {
            file = file.substr(1);
        }

        file = c->logsFolder + file;

        auto logFile = Services::LogFile(file);

        if (logFile.isValidLogFile) {

            std::shared_ptr<Server::Response> response = std::make_shared<Server::Response>();

            auto j = nlohmann::json::array();
            auto msgs = logFile.getMsgs();

            for (auto& msg : msgs) {
                j.push_back(msg);
            }

            response->jsonResponse(j.dump());

            return response;
        }

        return nullptr; // 404
    }

} // namespace Logs

} // namespace Controllers
