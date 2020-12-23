#include <iostream>
using namespace std;
#include <list>

void test01()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);

	// L1[0]; 不支持
	// L1.at(0); 不支持 list本质是链表,不是用连续的线性空间存储数据,迭代器也是不支持随机访问的
	
	list<int>::iterator it = L1.begin();
	it++;
	// it+=1; 不支持
}

int main()
{
	test01();
	return 0;
}
