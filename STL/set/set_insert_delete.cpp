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

void test01()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	PrintSet(s1); // [ 10 20 30 40 ]

	s1.erase(s1.begin());
	PrintSet(s1); // [ 20 30 40 ]

	s1.erase(30);
	PrintSet(s1); // [ 20 40 ]

	s1.clear();
	PrintSet(s1);
}

int main()
{
	test01();
	return 0;
}
