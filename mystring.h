#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
class mystring{
private:
    char *data;
    int length;
public:
    //default ctor
    mystring();
    //param ctoer
    mystring(const char *str);
    //copy ctor
    mystring(const mystring&other);
    //dtor
    ~mystring();
    
    int size()const;
    bool empty() const;
    const char *c_str() const;
    char &operator[](int index);
    int find(const mystring &substr) const;
    

    //overloading
    friend std::ostream &operator<<(std :: ostream &os ,const mystring &str);

};
#endif //mystring_h