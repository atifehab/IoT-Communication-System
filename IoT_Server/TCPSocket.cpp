#include "TCPSocket.h"

TCPSocket::TCPSocket(QObject *parent)
    : QObject(parent), socket(nullptr)
{
}

TCPSocket::~TCPSocket()
{
    shutdown();
}

void TCPSocket::waitForConnect()
{
    server.listen(QHostAddress::Any, 5000);
    QObject::connect(&server, &QTcpServer::newConnection, this, [this]() {
        socket = server.nextPendingConnection();
    });
}

void TCPSocket::connect(const QString&, int)
{
}

void TCPSocket::send(const QString& message)
{
    if(socket)
    {
        socket->write(message.toUtf8());
        socket->waitForBytesWritten();
    }
}

QString TCPSocket::receive()
{
    if(socket)
    {
        if (socket->bytesAvailable() > 0 || socket->waitForReadyRead(100))
        {
            return QString(socket->readAll()).trimmed();
        }
    }
    return "";
}

void TCPSocket::shutdown()
{
    if(socket)
    {
        socket->close();
        delete socket;
        socket = nullptr;
    }
}
