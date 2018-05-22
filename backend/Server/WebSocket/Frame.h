#pragma once
#include "string"

namespace Server {

namespace WebSocket {

    class Frame {
    public:
        static const short OPCODE_CLOSE = 0x8;
        static const short OPCODE_TEXT = 0x1;
        static const short OPCODE_BINARY = 0x2;
        static const short OPCODE_PING = 0x9;
        static const short OPCODE_PONG = 0xA;

        Frame();

        bool fin = true;
        bool rsv1 = false, rsv2 = false, rsv3 = false;

        char opcode = Frame::OPCODE_TEXT;

        bool mask = true;

        unsigned short baseLength = 0;
        unsigned long long extendedLength = 0;

        int bytesParsed = 0;

        char maskingKey[4] = {};

        std::string payload = "";
    };

} // namespace WebSocket

} // namespace Server