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
	PrintSet(s1);
	// set 容器的特点：所以元素插入的时候自动排序，不允许插入重复值
;	
	set<int>s2(s1); // 拷贝构造
	PrintSet(s2);

	set<int>s3 = s2; // 赋值
	PrintSet(s3);
}

int main()
{
	test01();
	return 0;
}
