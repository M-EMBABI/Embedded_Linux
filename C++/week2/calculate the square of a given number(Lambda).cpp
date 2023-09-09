#include <algorithm>
#include <cmath>
#include<iostream>
#include <iterator>
#include <math.h>

int main()
{
  auto sq=[](int x,int y = 2)->double
  {
    int z = pow(x,2) ; 
  
  return z ;
  };

  std::cout<<sq(1)<<std::endl;
  
}
