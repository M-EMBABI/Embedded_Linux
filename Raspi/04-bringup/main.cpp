#include "read/read.hpp"
#include "csv/csv.hpp"



int main(){
    write w;
    led l;
    while (1)
    {
        float humi = read_humi();
        if (humi == -1) {
            std::cerr << "Error reading humidity value" << std::endl;
        } else {
            std::cout << "humidity = " << humi / 1000 << std::endl;
            
        }
        
        std::this_thread::sleep_for(std::chrono::seconds(2));

        float temp = read_temp();
        if (temp == -1) {
            std::cerr << "Error reading temperature value" << std::endl;
        } else {
            std::cout << "temperature = " << temp / 1000 << std::endl;
            
        }
        // Convert floats to strings
        std::string humi_str = std::to_string(humi / 1000);
        std::string temp_str = std::to_string(temp / 1000);

        std::this_thread::sleep_for(std::chrono::seconds(2));

        std::vector<std::string> data = {humi_str, temp_str};

        std::string file_name="DHT_11.csv";
        std::string led = led_val;
        if(w.write_csv(file_name,data) == true){
            l.write_0(led);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            l.write_1(led);
        }
        

    }
}
