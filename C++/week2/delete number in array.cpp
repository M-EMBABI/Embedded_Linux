#include <iostream>




int deletint(int arr[],int size ,int num ){
   int newarr=0;
   for(int i = 0 ; i< size ; i++){
      if(i != num){
         arr[newarr] = arr[i];
         newarr++;
      }
   }
   return newarr;
}
int main() 
{
   int arr[] = { 0, 2, 3, 4, 5, 6, 7, 8, 9 };
   int size = sizeof(arr)/sizeof(arr[0]);
   int updatedArrayLength = deletint(arr, size, 0);
   for (int i = 0; i < updatedArrayLength; i++) 
   {
     std:: cout << arr[i] << " ";
   }
   std::cout << std::endl;
   return 0;
}
