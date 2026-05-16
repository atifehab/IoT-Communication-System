#ifndef UDP_SOCKET_H
#define UDP_SOCKET_H

#include "Socket.h"
#include <arpa/inet.h>
#include <unistd.h>

class UDPSocket : public Socket
{
private:
    int sockfd;
    sockaddr_in server;

public:
    UDPSocket();
    ~UDPSocket();

    void connect(const std::string& host, int port) override;
    void send(const std::string& message) override;
    std::string receive() override;
    void shutdown() override;
};

#endif

