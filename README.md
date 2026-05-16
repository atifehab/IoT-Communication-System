# IoT Device Communication System
> C++ · Qt6 · TCP/UDP Sockets · Yocto · QEMU

A full IoT device communication system built as part of the **Embedded Linux Diploma** at Edges Academy. The system simulates a real-world IoT scenario where a QEMU-emulated client device communicates with a Qt6 GUI server over both TCP and UDP sockets, implemented entirely in C++ with strict OOP principles.

---

## Repository Structure

```
IoT-Communication-System/
│
├── client/                   # Terminal client application (runs on QEMU)
│   ├── include/
│   │   ├── Socket.h
│   │   ├── TCPSocket.h
│   │   ├── UDPSocket.h
│   │   ├── Channel.h
│   │   └── ClientChannel.h
│   ├── src/
│   │   ├── main.cpp
│   │   ├── TCPSocket.cpp
│   │   ├── UDPSocket.cpp
│   │   └── ClientChannel.cpp
│   └── Makefile
│
└── IoT_Server/               # Qt6 GUI server application (runs on laptop)
    ├── Channel.h
    ├── Socket.h
    ├── TCPSocket.h / .cpp
    ├── UDPSocket.h / .cpp
    ├── ServerChannel.h / .cpp
    ├── mainwindow.h / .cpp
    ├── mainwindow.ui
    ├── main.cpp
    ├── resources.qrc
    ├── CMakeLists.txt
    └── Makefile
```

---

## System Overview

The system is divided into two applications that communicate over the network every second:

| Component | Platform | Role |
|---|---|---|
| **Client** | QEMU-emulated Linux terminal (Yocto image) | Simulates an IoT sensor device |
| **IoT Server** | Laptop — Qt6 GUI | Central monitoring and control server |

### Communication Flow

Every second, the server evaluates whether the temperature threshold has changed:

- **Threshold changed** → sends `set threshold` command + new value → client updates and displays LED status
- **Threshold unchanged** → sends `get Temp` command → client prompts user for temperature input → sends value back to server

---

## OOP Design

The project enforces **Abstraction, Encapsulation, Inheritance, and Polymorphism** through the following class hierarchy, shared across both applications:

```
Socket  (Abstract)
├── TCPSocket       — TCP implementation using POSIX sockets
└── UDPSocket       — UDP implementation with 1-second receive timeout

Channel  (Abstract)
│   └── channelSocket: Socket*   — pointer to either TCP or UDP socket
├── ClientChannel   — handles client-side command processing
└── ServerChannel   — handles server-side command dispatching
```

The protocol selection (TCP or UDP) is decided at runtime, and the rest of the system works transparently through the abstract `Socket` interface — a clean example of polymorphism in practice.

---

## Client Application

### Description

A pure C++ terminal application designed to run inside a QEMU-emulated Linux environment built with Yocto. It connects to the server on startup and responds to commands interactively via the terminal.

### File Structure

```
client/
├── include/
│   ├── Socket.h          # Abstract socket interface
│   ├── TCPSocket.h       # TCP socket declaration
│   ├── UDPSocket.h       # UDP socket declaration
│   ├── Channel.h         # Abstract channel interface
│   └── ClientChannel.h   # Client channel declaration
├── src/
│   ├── main.cpp          # Entry point — protocol selection, channel start
│   ├── TCPSocket.cpp     # TCP: connect, send, receive, shutdown
│   ├── UDPSocket.cpp     # UDP: connect, send, recvfrom (1s timeout), shutdown
│   └── ClientChannel.cpp # Command handler: get Temp / set threshold logic
└── Makefile
```

### Build Instructions (Native Linux)

```bash
cd client
make
```

This produces `client_app.exe` using:
```
g++ -std=c++17 -pthread -Iinclude src/main.cpp src/TCPSocket.cpp src/UDPSocket.cpp src/ClientChannel.cpp -o client_app.exe
```

