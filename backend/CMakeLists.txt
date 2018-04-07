cmake_minimum_required(VERSION 3.9)
project(http_event)

set(CMAKE_CXX_STANDARD 17)

add_executable(http_event
        Server/common.h
        main.cpp
        Server/Server.cpp
        Server/Server.h
        Server/Action.cpp
        Server/Action.h
        Server/Request.cpp
        Server/Request.h
        Server/Response.cpp
        Server/Response.h
        Server/Route.cpp
        Server/Route.h
        Server/WebSocketConn.cpp
        Server/WebSocketConn.h
        Server/WebSocketAction.cpp
        Server/WebSocketAction.h
        Server/WebSocketRoute.cpp
        Server/WebSocketRoute.h
        Services/MemoryInfo.cpp
        Services/MemoryInfo.h
        Controllers/Memory/MemoryController.cpp
        Controllers/Memory/MemoryController.h
        json/json.hpp
        Controllers/Memory/MemoryInfoCurrent.cpp
        Controllers/Memory/MemoryInfoCurrent.h
        Services/MemoryInfoData.cpp
        Services/MemoryInfoData.h
        Services/LogsReader.cpp
        Services/LogsReader.h
        Common/Config.cpp
        Common/Config.h
        Controllers/Logs/LogsController.cpp
        Controllers/Logs/LogsController.h
        Controllers/Logs/LogsFilesAction.cpp
        Controllers/Logs/LogsFilesAction.h
        Services/LogFile.cpp
        Services/LogFile.h
        Common/LogLevel.cpp
        Common/LogLevel.h
        Common/StrTemplate.cpp
        Common/StrTemplate.h
        Controllers/Logs/LogsMsgsAction.cpp
        Controllers/Logs/LogsMsgsAction.h
        Controllers/LogsLevels/LogsLevelsController.cpp
        Controllers/LogsLevels/LogsLevelsController.h
        Controllers/LogsLevels/GetLogsLevelsAction.cpp
        Controllers/LogsLevels/GetLogsLevelsAction.h)

file(REMOVE ${CMAKE_BINARY_DIR}/config.json)
configure_file(config.json config.json COPYONLY)

target_link_libraries(http_event
        boost_system
        boost_filesystem
        event
)