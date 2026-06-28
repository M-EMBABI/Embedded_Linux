#include<iostream>
#include <cctype> 

class digit{

    public:
        char isdig(char ch){
            if(isdigit(ch)){
                std::cout<<" it is digit"<<std::endl;
            }else
            {
                std::cout<<" it is not digit"<<std::endl;                
            }
        }
};

int main()
{
    digit d;
    d.isdig('g');
}