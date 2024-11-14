#ifndef SERVER_H
#define SERVER_H

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "../../configrations.hpp"
#include "../command/command.hpp"

class Server{
    public:
        Std_Return server_Init(int port_number);
        Std_Return server_Accept();
        Std_Return server_Recv_Command();
        Std_Return server_Close();

    private:
        int socketDesc, newSocket;
        ssize_t readSize;
        struct sockaddr_in server, client;
        char message[1024] = {0};

};

#endif