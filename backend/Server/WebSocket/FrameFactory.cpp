#include "FrameFactory.h"

namespace Server {
namespace WebSocket {

    Frame FrameFactory::closeFrame() {

        auto frame = Frame();

        frame.fin = true;
        frame.opcode = Frame::OPCODE_CLOSE;
        frame.payload = "";
        frame.mask = false;

        return frame;
    }

    Frame FrameFactory::textFrame(const std::string& msg) {

        auto frame = Frame();

        frame.fin = true;
        frame.fin = Frame::OPCODE_TEXT;
        frame.payload = msg;
        frame.mask = false;

        if (frame.payload.size() <= 125) {

            frame.baseLength = frame.payload.size();
            frame.extendedLength = 0;

        } else if (frame.payload.size() <= 65536) {

            frame.baseLength = 126;
            frame.extendedLength = frame.payload.size();

        } else {

            frame.baseLength = 127;
            frame.extendedLength = frame.payload.size();
        }

        return frame;
    }

} // namespace WebSocket
} // namespace Server