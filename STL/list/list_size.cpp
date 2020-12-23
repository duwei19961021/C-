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

	if(L1.empty())
	{
		cout << "list is empty" << endl;
	}
	else
	{
		cout << "list is not empty" << endl;
		cout << "total elem = " << L1.size() << endl;
	}
	
	L1.resize(4);
	PrintList(L1);
	L1.resize(7); // 0填充
	PrintList(L1);

}

int main()
{
	test01();
	return 0;
}
