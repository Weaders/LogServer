cmake_minimum_required(VERSION 3.9)
project(http_event)

set(CMAKE_CXX_STANDARD 17)

add_executable(http_event
        src/Server/common.h
        src/main.cpp
        src/Server/Server.cpp
        src/Server/Server.h
        src/Server/Action.cpp
        src/Server/Action.h
        src/Server/Request.cpp
        src/Server/Request.h
        src/Server/Response.cpp
        src/Server/Response.h
        src/Server/Route.cpp
        src/Server/Route.h
        src/Server/WebSocketConn.cpp
        src/Server/WebSocketConn.h
        src/Server/WebSocketAction.cpp
        src/Server/WebSocketAction.h
        src/Server/WebSocketRoute.cpp
        src/Server/WebSocketRoute.h
        src/Services/MemoryInfo.cpp
        src/Services/MemoryInfo.h
        src/Controllers/Memory/MemoryController.cpp
        src/Controllers/Memory/MemoryController.h
        src/json/json.hpp
        src/Controllers/Memory/MemoryInfoCurrent.cpp
        src/Controllers/Memory/MemoryInfoCurrent.h
        src/Server/HomePageActionFile.cpp
        src/Server/HomePageActionFile.h
        src/Services/MemoryInfoData.cpp
        src/Services/MemoryInfoData.h
        src/Services/LogsReader.cpp
        src/Services/LogsReader.h
        src/Common/Config.cpp
        src/Common/Config.h
        src/Controllers/Logs/LogsController.cpp
        src/Controllers/Logs/LogsController.h
        src/Controllers/Logs/LogsFilesAction.cpp
        src/Controllers/Logs/LogsFilesAction.h
        src/Services/LogFile.cpp
        src/Services/LogFile.h
        src/Common/LogLevel.cpp
        src/Common/LogLevel.h
        src/Common/StrTemplate.cpp
        src/Common/StrTemplate.h
        src/Controllers/Logs/LogsMsgsAction.cpp
        src/Controllers/Logs/LogsMsgsAction.h)

target_link_libraries(http_event
        boost_system
        boost_filesystem
        event
)