#include <iostream>
#include <numeric> 
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]); 

  
    int sum = accumulate(arr, arr + size, 0);

    cout << "The sum of the array elements is: " << sum << endl;

    return 0;
}
