#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "Socket.h"

class TCPSocket : public QObject, public Socket
{
    Q_OBJECT

public:
    explicit TCPSocket(QObject *parent = nullptr);
    ~TCPSocket();

    void waitForConnect() override;
    void connect(const QString&, int) override;
    void send(const QString& message) override;
    QString receive() override;
    void shutdown() override;

private:
    QTcpServer server;
    QTcpSocket* socket;
};

#endif // TCPSOCKET_H
