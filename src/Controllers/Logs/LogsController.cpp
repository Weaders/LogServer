#include "LogsController.h"

namespace Controllers {

    namespace Logs {

        LogsController::LogsController(const std::string& folder, const std::string& logExtension) {
            this->logsReader = std::make_shared<Services::LogsReader>(folder, logExtension);
        }

        std::shared_ptr<Server::Action> LogsController::getLogsFiles() {

            if (this->logsFilesAction == nullptr) {
                this->logsFilesAction = std::make_shared<LogsFilesAction>(this->logsReader);
            }

            return this->logsFilesAction;

        }

        std::shared_ptr<Server::Action> LogsController::getLogsMsgs() {

            if (this->logsMsgsAction == nullptr) {
                this->logsMsgsAction = std::make_shared<LogsMsgsAction>();
            }

            return this->logsMsgsAction;

        }

    }

}