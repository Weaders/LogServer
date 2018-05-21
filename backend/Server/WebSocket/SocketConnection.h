#include "FrameReader.h"
#include <event2/http.h>
#include <memory>

namespace Server {

namespace WebSocket {

    class SocketConnection {
    public:
        enum CONNECTION_STATE {
            CLOSED,
            CLOSING,
            OPENED
        };

        SocketConnection(evhttp_connection*);

        CONNECTION_STATE state;

        evhttp_connection* getConnection();
        std::shared_ptr<FrameReader> getFrameReader();

        void close();

    protected:
        evhttp_connection* _conn = nullptr;
        std::shared_ptr<FrameReader> _reader = nullptr;
    };

} // namespace WebSocket

} // namespace Server