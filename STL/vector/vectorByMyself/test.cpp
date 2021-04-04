#include "vector.hpp"
#include <iostream>

void test1()
{
	duwei::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(8);
	v.push_back(4);

	for(duwei::vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout << *it << std::endl;		
	}

	v.resize(10,1);

	std::cout << std::endl;

	duwei::vector<int>::iterator it = v.begin();
	it = v.insert(++it,10);
	/*
	 * 如果v发生扩容那么it就会失效,
	 * 解决办法就是将新的迭代器返回。
	 */

	auto it2 = v.begin();
	while(it2 != v.end())
	{
		if(*it2 % 2 == 0)
		{
			it2 = v.erase(it2);
		}
		else
		{
			it2++;
		}
	}

	for(size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}
}

int main()
{
	test1();
	return 0;
}
