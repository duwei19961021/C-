#include "string.h"
#include <iostream>
#include <cstring>

namespace duwei
{
	class string
	{
	public:
		typedef char* iterator;
		
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _len;
		}

		string(char* str = "")
		{
			_len = strlen(str);
			_str = new char[strlen(str)+1];
			strcpy(_str,str);
		}

		/*
		string(const duwei::string& s)
				:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}
		*/

		string(const duwei::string& s)
		{
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);	
		}

		string()
			:_str(new char[1])
		{
			_str[0] = '\0';
		}
		~string()
		{
			delete[] _str;
		}
		char& operator[](size_t i)
		{
			return _str[i];
		}

		const char* c_str()
		{
			return _str;
		}

		string& operator=(const string& s)
		{
			if(&s != this)
			{
				delete[] _str;
				_str = new char[strlen(s._str)+1];
				strcpy(_str,s._str);
			}	
			return *this;
		}
	private:
		size_t _len;
		char*  _str;
	};
}

int main()
{
	duwei::string s("1996");
	std::cout << s[3] << std::endl;
	s[2] = 'x';
	std::cout << s[2] << std::endl;
	std::cout  << s.c_str() << std::endl;
	s[3] = '0';
	duwei::string s2(s);
	std::cout << s2.c_str() << std::endl;

	duwei::string s3 = s2;
	std::cout << s3.c_str() << std::endl;
	s3[0] = 'q';
	std::cout << s3.c_str() << std::endl;
	std::cout << s2.c_str() << std::endl;
	return 0;
}
