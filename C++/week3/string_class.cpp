#include <cstddef>
#include <cstring>
#include <iostream>
#include <stdexcept>
class string{
    public:
        string() : data(nullptr),length(0){}
        string(const char* str) : data(nullptr),length(0){
            if(str){
                length=std::strlen(str);
                data=new char[length+1];
                std::strcpy(data,str);
            }
        }

        ~string(){
            delete [] data;
        }        
        size_t getlength() const{
            return length;
        }
        const char* getstring() const {
            return data;
        }
    private:
        char* data;
        size_t length;
    
};
//////////////////////////////////////
int main()
{
    string s1("hi");
    string s2("member");
    std::cout << "str1 Length: " << s1.getlength() << std::endl;
    std::cout << "str1 String: " << s1.getstring() << std::endl;

    std::cout << "str2 Length: " << s2.getlength() << std::endl;
    std::cout << "str2 String: " << s2.getstring() << std::endl;

    return 0;
}