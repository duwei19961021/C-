#include <iostream>
using namespace std;
#include <deque>

void PrintDeque(const deque<int>d)
{
	cout << "[";
	for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)
	{
		cout << *it << " ";	
	}
	cout << "]"<<endl;
}

void test01()
{
	deque<int>d1;
	for(int i=0;i<10;i++)
	{
		d1.push_back(i);
	}
	PrintDeque(d1);

	// deque& operator=(const deque &deq),重载操作符 =
	deque<int>d2 = d1;
	PrintDeque(d2);

	deque<int>d3;
	// 区间方式赋值
	d3.assign(d2.begin(),d2.end());
	PrintDeque(d3);

	deque<int>d4;
	// 拷贝10个999给容器本身
	d4.assign(10,999);
	PrintDeque(d4);
}

int main()
{
	test01();
	return 0;
}
