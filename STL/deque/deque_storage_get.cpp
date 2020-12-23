#include <iostream>
using namespace std;
#include <deque>

void test01()
{
	deque<int>d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(4);
	d.push_back(5);
	d.push_back(6);

	for(int i=0;i<d.size();i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;

	for(int i=0;i<d.size();i++)
	{
		cout << d.at(i) << " ";
	}
	cout << endl;

	cout << d.front() << endl; // 首元素
	cout << d.back() << endl; // 尾元素
}

int main()
{
	test01();
	return 0;
}
