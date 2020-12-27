#include <iostream>
using namespace std;
#include <set>

void PrintSet(const set<int>&s)
{
	cout << "[ ";
	for(set<int>::const_iterator it = s.begin();it!=s.end();it++)
	{
		cout << *it << " ";
	}
	cout << "]"<< endl;
}

// 大小
void test01()
{
	set<int>s1;
	s1.insert(9);
	s1.insert(3);
	s1.insert(1);
	s1.insert(8);
	s1.insert(4);
	s1.insert(7);

	PrintSet(s1);

	if(s1.empty())
	{
		cout << "s1为空" << endl;
	}
	else
	{
		cout << "s1不为空" << endl;
		cout << "s1.size() = " << s1.size() << endl;
	}
}

// 交换
void test02()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	PrintSet(s1);

	set<int> s2;
	s2.insert(100);
	s2.insert(200);
	s2.insert(300);
	s2.insert(400);
	PrintSet(s2);

	s1.swap(s2);
	PrintSet(s1);
	PrintSet(s2);
}

int main()
{
	test02();
	return 0;
}
