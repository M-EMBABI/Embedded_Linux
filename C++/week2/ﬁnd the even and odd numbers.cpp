
#include <iostream>

int main() 
{
    int numbers[] = {2, 5, 8, 11, 14, 17};
    int evenNumbers[100];
    int oddNumbers[100];
    int evenCount = 0;
    int oddCount = 0;

    int size = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < size; i++) 
    {
        if (numbers[i] % 2 == 0) 
        {
            evenNumbers[evenCount] = numbers[i];
            evenCount++;
        } 
        else 
        {
            oddNumbers[oddCount] = numbers[i];
            oddCount++;
        }
    }

    std::cout << "Even numbers: ";
    for (int i = 0; i < evenCount; i++)
    {
        std::cout << evenNumbers[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Odd numbers: ";
    for (int i = 0; i < oddCount; i++) 
    {
        std::cout << oddNumbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
