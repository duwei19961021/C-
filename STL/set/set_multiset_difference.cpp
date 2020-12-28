#include <iostream>
using namespace std;
#include <set>

void test01()
{
	set<int>s;
	s.insert(10);
	s.insert(10);
}

int main()
{
	test01();
	return 0;
}
