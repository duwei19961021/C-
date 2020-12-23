#include <iostream>
using namespace std;
#include <list>

void PrintList(const list<int>&L)
{
	cout << "[ ";
	for(list<int>::const_iterator it=L.begin();it!=L.end();it++)
	{
		cout << *it << " ";
	}
	cout << "]" << endl;
}

void test01()
{
	list<int>L1;
	for(int i=0;i<10;i++)
	{
		L1.push_back(i);
	}

	PrintList(L1);

	//删除容器中最后一个元素
	L1.pop_back();
	PrintList(L1);

	// 头插一个元素
	L1.push_front(999);
	PrintList(L1);

	// 从容器头部移除一个元素
	L1.pop_front();
	PrintList(L1);

	// 在指定的位置插入一个元素,返回新数据的位置
	L1.insert(L1.begin(),888);
	PrintList(L1);

	// 在指定位置插入n个元素
	L1.insert(L1.end(),3,777);
	PrintList(L1);

	// 在指定位置插入[beg,end]区间的元素
	list<int>L2;
	L2.insert(L2.begin(),L1.begin(),L1.end());
	PrintList(L2);

	// 清空容器
	L2.clear();
	PrintList(L2);

	// 清空指定区间的元素
	L1.erase(L1.begin(),L1.end());
	PrintList(L1);

	L1.push_back(1);
	L1.push_back(2);
	L1.push_back(3);
	L1.push_back(4);
	L1.push_back(4);
	L1.push_back(4);
	L1.push_back(4);
	PrintList(L1);

	// 删除指定位置的元素
	L1.erase(L1.begin());
	PrintList(L1);

	// 删除值与4匹配的元素
	L1.remove(4);
	PrintList(L1);
}

int main()
{
	test01();
	return 0;
}
