#ifndef LED_H_
#define LED_H_

//---------------------------- Include Section --------------------------------
#include "../GPIO/gpio.hpp"

//---------------------------- class Section --------------------------------

class LED : public GPIO {

    public:
        LED()=default;
        LED(std::string pin_num);
        Std_Return GPIO_ON() override ;
        Std_Return GPIO_OFF() override ;
        void Led_Blink(int count, int delay);

    private:
        std::string gpio_num ;
        std::string gpio_Path =  "/sys/class/gpio/gpio" ;
        std::string export_path = "/sys/class/gpio/export";
        std::string dir_Path;
        std::string val_Path;
        void Set_Direction() ;
};

#endif