#include <iostream>

int main() {
    int arr[9991]; 
    
    int value = 10;
    int index = 0;
    
    while (value <= 10000 && index < 9991) {
        arr[index] = value;
        value++;
        index++;
    }
    
    
    
    for (int i = 0; i < 9991; i++) {
        std::cout << arr[i] << " ";
    }
    
    return 0;
}
