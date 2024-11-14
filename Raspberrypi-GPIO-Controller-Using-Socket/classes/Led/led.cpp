#include "led.hpp"
#include <unistd.h>

LED::LED(std::string pin_num) : gpio_num(pin_num){
    
    gpio_Path = gpio_Path + gpio_num;

    if (access(gpio_Path.c_str(), F_OK) == 0) 
    {
        std::cout << "File exists." << std::endl;
        Set_Direction();
    }
    else 
    {
        std::cout << gpio_Path << " Folder does not exist." << std::endl;
        std::cout << "will create Folder now." << std::endl;
        int fd= open(export_path.c_str(), O_WRONLY);
        if (fd == -1) 
        {
        std::cerr << "Error opening file: " << export_path << std::endl;
        }
        else
        {
            write( fd, gpio_num.c_str(), strlen(gpio_num.c_str()));
            close(fd);
            sleep(1);
            std::cout << "Data has been written to " << export_path << std::endl;
            Set_Direction();

        }
    }
}

void LED::Set_Direction(){

    dir_Path = gpio_Path + "/direction";
    int fd= open(dir_Path.c_str(), O_WRONLY);
    if (fd == -1) 
    {
        std::cerr << "Error opening direction file: " << dir_Path << std::endl;
    }
    else
    {
        write( fd, "out", strlen("out"));
        close(fd);
        std::cout << "Data has been written to " << dir_Path << std::endl;
     }
}

Std_Return LED::GPIO_ON() {
    Std_Return R_Value = Std_Return::STD_R_NOK;

    val_Path = gpio_Path + "/value";
    int fd= open(val_Path.c_str(), O_WRONLY);
    if (fd == -1) 
    {
        std::cerr << "Error opening value file: " << val_Path << std::endl;
        R_Value = Std_Return::STD_R_NOK;
    }
    else
    {
        write( fd, "1", strlen("1"));
        close(fd);
        std::cout << "value 1 has been written to " << val_Path << std::endl;
        R_Value = Std_Return::STD_R_OK;
     }
     return R_Value;
}

Std_Return LED::GPIO_OFF() {
    Std_Return R_Value = Std_Return::STD_R_NOK;

    val_Path = gpio_Path + "/value";
    int fd= open(val_Path.c_str(), O_WRONLY);
    if (fd == -1) 
    {
        std::cerr << "Error opening value file: " << val_Path << std::endl;
        R_Value = Std_Return::STD_R_NOK;
    }
    else
    {
        write( fd, "0", strlen("0"));
        close(fd);
        std::cout << "value 0 has been written to " << val_Path << std::endl;
        R_Value = Std_Return::STD_R_OK;
     }
     return R_Value;
}

void LED::Led_Blink(int count, int delay){
    for(int i=0; i< count; i++){
        GPIO_ON();
        sleep(delay);
        GPIO_OFF();
        sleep(delay);
    }
}
