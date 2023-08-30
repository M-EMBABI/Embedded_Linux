#include <iostream>

int main()
{
    int i,j;
    int row=0;
    std::cout<<"enter num of row: "<<std::endl;
    std::cin>>row;
    for(i=1;i<=row;i++)
    {
        
        // std::cout<<i<<std::endl;
        for(j=1;j<=i;j++)
        {
            std::cout<<"*";
            
        }
        std::cout<<std::endl;
        // std::cout<<j<<std::endl;
        // std::cout<<i<<std::endl;
    }
}