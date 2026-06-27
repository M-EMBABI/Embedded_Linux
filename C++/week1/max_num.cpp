
#include <iostream>
#include <algorithm>

int max_num(int *num){
    int val = *std::max_element(num,num+3);
    return val;
}

void input(int arr[]){
    int x,y,z;
    std::cout<<"please enter your input : "<<std::endl;
    for (int i=0 ; i<3 ; i++){
        std::cout<<"num "<<i+1<<": ";
        std::cin>>arr[i];
    }

}
int main(){

    int arr2[3];
    input(arr2);
    std::cout<<max_num(arr2)<<std::endl;
    
}