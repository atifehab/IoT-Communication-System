#include "../include/ClientChannel.h"
#include <iostream>
#include <algorithm>

using namespace std;

ClientChannel::ClientChannel(Socket* s, const string& host)
    : threshold(0), currentTemperature(0), serverHost(host)
{
    channelSocket = s;
}

void ClientChannel::stop()
{
    channelSocket->shutdown();
}

void ClientChannel::send(const string& message)
{
    channelSocket->send(message);
}

string ClientChannel::receive()
{
    return channelSocket->receive();
}

void ClientChannel::start()
{
    cout << "Attempting to connect to server...\n";

    channelSocket->connect(serverHost, 5000);

    string command;
    while (true) {
        channelSocket->send("HELLO\n");
        command = channelSocket->receive();
        if (!command.empty()) {
            cout << "Connected. Awaiting threshold setting...\n";
            cout << "LED Status: OFF\n";
            break;
        }
    }

    handleCommand(command);

    while(true)
    {
        command = channelSocket->receive();

        if(command.empty())
            continue;

        handleCommand(command);
    }
}

void ClientChannel::handleCommand(string command)
{
    command.erase(remove(command.begin(), command.end(), '\n'), command.end());
    command.erase(remove(command.begin(), command.end(), '\r'), command.end());

    if(command.find("set threshold") != string::npos)
    {
        cout << "Received command: set threshold\n";
        
        string threshStr;
        while (true) {
            threshStr = channelSocket->receive();
            threshStr.erase(remove(threshStr.begin(), threshStr.end(), '\n'), threshStr.end());
            threshStr.erase(remove(threshStr.begin(), threshStr.end(), '\r'), threshStr.end());
            
            if (!threshStr.empty()) {
                try {
                    threshold = stoi(threshStr);
                    break;
                } catch (...) {
                }
            }
        }

        cout << "Received new threshold: "
             << threshold << "°C – ";

        if(currentTemperature <= threshold)
            cout << "LED Status: ON\n";
        else
            cout << "LED Status: OFF\n";
    }
    else if(command.find("get Temp") != string::npos)
    {
        cout << "Received command: get Temp\n";
        cout << "Enter temperature: ";
        cin >> currentTemperature;
        cout << "Sending temperature: " << currentTemperature << "°C\n";
        channelSocket->send(to_string(currentTemperature) + "\n");
    }
}