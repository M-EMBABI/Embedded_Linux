
#include <iostream>

int main()
{
    int x,y,z,max;
    std::cin>>x>>y>>z;
    max=x;
    if(x<y)
    {
        max=y;
    }
    if(y<z)
    {
        max=z;
    }
    std::cout<<"max num= "<<max<<std::endl;
    return 0;
}