#include<iostream>
int main()
{
    int arr[]={2,10,1,2,8,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int evennum = 0;
    for( int i=0 ; i<size ; i++){
        if(arr[i]%2 == 0){
            std::cout<<" num : "<<arr[i]<<" is even "<<" , at indix  "<<i<<std::endl;
            //break;
        }else{
            std::cout<<" num : "<<arr[i]<<" is odd "<<" , at indix  "<<i<<std::endl;
        }
    }
}