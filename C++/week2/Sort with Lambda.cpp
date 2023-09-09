#include <iostream>
#include <algorithm>

int main() {
    int numbers[] = {7, 2, 5, 1, 9};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    
    std::sort(numbers, numbers + size, [](int a, int b) {
        return a < b;
    });

    std::cout << "Ascending order: ";
    for (int i = 0; i < size; i++) 
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // Sort in descending order
    std::sort(numbers, numbers + size, [](int a, int b) {return a > b;});

    std::cout << "Descending order: ";
    for (int i = 0; i < size; i++) 
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
