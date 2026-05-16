#include "ServerChannel.h"

ServerChannel::ServerChannel(Socket* socket)
{
    channelSocket = socket;
}

void ServerChannel::start()
{
    channelSocket->waitForConnect();
}

void ServerChannel::stop()
{
    channelSocket->shutdown();
}

void ServerChannel::send(const QString& message)
{
    channelSocket->send(message);
}

QString ServerChannel::receive()
{
    return channelSocket->receive();
}
