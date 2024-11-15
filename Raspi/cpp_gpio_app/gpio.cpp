#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


#define PIN_NUM "21"
#define PIN_DIRECTION "out"
#define PIN_HIGH "1"
#define PIN_LOW "0"

int main()
{
    /* code */
    int fd;
    // export the pin
    fd = open("/sys/class/gpio/export",O_WRONLY);
    if(fd == -1 ){
        std::cout<<"we cannot open export\n";

    }
    write(fd,PIN_NUM,strlen(PIN_NUM));
    close(fd);
    sleep(1);

    //in/out diriction
    fd = open("/sys/class/gpio/gpio21/direction",O_WRONLY);
    if(fd == -1 ){
        std::cout<<"we cannot open direction\n";

    }
    write(fd,PIN_DIRECTION,strlen(PIN_DIRECTION));
    close(fd);
    sleep(1);
    //write 1 or 0 in val
    fd = open("/sys/class/gpio/gpio21/value",O_WRONLY);
    if(fd == -1 ){
        std::cout<<"we cannot open value\n";

    }
    for(int i = 0 ; i < 5 ; i++ ){
    write(fd,PIN_HIGH,strlen(PIN_HIGH));
    sleep(2);
    write(fd,PIN_LOW,strlen(PIN_LOW));
    sleep(2);
    }

    close(fd);
    return 0;
}
