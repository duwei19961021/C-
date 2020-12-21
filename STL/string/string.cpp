#include <iostream>
using namespace std;
#include <string>

/*
 * string的本质是一个类，内部维护着一个char*
 * */

void test01()
{
	string s1;
	const char * str = "hello world";
	string s2(str);
	cout << "s2 = "<< s2 << endl;

	string s4(10,'a');
	s4+="bb";
	cout << s4 << endl;
}

int main()
{
	test01();
}
