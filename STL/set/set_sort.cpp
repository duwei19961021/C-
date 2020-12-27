#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <set>

class MyCompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

void PrintSet(const set<int>&s)
{
	cout << "[ ";
	for(set<int>::const_iterator it = s.begin();it!=s.end();it++)
	{
		cout << *it << " ";
	}
	cout << "]"<< endl;
}


void PrintSet(const set<int,MyCompare>&s)
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
	srand(time(NULL));
	set<int>s1;
	for (int i=0;i<10;i++)
	{
		s1.insert(rand()%100);
	}
	PrintSet(s1);
}

void test02()
{
	srand(time(NULL));
	set<int,MyCompare>s1;
	for (int i=0;i<10;i++)
	{
		s1.insert(rand()%100);
	}
	PrintSet(s1);
}

int main()
{
	test01();
	test02();
	return 0;
}
