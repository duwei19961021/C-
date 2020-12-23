#include <iostream>
using namespace std;
#include <stack>

void test()
{
	stack<int>s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	while(!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
}

int main()
{
	test();
	return 0;
}
