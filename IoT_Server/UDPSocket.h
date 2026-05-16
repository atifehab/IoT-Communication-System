#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include "Socket.h"
#include <QUdpSocket>

class UDPSocket : public Socket
{
private:
    QUdpSocket udpSocket;
    QHostAddress clientAddress;
    quint16 clientPort;

public:
    UDPSocket();

    void waitForConnect() override;
    void connect(const QString& host, int port) override;
    void send(const QString& message) override;
    QString receive() override;
    void shutdown() override;
};

#endif // UDPSOCKET_H
