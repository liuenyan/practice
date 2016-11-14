#include "String.h"

using enyan::String;
using namespace std;

int main(){
    String s1(5, 'c');
    cout << s1 << endl;
    cout << s1.size() << endl;
    String s2 = s1;
    cout << s2 << endl;
    cout << s2.size() << endl;

    String s3;
    cout << s3 << endl;
    cout << s3.size() << endl;

    s3 = s2;
    cout << s3 << endl;
    cout << s3.size() << endl;

    //尝试拷贝自身
    s3 = s3;
    cout << s3 << endl;
    cout << s3.size() << endl;

    const char *cp1 = "test";
    String s4 = cp1;

    cout << s4 << endl;
    cout << s4.size() << endl;

    //调用拷贝赋值运算符
    const char *cp2 = s4.c_str();
    s4 = cp2;

    cout << s4 << endl;
    cout << s4.size() << endl;

    return 0;
}
