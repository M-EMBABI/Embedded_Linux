
#include <iostream>



int getASCIIValue(char character){
    return static_cast<int>(character);
}


int main()
{
    char c ;
    std::cout<<"*******please enter your input*******"<<std::endl;
    std::cin>>c;
    std::cout<<"---------------------"<<std::endl;
    std::cout << "askii code for :" <<c << " -> " << getASCIIValue(c) << '\n';
    std::cout<<"---------------------"<<std::endl;


    return 0;
}
