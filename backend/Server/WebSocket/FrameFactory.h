#pragma once
#include "Frame.h"

namespace Server {

namespace WebSocket {

    class FrameFactory {
    public:
        static Frame emptyFrame();
        static Frame closeFrame();
        static Frame pongFrame();
        static Frame pingFrame();
    };
} // namespace WebSocket
} // namespace Server