#include <algorithm>
#include <cstring>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>

using namespace std;
class mystring{
    public:
        char *str;
        mystring():str(nullptr){}
        mystring(const char *i) : str(new char[strlen(i) + 1]) {
        strcpy(str, i);
        }
        mystring(const mystring& sorce);
        mystring(mystring&&ex);
        mystring& operator=(const mystring& other);
        friend mystring operator+( const mystring& s1,const mystring& s2);
        friend istream& operator>>(istream &is,mystring& obj);
        friend ostream& operator<<(ostream&os,const mystring&obj);
        int strlength();
        void swap(mystring& r);


        ~mystring(){
            delete[] str;
            }

};
//

mystring::mystring(const mystring& s){
    str = new char[strlen(s.str) + 1];
    strcpy(str, s.str);
}
////
mystring::mystring(mystring&&ex){
    this->str=ex.str;
    ex.str=nullptr;
}
mystring& mystring::operator=(const mystring& other){
    if (this==&other){
        return *this;
    }
    delete [] str;
    str=new char[strlen(other.str)+1];
    strcpy(const_cast<char*>(str),other.str);
    return *this;

}
///////
mystring operator+( const mystring& s1,const mystring& s2){
   int length=strlen(s1.str)+strlen(s2.str);
   char *buf=new char[length+1];
   strcpy(buf, s1.str);
   strcat(buf, s2.str);
   buf[length]='\0';
   mystring temp{buf};

   delete [] buf;
   return temp;
   
}
////////////


istream& operator>>(istream &is, mystring& obj){
    char *buf=new char[1000];
    memset(&buf, 0, sizeof(buf));
    is>>buf;
    obj=mystring{buf};
    delete [] buf;
    return is;

}
////////////////

ostream& operator<<(ostream&os,const mystring&obj){
    os<<obj.str;
    return os;
}

int mystring::strlength(){
    return strlen(str);
}
/////////////////////
void mystring:: swap(mystring& r){
    char *temp=str;
    str=r.str;
    r.str=temp;
}

int main(){
    
    mystring m("f");
    mystring f("m");
    mystring g("l");
    mystring i("hi");
    i=std::move(g);
    cout<<i<<"\n";
    // g.swap(f);
    // m.swap(g);

    cout<<m<<"\n";
    cout<<g<<"\n";
    f=m+g;
    cout<<f<<"\n";
    
}
