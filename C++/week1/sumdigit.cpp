#include<iostream>
int main()
{
    int x=0,z=0,sum=0;
    std::cin>>x;
    while(x!=0)
    {
        z=x%10;
        sum=sum+z;
        x=x/10;
        
    }
    std::cout<<sum<<std::endl;

    return 0;
}