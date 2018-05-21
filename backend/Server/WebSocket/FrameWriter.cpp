#include "FrameWriter.h"

namespace Server {

namespace WebSocket {

    FrameWriter::FrameWriter() {
    }

    FrameWriter::FrameWriter(const Frame& frame) {
        this->setFrame(frame);
    }

    void FrameWriter::setFrame(const Frame& frame) {
        this->_frameData = frame;
    }

    std::string FrameWriter::output() {

        std::string result = "";

        result += (this->_frameData.fin << 7 | this->_frameData.rsv1 << 6 | this->_frameData.rsv2 << 5 | this->_frameData.rsv3 << 4 | this->_frameData.opcode);

        result += static_cast<char>(this->_frameData.baseLength & 0x7F);

        if (this->_frameData.baseLength == 126) {

            result += (this->_frameData.extendedLength >> 8) & 0xFF;
            result += this->_frameData.extendedLength & 0xFF;

        } else if (this->_frameData.baseLength == 127) {

            result += this->_frameData.extendedLength >> 56 & 0xFF;
            result += this->_frameData.extendedLength >> 48 & 0xFF;
            result += this->_frameData.extendedLength >> 40 & 0xFF;
            result += this->_frameData.extendedLength >> 32 & 0xFF;
            result += this->_frameData.extendedLength >> 24 & 0xFF;
            result += this->_frameData.extendedLength >> 16 & 0xFF;
            result += this->_frameData.extendedLength >> 8 & 0xFF;
            result += this->_frameData.extendedLength & 0xFF;
        }

        // if (this->_frameData.mask) {

        //     result += this->_frameData.maskingKey[0];
        //     result += this->_frameData.maskingKey[1];
        //     result += this->_frameData.maskingKey[2];
        //     result += this->_frameData.maskingKey[3];

        // }

        result += this->_frameData.payload;

        return result;
    }
} // namespace WebSocket

} // namespace Server