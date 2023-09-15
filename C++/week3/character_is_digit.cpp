#include<iostream>
#include <cctype> 

class digit{
    public:
        char isdig(char ch){
            if(isdigit(ch))
            {
                std::cout<<" is digit"<<std::endl;
            }
            else {
            std::cout<<"is not digit"<<std::endl;
            }
            return ch;
        }
};

int main()
{
    digit d;
    d.isdig('5');
}