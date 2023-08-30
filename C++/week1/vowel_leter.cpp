#include <iostream>
 int main()
{

    char x;
  
    std::cin>>x;

    if(x=='A'||x=='I'||x=='O'||x=='U'||x=='E'||x=='a'||x=='i'||x=='o'||x=='u'||x=='e')
    {
        printf("letter is vowel");
    }
    else
    {
        std::cout<<"letter is not vowel"<<std::endl;
    }
    return 0;


}  