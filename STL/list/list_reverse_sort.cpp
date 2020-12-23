#include <iostream>
using namespace std;
#include <list>
#include <ctime>
#include <cstdlib>

void PrintList(const list<int>&L)
{
	cout << "[";
	for(list<int>::const_iterator it=L.begin();it!=L.end();it++)
	{
		cout << *it << " ";
	}
	cout << "]" << endl;
}

bool compare(int a, int b)
{
	return a > b;
}

void test01()
{
	list<int>L1;
	srand(time(NULL));
	for(int i=0;i<100;i++)
	{
		L1.push_back(rand()%100);	
	}

	PrintList(L1);

	// 反转
	L1.reverse();
	PrintList(L1);

	// 排序
	L1.sort();
	PrintList(L1);

	// 降序
	L1.sort(compare);
	PrintList(L1);
}

int main()
{
	test01();
	return 0;
}
