#include <iostream>
using namespace std;
#include <list>

void PrintList(const list<int>L)
{
	cout << "[";
	for(list<int>::const_iterator it=L.begin();it!=L.end();it++)
	{
		cout << *it << " ";	
	}
	cout << "]" << endl;
}

void test01()
{
	list<int>L1;
	L1.push_back(1);
	L1.push_back(2);
	L1.push_back(3);
	L1.push_back(4);
	L1.push_back(5);
	L1.push_back(6);
	L1.push_back(7);

	PrintList(L1);

	list<int>L2(L1.begin(),L1.end()); // 区间方式初始化 
	PrintList(L2);

	list<int>L3(L2); // 拷贝构造
	PrintList(L3);

	list<int>L4(4,999);// 初始化4个元素,值都是999
	PrintList(L4);

}

int main()
{
	test01();
	return 0;
}
