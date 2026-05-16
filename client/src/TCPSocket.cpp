#include "../include/TCPSocket.h"
#include <iostream>
#include <unistd.h>

using namespace std;

TCPSocket::TCPSocket()
{
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
}

TCPSocket::~TCPSocket()
{
    shutdown();
}

void TCPSocket::connect(const string& host, int port)
{
    sockaddr_in server{};
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    inet_pton(AF_INET, host.c_str(), &server.sin_addr);

    while(::connect(sockfd, (sockaddr*)&server, sizeof(server)) < 0)
    {
        sleep(1);
    }
}

void TCPSocket::send(const string& message)
{
    ::write(sockfd, message.c_str(), message.size());
}

string TCPSocket::receive()
{
    char buffer[1024];

    int bytes = read(sockfd, buffer, 1023);

    if(bytes <= 0)
        return "";

    buffer[bytes] = '\0';

    return string(buffer);
}

void TCPSocket::shutdown()
{
    close(sockfd);
}