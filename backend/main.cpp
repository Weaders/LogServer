#include "Server/Server.h"
#include "Common/Config.h"
#include <cstring>
#include <event.h>
#include <iostream>
#include <regex>

#include "./Controllers/Memory/MemoryController.h"
#include "./Controllers/LogsLevels/LogsLevelsController.h"
#include "./Controllers/Logs/LogsController.h"
#include "./Services/LogsReader.h"
#include "./Controllers/Example/ExampleController.h"

int main(int argc, char **argv) {

    auto c = Common::Config::getInstance();

    auto exampleController = Controllers::Example::ExampleController();
    auto memController = Controllers::Memory::MemoryController();
    auto logsController = Controllers::Logs::LogsController(c->logsFolder, c->logExtension);
    auto logsLevelsController = Controllers::LogsLevels::LogsLevelsController();

    auto server = Server::Server();

//    server.fileHomePage("../frontend/index.html");

//    server.homeOn({"/logs"});

//    server.addExtensionType("js", "application/javascript");
//    server.addExtensionType("html", "text/html");
//    server.addExtensionType("css", "text/css");
//
//    server.staticRoute("/", "../frontend/");

    server.websocketRoute("/v1/echo", exampleController.getEchoAction());

    server.route("/v1/memory", memController.memoryDataAction());
    server.route("/v1/logs", logsController.getLogsFiles());
    server.route("/v1/logs/:file", logsController.getLogsMsgs());
    server.route("/v1/logs-levels", logsLevelsController.getLogLevels());

    server.start(c->port);

    return 0;

}