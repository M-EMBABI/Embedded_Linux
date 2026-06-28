#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

// Decimal --> Binary
std::string decimalToBinary(int decimal)
{
    if (decimal == 0)
        return "0";

    std::string binary;

    while (decimal > 0)
    {
        binary += (decimal % 2) + '0';
        decimal /= 2;
    }

    std::reverse(binary.begin(), binary.end());

    return binary;
}

// Binary --> Decimal
int binaryToDecimal(std::string binary)
{
    int decimal = 0;
    int power = 0;

    for (int i = binary.length() - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
            decimal += std::pow(2, power);

        power++;
    }

    return decimal;
}

int main()
{
    int choice;

    std::cout << "=============================\n";
    std::cout << " Decimal / Binary Converter\n";
    std::cout << "=============================\n";
    std::cout << "1. Decimal to Binary\n";
    std::cout << "2. Binary to Decimal\n";
    std::cout << "Enter your choice: ";

    std::cin >> choice;

    switch (choice)
    {
    case 1:
    {
        int decimal;

        std::cout << "Enter Decimal Number: ";
        std::cin >> decimal;

        std::cout << "Binary = "
                  << decimalToBinary(decimal)
                  << std::endl;

        break;
    }

    case 2:
    {
        std::string binary;

        std::cout << "Enter Binary Number: ";
        std::cin >> binary;

        std::cout << "Decimal = "
                  << binaryToDecimal(binary)
                  << std::endl;

        break;
    }

    default:
        std::cout << "Invalid Choice!" << std::endl;
    }

    return 0;
}