#ifndef TCP_SOCKET_H
#define TCP_SOCKET_H

#include "Socket.h"
#include <arpa/inet.h>
#include <unistd.h>

class TCPSocket : public Socket
{
private:
    int sockfd;

public:
    TCPSocket();
    ~TCPSocket();

    void connect(const std::string& host, int port) override;
    void send(const std::string& message) override;
    std::string receive() override;
    void shutdown() override;
};

#endif

