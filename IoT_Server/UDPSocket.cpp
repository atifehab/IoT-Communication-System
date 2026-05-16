#include "UDPSocket.h"

UDPSocket::UDPSocket()
{
    udpSocket.bind(QHostAddress::Any, 5000);
}

void UDPSocket::waitForConnect()
{
}

void UDPSocket::connect(const QString&, int)
{
}

void UDPSocket::send(const QString& message)
{
    udpSocket.writeDatagram(message.toUtf8(), clientAddress, clientPort);
}

QString UDPSocket::receive()
{
    if (udpSocket.hasPendingDatagrams() || udpSocket.waitForReadyRead(100)) {
        QByteArray buffer;
        buffer.resize(udpSocket.pendingDatagramSize());

        udpSocket.readDatagram(buffer.data(), buffer.size(),
                               &clientAddress, &clientPort);

        return QString(buffer).trimmed();
    }
    return "";
}

void UDPSocket::shutdown()
{
    udpSocket.close();
}
