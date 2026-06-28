#include <iostream>

int main()
{
    int number;
    int sum = 0;

    std::cout << "Enter an integer: ";
    std::cin >> number;

    while (number != 0)
    {
        sum += number % 10; 
        number /= 10;       
    }

    std::cout << "Sum = " << sum << std::endl;

    return 0;
}