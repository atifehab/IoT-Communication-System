#ifndef CHANNEL_H
#define CHANNEL_H

#include "Socket.h"

class Channel
{
protected:
    Socket* channelSocket;

public:
    virtual ~Channel() {}

    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void send(const QString& message) = 0;
    virtual QString receive() = 0;
};

#endif // CHANNEL_H
