#ifndef SOCKET_H
#define SOCKET_H

#include <string>

class Socket
{
public:
    virtual ~Socket() {}

    virtual void connect(const std::string& host, int port) = 0;
    virtual void send(const std::string& message) = 0;
    virtual std::string receive() = 0;
    virtual void shutdown() = 0;
};

#endif

