#include <iostream>
using namespace std;
#include <set>
#include <cstdlib>

void PrintSet(const set<int>&s)
{
	cout << "[ ";
	for(set<int>::const_iterator it = s.begin();it!=s.end();it++)
	{
		cout << *it  << " " ;
	}
	cout << "]" << endl;
}

// set容器构造和赋值
void test01()
{
	set<int>s1;
	s1.insert(3); 
	s1.insert(3); // 元素不能重复
	s1.insert(2);
	s1.insert(7);
	s1.insert(5);
	s1.insert(9);
	s1.insert(6);
	s1.insert(1);
	// 自动排序且元素不能重复
	PrintSet(s1);
}

int main()
{
	test01();
	return 0;
}
