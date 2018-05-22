#pragma once
#include "Frame.h"

namespace Server {

namespace WebSocket {

    class FrameFactory {
    public:
        static Frame textFrame(const std::string&);
        static Frame emptyFrame();
        static Frame closeFrame();
        static Frame pongFrame();
        static Frame pingFrame();
    };
} // namespace WebSocket
} // namespace Server