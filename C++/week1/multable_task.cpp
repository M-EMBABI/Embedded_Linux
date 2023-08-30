#include <codecvt>
#include <iostream>

int main()
{
    int i=0,j=0;
    
    for(i=0;i<=10;i++)
    {
        for(j=0;j<=10;j++)
        {
            std::cout<<i;
            std::cout<<"*";
            std::cout<<j;
            std::cout<<" = "<<i*j<<std::endl;
        }
        j=0;
    }




    return 0;
}