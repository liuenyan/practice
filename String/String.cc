#include "String.h"

namespace enyan{
	void String::duplicate(const char *cp){
		if (cp){
			s = new char[strlen(cp)+1]();
			strcpy(s, cp);
		}
		else{
			// 当 cp 为空时，直接指向长度为 0 的 C 字符串
			s = new char[1]();
		}
	}

	String::String(){
		s = new char[1]();
	}

	String::String(int n, char c){
		s = new char[n+1]();
		for(int i=0; i<n; ++i){
			s[i] = c;
		}
	}

	String::String(const String &rs) {
		duplicate(rs.s);
	}

	String::String(const char *cp){
		duplicate(cp);
	}

	String& String::operator=(const String &rs){
		// 传入的参数是自己本身直接返回
		if (&rs == this)
			return *this;

		return operator=(rs.s);
	}
	String& String::operator=(const char *cp){
		// 先复制再释放旧内存， 保证在当cp == this->s 时能够正确复制
		char *old = s;
		duplicate(cp);
		delete[] old;
		return *this;
	}

	std::ostream& operator<<(std::ostream &os, String &str){
		os << str.s;
		return os;
	}
}