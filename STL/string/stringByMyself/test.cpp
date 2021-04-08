#include <iostream>
#include "string.hpp"

int main()
{
	duwei::string s("duwei");
	std::cout << s[0] << std::endl;
	std::cout << s.capacity() << std::endl;
	std::cout << s.size() << std::endl;

	s.push_back('z');
	s.push_back('z');
	s.push_back('z');
	s.push_back('z');
	s.push_back('z');
	for(size_t i = 0; i < s.size(); i++)
	{
		std::cout << s[i] << std::endl;
	}

	duwei::string s2(s);
	std::cout << s2.c_str() << std::endl;

	s2.resize(20,'o');
	std::cout << s2.c_str() << std::endl;

	s2.insert(s2.size(),'p');
	std::cout << s2.c_str() << std::endl;

	s2.insert(0,'p');
	std::cout << s2.c_str() << std::endl;
	return 0;
}
