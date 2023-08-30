+
#include <iostream>

int main()
{
    char x[128]={};
    int i=0;
    std::cout<<"---------------------"<<std::endl;
    std::cout<<"askii code table is:"<<std::endl;
    std::cout<<"---------------------"<<std::endl;

    for(i=0;x[i]<=127;i++)
    {   
         std::cout<<x[i]<<"|"<<int(x[i])<<std::endl;
        // x[i]=0;
        // std::cin>> x[i] ;
        // std::cout<< x[i] <<"|"<< int(x[i]) <<"\n" << std::endl;
    }
   
    return 0;
}