To clean:
```bash
make clean
```

### Running the Client

```bash
./client_app.exe [server_ip]
```

- `server_ip` is optional. Defaults to `192.168.7.1` (QEMU TAP bridge default).
- On startup, select the protocol:
  ```
  Select Protocol (TCP/UDP): TCP
  ```

### Sample Terminal Output

```
Attempting to connect to server...
Connected. Awaiting threshold setting...
LED Status: OFF
Received command: set threshold
Received new threshold: 30°C – LED Status: ON
Received command: get Temp
Enter temperature: 35
Sending temperature: 35°C
Received command: set threshold
Received new threshold: 40°C – LED Status: ON
```

### Running on QEMU (Yocto Image)

The client is integrated into a custom Yocto layer (`meta-iotclient`). To run:

1. Build the Yocto image with `meta-iotclient` included
2. Launch the QEMU image:
   ```bash
   runqemu qemux86-64 nographic
   ```
3. Inside the QEMU terminal, run:
   ```bash
   ./client_app.exe <host_ip>
   ```

---

## IoT Server Application

### Description

A C++ server application with a **Qt6 GUI** that listens for client connections over TCP or UDP, sends commands every second, and displays real-time data through an interactive dashboard.

### File Structure

```
IoT_Server/
├── Channel.h              # Abstract channel interface
├── Socket.h               # Abstract socket interface
├── TCPSocket.h / .cpp     # TCP socket implementation
├── UDPSocket.h / .cpp     # UDP socket implementation
├── ServerChannel.h / .cpp # Server-side command dispatching
├── mainwindow.h / .cpp    # Qt6 main window logic
├── mainwindow.ui          # Qt Designer UI layout
├── main.cpp               # Entry point
├── resources.qrc          # Embedded resources (icons, images)
├── CMakeLists.txt         # CMake build configuration
└── Makefile
```

### GUI Tabs

| Tab | Description |
|---|---|
| **Real Time Monitor** | Live simulated temperature meter updated with each client response |
| **Historical Analysis** | 2D graph displaying all temperature readings received over time |
| **Configuration** | Input field to set and update the temperature threshold |
| **Quick Access** | Buttons with icons that open Facebook, LinkedIn, and Instagram |

The GUI also displays a simulated **LED Status (ON/OFF)** based on whether the latest received temperature exceeds the configured threshold.

### Build Instructions

**Using CMake:**
```bash
cd IoT_Server
mkdir build && cd build
cmake ..
make
./IoT_Server
```

**Using Makefile:**
```bash
cd IoT_Server
make
```

### Prerequisites

- Qt6 (with `Qt6::Widgets` and `Qt6::Charts` modules)
- CMake ≥ 3.16
- GCC / G++ with C++17 support

---

## Communication Protocol Details

| Property | Value |
|---|---|
| Default port | `5000` |
| Polling interval | Every `1 second` |
| Supported protocols | TCP and UDP |
| Default QEMU server IP | `192.168.7.1` |

**Commands sent by server:**

| Command | Meaning |
|---|---|
| `set threshold` | Threshold changed — client receives new value and updates LED status |
| `get Temp` | Threshold unchanged — client prompts user and sends current temperature |

---

## Technologies Used

| Technology | Purpose |
|---|---|
| C++17 | Core implementation language |
| Qt6 (Widgets + Charts) | Server GUI framework |
| POSIX TCP/UDP Sockets | Network communication |
| Yocto Project | Custom Linux image generation for QEMU |
| QEMU | Client-side emulation environment |
| CMake & Makefile | Build automation |

---

## Course Context

This project was developed as part of the **Embedded Linux Diploma** at Edges Academy, covering:

- Linux Administration
- Embedded Linux & Device Drivers
- Yocto Project
- C++ & OOP
- Qt++ (Qt6 Framework)

---

## Demo

📹 A full demo video of the project running end-to-end is available in the project's Google Drive folder.
