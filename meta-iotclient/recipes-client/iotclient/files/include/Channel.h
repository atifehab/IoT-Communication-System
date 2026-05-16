#ifndef CHANNEL_H
#define CHANNEL_H

#include <string>
#include "Socket.h"

class Channel
{
protected:
    Socket* channelSocket;

public:
    virtual ~Channel() {}

    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void send(const std::string& message) = 0;
    virtual std::string receive() = 0;
};

#endif // CHANNEL_H
