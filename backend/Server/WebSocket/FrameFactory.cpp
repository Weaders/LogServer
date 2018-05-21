#include "FrameFactory.h"

namespace Server {
namespace WebSocket {

    Frame FrameFactory::closeFrame() {

        auto frame = Frame();

        frame.fin = true;
        frame.opcode = Frame::OPCODE_CLOSE;
        frame.payload = "";
        frame.mask = 0;

        return frame;
    }

} // namespace WebSocket
} // namespace Server