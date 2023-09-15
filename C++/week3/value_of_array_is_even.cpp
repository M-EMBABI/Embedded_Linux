#include<iostream>
int main()
{
    int arr[]={2,10,1,2,8,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;size>i;i++){
        if(arr[i]%2 ==0)
        {
            std::cout<<"indix: "<<i<<" is even\n";
        }
        else {
        std::cout<<"indix: "<<i<<" arr is odd\n";
        }
    }
}