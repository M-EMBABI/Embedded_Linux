#ifndef B1330C2F_AACA_4946_AA2B_C03577E06232
#define B1330C2F_AACA_4946_AA2B_C03577E06232



#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <string>
#include <stdexcept>  // For std::invalid_argument

#define  humi_val "/sys/bus/iio/devices/iio:device0/in_humidityrelative_input"
#define  temp_val "/sys/bus/iio/devices/iio:device0/in_temp_input"
#define  led_val "/sys/class/leds/led_test/brightness"

float read_humi(){
    std::ifstream humi_file(humi_val);
    std::string humi_value;
    if (!humi_file) {
        std::cerr << "Error opening humidity file" << std::endl;
        return -1;  // Return error value
    }
    humi_file >> humi_value;
    if (humi_value.empty()) {
        std::cerr << "Humidity value is empty" << std::endl;
        return -1;  // Return error value
    }
    //std::cout << "Raw humidity value: " << humi_value << std::endl;  // Debug print
    try {
        return std::stof(humi_value);  // Try to convert to float
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid humidity value: " << humi_value << std::endl;
        return -1;  // Return error value
    } catch (const std::out_of_range& e) {
        std::cerr << "Humidity value out of range: " << humi_value << std::endl;
        return -1;  // Return error value
    }
}

float read_temp(){
    std::ifstream temp_file(temp_val);
    std::string temp_value;
    if (!temp_file) {
        std::cerr << "Error opening temperature file" << std::endl;
        return -1;  // Return error value
    }
    temp_file >> temp_value;
    if (temp_value.empty()) {
        std::cerr << "Temperature value is empty" << std::endl;
        return -1;  // Return error value
    }
    //std::cout << "Raw temperature value: " << temp_value << std::endl;  // Debug print
    try {
        return std::stof(temp_value);  // Try to convert to float
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid temperature value: " << temp_value << std::endl;
        return -1;  // Return error value
    } catch (const std::out_of_range& e) {
        std::cerr << "Temperature value out of range: " << temp_value << std::endl;
        return -1;  // Return error value
    }
}
class led{
    public:
    led()=default;
        void write_0(const std::string &filename){
            std::ofstream file(filename);
            if(!file.is_open()){
                system("sudo chmod 666 /sys/class/leds/led_test/brightness\n");
            }
            file<<"0"<<std::endl;

        }
        void write_1(const std::string &filename){
            std::ofstream file(filename);
            if(!file.is_open()){
                system("sudo chmod 666 /sys/class/leds/led_test/brightness\n");
            }
            file<<"1"<<std::endl;

        }
    
    ~led(){
        write_1(led_val);
    }
        
};
#endif /* B1330C2F_AACA_4946_AA2B_C03577E06232 */
