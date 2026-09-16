# C++ TCP Chatroom

A small asynchronous, multi-client chatroom written in C++20 with Boost.Asio.
The server accepts TCP connections and broadcasts each newline-terminated message
to every connected client except the sender.

## Features

- Asynchronous TCP server using Boost.Asio
- Multiple simultaneous clients
- Broadcast messaging through a shared `Room`
- Line-based client input and output
- Maximum message body size of 512 bytes

## Prerequisites

- A C++20-capable compiler (for example, `g++`)
- GNU Make
- Boost headers and the `boost_system` and `boost_thread` libraries

On Linux, these are commonly available through your distribution's Boost
development package. On Windows, build from an environment that provides GNU
Make, `g++`, and Boost (such as MSYS2 or WSL), or adapt the Makefile to your
toolchain.

## Build

From the project directory, run:

```sh
make
```

This creates two executables:

| Executable | Purpose |
| --- | --- |
| `chatApp` | Starts the chat server |
| `clientApp` | Connects a terminal client to the server |

To remove build outputs:

```sh
make clean
```

## Run

Start the server on a port, for example `8080`:

```sh
./chatApp 8080
```

In one or more separate terminals, connect clients to that port:

```sh
./clientApp 8080
```

Type a message and press Enter. It will be delivered to the other connected
clients. The sender does not receive its own message back.

## Project layout

| File | Description |
| --- | --- |
| `chatRoom.cpp` | Server entry point plus `Room` and `Session` implementations |
| `chatRoom.hpp` | Chatroom, participant, and session declarations |
| `client.cpp` | Interactive command-line client |
| `message.hpp` | Message container with a 4-byte length header and 512-byte body limit |
| `Makefile` | GNU Make build rules |

## Notes

- The client connects only to `127.0.0.1`, so it is intended for local testing.
- Messages are framed at the transport boundary by a trailing newline.
- The server excludes the originator when broadcasting a message.