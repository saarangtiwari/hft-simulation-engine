#include "tcp_server/tcp_server.h"
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>

void initServer()
{
    std::cout << "Initiating TCP Server" << "\n";
    spinServer()
}

void spinServer()
{
    // here created tcp socket is a file descriptor
    // this is an integer which uniquely identifies
    // an open file, socket or other I/O resource within a process
    int tcp_socket = socket(AF_INET, SOCK_STREAM, 0);
}