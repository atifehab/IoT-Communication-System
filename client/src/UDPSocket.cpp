#include "../include/UDPSocket.h"
#include <cstring>
#include <iostream>
#include <sys/time.h>

using namespace std;

UDPSocket::UDPSocket()
{
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    // Set 1-second receive timeout so recvfrom doesn't block forever
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));
}

UDPSocket::~UDPSocket()
{
    shutdown();
}

void UDPSocket::connect(const string& host, int port)
{
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, host.c_str(), &server.sin_addr);
}

void UDPSocket::send(const string& message)
{
    sendto(sockfd, message.c_str(), message.size(), 0,
           (sockaddr*)&server, sizeof(server));
}

string UDPSocket::receive()
{
    char buffer[1024];
    socklen_t len = sizeof(server);

    int bytes = recvfrom(sockfd, buffer, 1023, 0,
                         (sockaddr*)&server, &len);

    if(bytes <= 0)
        return "";

    buffer[bytes] = '\0';

    return string(buffer);
}

void UDPSocket::shutdown()
{
    close(sockfd);
}