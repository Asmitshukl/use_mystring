#include "mystring.h"
#include <cstring>
//definitions of all thee functions
mystring :: mystring(){
    data =new char[1];
    length=0;
    data[0]='\0';
}
//param ctor
mystring :: mystring(const char *str){
    data=new char[strlen(str)+1];
    length=strlen(str);
    strcpy(data,str);
}
mystring :: mystring(const mystring&other){
    data=new char[other.length+1];
    length=other.length;
    strcpy(data,other.data);
}
mystring ::~mystring(){
    delete[] data;
}
int mystring :: size() const{
    return length;
}
bool mystring ::empty() const{
    return length==0;
}
const char *mystring:: c_str() const{
    return data;
}
std:: ostream & operator << (std:: ostream &os,const mystring &str){
    os<<str.c_str();
}
//operator overloading of <<
char &mystring :: operator[](int index){
    if(index>=length){
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}
//find the index like find function
int mystring:: find(const mystring &substr)const{
    if(substr.length>length){
        return -1;
    }
    for(int i=0;i<length-substr.length;i++){
        int j;
        for(j=0;j<substr.length;j++){
            if(data[i+j]!=substr.data[j]){
                break;
            }
        }
        if(j==substr.length){
            return i;
        }
    }
    return -1;
}
