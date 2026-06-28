#include <iostream>
#include <algorithm>

int main()
{
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};

    int merged[6];

    std::merge(arr1, arr1 + 3,
               arr2, arr2 + 3,
               merged);

    for (int i = 0; i < 6; i++)
        std::cout << merged[i] << " ";
}