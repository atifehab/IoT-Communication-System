#ifndef CLIENT_CHANNEL_H
#define CLIENT_CHANNEL_H

#include "Channel.h"

class ClientChannel : public Channel
{
private:
    int threshold;
    int currentTemperature;
    std::string serverHost;

    void handleCommand(std::string command);

public:
    ClientChannel(Socket* s, const std::string& host = "192.168.7.1");
    void start() override;
    void stop() override;
    void send(const std::string& message) override;
    std::string receive() override;
};

#endif

