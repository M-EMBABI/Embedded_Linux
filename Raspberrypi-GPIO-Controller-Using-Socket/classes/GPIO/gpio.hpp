#ifndef _GPIO_H_
#define _GPIO_H_

#include "../../configrations.hpp"


class GPIO {
    public:
        virtual Std_Return GPIO_ON()  = 0 ;
        virtual Std_Return GPIO_OFF() = 0 ;
};

#endif