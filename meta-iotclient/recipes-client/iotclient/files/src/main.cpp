#include "../include/TCPSocket.h"
#include "../include/UDPSocket.h"
#include "../include/ClientChannel.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    string protocol;
    string serverIp = "192.168.7.1"; // Default for QEMU TAP bridge

    if(argc >= 2)
        serverIp = argv[1];

    cout << "Select Protocol (TCP/UDP): ";
    cin >> protocol;

    Socket* socket;

    if(protocol == "TCP")
        socket = new TCPSocket();
    else
        socket = new UDPSocket();

    ClientChannel channel(socket, serverIp);
    channel.start();

    delete socket;

    return 0;
}