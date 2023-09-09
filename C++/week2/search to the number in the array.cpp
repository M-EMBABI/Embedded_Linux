#include <algorithm>
#include <cmath>
#include<iostream>
#include <iterator>
#include <math.h>

int searchNumber(int arr[], int size, int target) 
{
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == target) 
        {
            return i;
        }
    }

    return -1; 
}

int main() {
    int arr[] = { 10, 20, 30, 40, 50 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    std::cout << "Enter a number to search: ";
    std::cin >> target;

    int index = searchNumber(arr, size, target);

    if (index != -1) 
    {
        std::cout << "Number found at index " << index << std::endl;
    } 
    else 
    {
        std::cout << "Number not found in the array." << std::endl;
    }

    return 0;
}
