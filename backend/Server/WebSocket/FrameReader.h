#pragma once

#include "Frame.h"
#include "bitset"

namespace Server {

namespace WebSocket {

    class FrameReader {
    public:
        FrameReader();

        void read(char byte);
        bool isEndRead();
        void clear();

        Frame getFrameData();

    protected:
        Frame _frameData;
        size_t _bytesRead = 0;

        void readFirstByte(char byte);
        void readSecondByte(char byte);

        size_t needParseLength();
        size_t needParseMasking();
    };

} // namespace WebSocket

} // namespace Server