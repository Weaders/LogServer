#include "LogsFilesAction.h"

namespace Controllers {

namespace Logs {

    LogsFilesAction::LogsFilesAction(std::shared_ptr<Services::LogsReader> ptr)
        : reader(std::move(ptr)) {}

    std::shared_ptr<Server::Response> LogsFilesAction::run(const Server::Request&) {

        std::shared_ptr<Server::Response> response = std::make_shared<Server::Response>();

        auto files = this->reader->getLogsFiles();

        nlohmann::json j;

        for (auto& f : files) {
            j.push_back(f);
        }

        response->jsonResponse(j.dump());

        return response;
    }

} // namespace Logs

} // namespace Controllers
