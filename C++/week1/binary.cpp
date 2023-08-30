#include<iostream>
#include<bitset>
 int main()
 {
    int x=0,y=0;
    
    std::cout<<"1- binary to dicimal  2-dicimal to binary"<<std::endl;
    std::cin>>y;
        std::cout<<"enter var"<<std::endl;

    

    if(y==1)
    {
        char binaryNumber[] = "0011" ;
        
        
    
        std:: cout << std::stoi(binaryNumber, 0, 2);
    return 0;
    }
    if(y==2)
    {
         std::bitset<16> var (x);
         std::cout<<var;
    }
    else
    {
        
    }
   
 }