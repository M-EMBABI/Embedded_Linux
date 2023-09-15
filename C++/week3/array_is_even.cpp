#include<iostream>
int main()
{
    int arr[]={2,10,1,5,8,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    bool alleven=true;
    for(int i=0;size>i;++i){
        if( arr[i]%2 != 0 )
        {
           alleven=false;
            break;
        }
    }    
        if(alleven){
            std::cout<<"all elements are even\n";
        }
        else {
        std::cout<<"not all elements are even \n";
        }
    
    return 0;
}