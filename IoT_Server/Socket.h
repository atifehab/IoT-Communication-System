#ifndef SOCKET_H
#define SOCKET_H

#include <QString>

class Socket
{
public:
    virtual ~Socket() {}

    virtual void waitForConnect() = 0;
    virtual void connect(const QString& host, int port) = 0;
    virtual void send(const QString& message) = 0;
    virtual QString receive() = 0;
    virtual void shutdown() = 0;
};

#endif // SOCKET_H
