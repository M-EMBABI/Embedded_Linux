#include <algorithm>
#include <cmath>
#include<iostream>
#include <iterator>
#include <math.h>
int main ()
{
  int arr[]={1,2,5,8,9,4,7};
  
  std::cout <<*std::max_element(arr,arr+6)<< std::endl;
}
