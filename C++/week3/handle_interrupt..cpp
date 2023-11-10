#include <iostream>
#include <csignal>
//
void signalhandel(int signum){
    std::cout<<"interrupt signal("<<signum<<")receved\n";
    exit(signum);
}

int main(){
    signal(SIGINT,signalhandel);
    std::cout<<"press ctrl+c to exit"<<std::endl;

    while(true){
        
        std::cout<<"hello embabi"<<std::endl;
    }
}
