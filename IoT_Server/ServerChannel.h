#ifndef SERVERCHANNEL_H
#define SERVERCHANNEL_H

#include "Channel.h"

class ServerChannel : public Channel
{
public:
    ServerChannel(Socket* socket);

    void start() override;
    void stop() override;
    void send(const QString& message) override;
    QString receive() override;
};


#endif // SERVERCHANNEL_H
