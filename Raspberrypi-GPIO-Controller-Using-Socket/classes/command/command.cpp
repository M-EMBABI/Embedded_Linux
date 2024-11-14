#include "command.hpp"

Std_Return Command::executeCmdLine(std::string commaned){
    Std_Return R_value = Std_Return::STD_R_OK;
    /*
    split a std::string into substrings using a specified delimiter 
    and store the result in a std::vector<std::string>
    */
    //---------------------------Start spliting-----------------------------//
    std::vector<std::string> tokens;
    std::istringstream tokenStream(commaned);
    std::string token;
    while (std::getline(tokenStream, token, ' ')) {
        tokens.push_back(token);
    }
    //-----------------------------End spliting-----------------------------//

    
   
    if(tokens[0] == "led")
    {
        LED led(tokens[1]);
        if(tokens[2] == "on")
        {
            led.GPIO_ON();
            R_value = Std_Return::STD_R_OK;
        }
        else if (tokens[2] == "off"){
            led.GPIO_OFF();
            R_value = Std_Return::STD_R_OK;
        }
        else if (tokens[2] == "blink"){
            led.Led_Blink(std::stoi(tokens[3]),std::stoi(tokens[4]));
            R_value = Std_Return::STD_R_OK;
        }
        else {
            std::cout <<  "argument number 3 Fault" << std::endl;
            R_value = Std_Return::STD_R_NOK;
        }
    }
    else 
    {
        R_value = Std_Return::STD_R_OK;
    }

    return R_value;
}