#include<iostream>
#include <stdexcept>
#include<cstring>



class string{
    private:
        char *str;
        int size;


    public:
        string():str(nullptr),size(0){

        }

        string(const char *str):str(const_cast<char*>(str)),size(0){
        if (str == nullptr)
        {
            this->str = new char[1];
            this->str[0] = '\0';
            return;
        }
            size = std::strlen(str);
            this -> str = new char [size+1];
            std::strcpy(this->str,str);
        }


        ~string(){
            delete [] str;
        }
        
        size_t get_lengh() const ;
        char *get_string()const;
};

size_t string::get_lengh() const {
    return size;
}

char *string::get_string()const {
    return str;
}

int main(){
    string s1("muhammad");
    string s2("embabi");
    
    std::cout << "str1 Length: " << s1.get_lengh() << std::endl;
    std::cout << "str1 String: " << s1.get_string() << std::endl;

    std::cout << "str2 Length: " << s2.get_lengh() << std::endl;
    std::cout << "str2 String: " << s2.get_string() << std::endl;
}