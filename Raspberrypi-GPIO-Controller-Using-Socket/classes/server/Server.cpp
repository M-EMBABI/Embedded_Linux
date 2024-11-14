#include "Server.hpp"

Std_Return Server::server_Init(int port_number){
    Std_Return R_value = Std_Return::STD_R_NOK;
    Server::socketDesc = socket(AF_INET, SOCK_STREAM,0);

    if(-1 == socketDesc)
    {
        std::cerr << "could not create socket\n";
        R_value = Std_Return::STD_R_NOK;
    }
    else
    {
        Server::server.sin_family = AF_INET;
        Server::server.sin_addr.s_addr = INADDR_ANY;
        Server::server.sin_port = htons(port_number);
        
        if(bind(socketDesc, reinterpret_cast<struct sockaddr *>(&server),sizeof(server)) < 0)
        {
            std::cerr << "bind failed\n";
            close(socketDesc);
            R_value = Std_Return::STD_R_NOK;
        }
        else
        {
            R_value = Std_Return::STD_R_OK;
        }
    }
    return R_value;
}



Std_Return Server::server_Accept(){
    Std_Return R_value = Std_Return::STD_R_NOK;
    int c = sizeof(struct  sockaddr_in);
    unsigned int count=0;

    //listen 
    if (listen(socketDesc, 3) < 0) 
    {
        std::cerr << "Error listening on socket" << std::endl;
        close(socketDesc);
        R_value = Std_Return::STD_R_NOK;
    }
    else
    {
        std::cout << "waiting for incoming connections...\n";
        R_value = Std_Return::STD_R_OK;
    }
    

    // Accept incoming connection
    while(true)
    {
        newSocket = accept(socketDesc, reinterpret_cast<struct sockaddr *>(&client),reinterpret_cast<socklen_t *>(&c));
        if(newSocket < 0)
        {
            std::cerr << "Accept failed\n";
            count++;
            if(count < 10)
            {
                continue;
            }
            else
            {
                close(socketDesc);
                R_value = Std_Return::STD_R_NOK;
                break;
            }
        }
        else
        {
            std::cout << "Connection accepted\n";
            R_value = Std_Return::STD_R_OK;
            break;
        }
    }
    
    return R_value;
}


Std_Return Server::server_Recv_Command(){
    Std_Return R_value = Std_Return::STD_R_NOK;
    const char *response = nullptr;
    Command commd;
    while (true)
    {
        memset(message, 0, sizeof(message));
        while(recv(newSocket, message,sizeof(message),0) > 0)
        {
            
            R_value = commd.executeCmdLine(message);
            
            if(R_value == Std_Return::STD_R_OK)
            {
                response = "The command execute Correctly\n";
            }
            else
            {
                response = "The command execute Faild\n";
            }       
            if(write(newSocket,response,strlen(response)) == -1)
            {
                perror("failed send message to client");
                Server::server_Close();
                R_value = Std_Return::STD_R_NOK;
            }
            else
            {
                R_value = Std_Return::STD_R_OK;
            }
        }
    }
    return R_value;
}


Std_Return Server::server_Close(){
    Std_Return R_value = Std_Return::STD_R_NOK;
    if(close(newSocket) == 0 && close(socketDesc) == 0)
    {
        R_value = Std_Return::STD_R_OK;
    }
    else
    {
        R_value = Std_Return::STD_R_NOK;
    }
    
    return R_value;
}