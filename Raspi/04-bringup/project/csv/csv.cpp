#include "csv.hpp"


bool write::write_csv(const std::string &filename, const std::vector<std::string> &data) {
    std::ofstream file(filename, std::ios::app);  // Open the file in append mode

    // Write data in a more structured manner
    if (file.is_open()) {
        for (const auto &row : data) {
            file << row << ",";  // This adds the comma between humidity and temperature values
        }
        file << std::endl;  // Write a new line after each pair of values
    } else {
        std::cerr << "Error opening CSV file" << std::endl;
        return false;  // Return false in case of failure
    }
    return true;
}
