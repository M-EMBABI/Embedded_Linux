#include<iostream>
#include <fstream>
#include <string>
#include <system_error>
#include "logs.hpp"

int main(){
    logs log("file.txt");
    std::string userinput;
    std::cout<<" enter a message : ";
    std::getline(std::cin,userinput);
    std::cout<<userinput<<std::endl;
    
    if((userinput.find("warning" )) != std::string::npos){
    
        log.log(logs::loglevel::WARN,userinput);
    
    } 
    
    else if(userinput.find("INFO")  != std::string::npos) {
    
        log.log(logs::loglevel::INFO, userinput);
    
    }
    
    else {
    
        log.log(logs::loglevel::ERROR, userinput);
        //log.clear();
    }


}