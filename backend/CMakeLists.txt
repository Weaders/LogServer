cmake_minimum_required(VERSION 3.9)
project(http_event)

set(CMAKE_BUILD_TYPE Debug)

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
        Controllers/LogsLevels/GetLogsLevelsAction.h 
        Common/Base64.h 
        Server/WebSocket/SocketConnection.cpp 
        Server/WebSocket/SocketConnection.h
        Server/WebSocket/Frame.cpp 
        Server/WebSocket/Frame.h
        Server/WebSocket/FrameReader.h
        Server/WebSocket/FrameReader.cpp
        Server/WebSocket/FrameWriter.h
        Server/WebSocket/FrameWriter.cpp
        Server/WebSocket/FrameFactory.h
        Server/WebSocket/FrameFactory.cpp
        Server/WebSocket/SocketRoute.h
        Server/WebSocket/SocketRoute.cpp
        Server/WebSocket/SocketAction.cpp
        Server/WebSocket/SocketAction.h
        Controllers/Example/ExampleController.h
        Controllers/Example/ExampleController.cpp
)

file(REMOVE ${CMAKE_BINARY_DIR}/config.json)
configure_file(config.json config.json COPYONLY)

target_link_libraries(http_event
        boost_system
        boost_filesystem
        event
)