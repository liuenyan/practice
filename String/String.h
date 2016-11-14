#ifndef _ENYAN_STRING_H_
#define _ENYAN_STRING_H_

#include <cstring>
#include <iostream>

namespace enyan{
    class String{
        char *s;
        void duplicate(const char *cp);
    public:
        String();
        String(int n, char c);
        String(const String &rs); //copy constructor
        String(const char *cp);
        ~String(){delete[] s;};

        String& operator=(const String &rs);
        String& operator=(const char *cp);

        size_t size() const {return strlen(s);};
        const char *c_str() const{return s;};
        friend std::ostream &operator<<(std::ostream &, String &);
    };
};

#endif
