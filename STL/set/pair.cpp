#include <iostream>
using namespace std;

void test01()
{
	// 1 、创建对组
	pair<string,int>p("tom",24);
	cout << "name = " << p.first << "\nage = " << p.second << endl;

	// 2、创建对组
	pair<string,int>p2 = make_pair("jim",25);
	cout << "name = " << p2.first << "\nage = " << p2.second << endl;
}

int main()
{
	test01();
	return 0;
}
