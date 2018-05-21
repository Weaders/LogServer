#include "FrameReader.h"

namespace Server {

namespace WebSocket {

    FrameReader::FrameReader() {}

    void FrameReader::clear() {

        this->_frameData = Frame();
        this->_bytesRead = 0;
    }

    void FrameReader::read(char byte) {

        if (this->_bytesRead == 0) {
            this->readFirstByte(byte);
        } else if (this->_bytesRead == 1) {
            this->readSecondByte(byte);
        } else {

            if (auto lengthBytes = this->needParseLength()) {
                this->_frameData.extendedLength |= (byte << (lengthBytes - 1) * 8);
            } else if (auto lengthMask = this->needParseMasking()) {
                this->_frameData.maskingKey[4 - lengthMask] = byte;
            } else {

                if (this->_frameData.mask) {

                    auto maskingOctet = this->_frameData.payload.size() % 4;
                    this->_frameData.payload += byte ^ this->_frameData.maskingKey[maskingOctet];

                } else {
                    this->_frameData.payload += byte;
                }
            }
        }

        this->_bytesRead++;
    }

    Frame FrameReader::getFrameData() {
        return this->_frameData;
    }

    void FrameReader::readFirstByte(char byte) {

        std::bitset<8> bits(byte);

        this->_frameData.fin = bits[7];
        this->_frameData.rsv1 = bits[6];
        this->_frameData.rsv2 = bits[5];
        this->_frameData.rsv3 = bits[4];

        this->_frameData.opcode = bits[3] << 3 | bits[2] << 2 | bits[1] << 1 | bits[0];
    }

    void FrameReader::readSecondByte(char byte) {

        std::bitset<8> bits(byte);

        this->_frameData.mask = bits[7];
        this->_frameData.baseLength = bits[6] << 6 | bits[5] << 5 | bits[4] << 4 | bits[3] << 3 | bits[2] << 2 | bits[1] << 1 | bits[0];
    }

    size_t FrameReader::needParseLength() {

        if (this->_frameData.baseLength == 126 && this->_bytesRead < 4) {
            return 4 - this->_bytesRead;
        } else if (this->_frameData.baseLength == 127 && this->_bytesRead < 10) {
            return 10 - this->_bytesRead;
        }

        return 0;
    }

    size_t FrameReader::needParseMasking() {

        if (!this->_frameData.mask) {
            return 0;
        }

        if (this->_frameData.baseLength < 126 && this->_bytesRead >= 2 && this->_bytesRead < 6) {
            return 6 - this->_bytesRead;
        }

        if (this->_frameData.baseLength == 126 && this->_bytesRead >= 4 && this->_bytesRead < 8) {
            return 8 - this->_bytesRead;
        }

        if (this->_frameData.baseLength == 127 && this->_bytesRead >= 10 && this->_bytesRead < 14) {
            return 14 - this->_bytesRead;
        }

        return 0;
    }

    bool FrameReader::isEndRead() {

        if (this->_bytesRead <= 2) {
            return false;
        }

        if (this->_frameData.baseLength < 126 && this->_frameData.payload.size() == this->_frameData.baseLength) {
            return true;
        }

        if (this->_frameData.baseLength > 125 && this->_frameData.payload.size() == this->_frameData.extendedLength) {
            return true;
        }
    }
} // namespace WebSocket
} // namespace Server