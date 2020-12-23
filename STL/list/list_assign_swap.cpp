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

	list<int>L2;
	L2 = L1; // operator= 重载
	PrintList(L2);

	list<int>L3(L1.begin(),L1.end());
	PrintList(L3);

}

void test02()
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

	list<int>L2;
	L2.assign(10,100); // 初始化10个100
	cout << "before swap():"<< endl;
	PrintList(L1);
	PrintList(L2);

	
	L1.swap(L2);

	cout << "after swap():"<< endl;
	PrintList(L1);
	PrintList(L2);

}

int main()
{
	test02();
	return 0;
}
