#include <iostream>
using namespace std;
#include <deque>

void PrintDeque(const deque<int> d)
{
	cout << "[";
	for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)
	{
		cout << *it << " ";
	}
	cout << "]";
	cout << endl;
}

void test01()
{
	deque<int>d1;
	for(int i=0;i<10;i++)
	{
		d1.push_back(i);
	}
	PrintDeque(d1);

	deque<int>d2(d1.begin(),d1.end());
	PrintDeque(d2);

	deque<int>d3(d2);
	PrintDeque(d3);

	deque<int>d4(10,999);
	PrintDeque(d4);
}

int main()
{
	test01();
	return 0;
}
