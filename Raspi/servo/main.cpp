#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

// Function to write a value to a file (used to interact with sysfs)
void write_to_file(const std::string& path, const std::string& value) {
    std::ofstream file(path);
    if (file.is_open()) {
        file << value;
        file.close();
    } else {
        std::cerr << "Failed to open file: " << path << std::endl;
    }
}

// Function to set the servo to a given angle (90 or 180 degrees)
void set_servo_angle(int angle) {
    const std::string pwm_path = "/sys/class/pwm/pwmchip0/pwm0/";

    // Set the period to 20 ms (20,000,000 ns)
    write_to_file(pwm_path + "period", "20000000");

    // Calculate duty cycle for the desired angle (SG90 servo)
    int duty_cycle_ns = 0;
    if (angle == 90) {
        duty_cycle_ns = 1500000; // 1.5 ms for 90 degrees
    } else if (angle == 180) {
        duty_cycle_ns = 1500000; // 1.5 ms for 180 degrees
    } else {
        std::cerr << "Invalid angle. Only 90 and 180 are supported." << std::endl;
        return;
    }

    // Set the duty cycle for the desired angle
    write_to_file(pwm_path + "duty_cycle", std::to_string(duty_cycle_ns));

    // Enable the PWM signal
    write_to_file(pwm_path + "enable", "1");

    // Wait for the servo to reach the desired position (1 second)
    std::this_thread::sleep_for(std::chrono::milliseconds(600)); // 600 ms = 0.6 seconds


    // Disable the PWM signal after the servo reaches its position
    write_to_file(pwm_path + "enable", "0");
}

int main() {
    // Move the servo to 90 degrees
    std::cout << "Moving servo to 90 degrees..." << std::endl;
    set_servo_angle(90);

    // Wait a bit before moving to 180 degrees
    std::this_thread::sleep_for(std::chrono::milliseconds(1200)); // 600 ms = 0.6 seconds

    // Move the servo to 180 degrees
    std::cout << "Moving servo to 180 degrees..." << std::endl;
    set_servo_angle(180);

    return 0;
}
