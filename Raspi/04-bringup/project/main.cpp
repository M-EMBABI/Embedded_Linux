#include "read/read.hpp"
#include "csv/csv.hpp"



int main() {
    write w;
    led l;
    while (1) {
        // Read humidity
        float humi = read_humi();
        if (humi == -1) {
            std::cerr << "Error reading humidity value" << std::endl;
        } else {
            std::cout << "humidity = " << humi / 1000 << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::seconds(10));  // Sleep for 10 seconds

        // Read temperature
        float temp = read_temp();
        if (temp == -1) {
            std::cerr << "Error reading temperature value" << std::endl;
        } else {
            std::cout << "temperature = " << temp / 1000 << std::endl;
        }

        // Convert to strings
        std::string humi_str = std::to_string(humi / 1000);  // Convert humidity to string
        std::string temp_str = std::to_string(temp / 1000);  // Convert temperature to string

        // Prepare data
        std::vector<std::string> data = {humi_str, temp_str};

        std::string file_name = "DHT_11.csv";

        // Write data to the CSV file
        if (w.write_csv(file_name, data)) {
            // LED blinks to indicate successful update
            l.write_0(led_val);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            l.write_1(led_val);
        }

        std::this_thread::sleep_for(std::chrono::seconds(10));  // Adjust as necessary
    }
}
