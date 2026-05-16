CXX ?= g++
CXXFLAGS += -std=c++17 -pthread -Iinclude

SRC = src/main.cpp src/TCPSocket.cpp src/UDPSocket.cpp src/ClientChannel.cpp
OUT = client_app.exe

all:
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
