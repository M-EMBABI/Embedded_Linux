#include <iostream>
int deleten(int arr[], int n, int l) 
{
   int i, newi = 0;
   for (i = 0; i < n; i++)
    {
      if (i != l ) 
      {
         arr[newi] = arr[i];
         newi++;
      }
   }
   
   return newi;
}
int main() 
{
   int n = 9;
   int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
   int updatedArrayLength = deleten(arr, n, 2);
   for (int i = 0; i < updatedArrayLength; i++) 
   {
     std:: cout << arr[i] << " ";
   }
   std::cout << std::endl;
   return 0;
}
