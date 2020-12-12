#include <iostream>
using namespace std;


void func(int& ref) // 发现是引用，转换为int* const ref = &a;
{
	ref = 100; // ref是引用，转换为*ref = 100
}

int main()
{
	int a = 10;

	int& ref = a; // 自动转换为int* const ref = &a;指针常量时指针指向不可修改，也说明了为什么引用不可以更改
	ref = 20; // 内部发现ref是引用，自动帮我们转换为: *ref = 20;

	cout << "a: " << a << endl;
	cout << "ref: " << ref << endl;

	cout << "&a: " << &a << endl;
	cout << "&ref: " << &ref << endl;

	func(a);
	return 0;
}
