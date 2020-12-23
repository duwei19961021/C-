#include <iostream>
using namespace std;
#include <deque>

void PrintDeque(const deque<int>d)
{
	cout << "[" ;
	for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)
	{
		cout << *it << " ";
	}
	cout << "]" << endl;
}

void test01()
{
	deque<int>d1;
	for(int i=0;i<10;i++)
	{
		d1.push_back(i);
	}

	cout << "d1.empty() = " << d1.empty() << endl;
	cout << "d1.size() = " << d1.size() << endl; // deque没有容量的概念

	// 重新指定大小
	// d1.resize(15); // 新增的空间默认以0填充
	// PrintDeque(d1);

	d1.resize(15,999); // 新增的空间默认以999填充
	PrintDeque(d1);

	d1.resize(5);
	PrintDeque(d1);
}

int main()
{
	test01();
	return 0;
}
