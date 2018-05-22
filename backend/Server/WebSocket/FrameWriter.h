#pragma once

#include "Frame.h"
#include "string"

namespace Server {

namespace WebSocket {

    class FrameWriter {
    public:
        FrameWriter();
        FrameWriter(const Frame&);
        std::string output();

        void setFrame(const Frame&);

    protected:
        Frame _frameData;
    };

} // namespace WebSocket

} // namespace Server