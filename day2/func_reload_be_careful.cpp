#include <iostream>
using namespace std;

void func(int &a)
{
	cout << "func(int &a)调用" << endl;
}

void func(const int &a)
{
    cout << "func(const int &a)调用" << endl;
}

void func2(int a,int b=10)
{
	cout << "func2(int a,int b=10)" << endl;
}

void func2(int a)
{
	cout << "func2(int a)" << endl;
}

int main()
{
	int a = 10;
	func(a);

	const int b = 10;
	func(b);

	func2(10); // 当函数重载遇见默认值，出现二义性
	return 0;
}

/*
 * 参数加const 和 不加const 可以作为函数重载条件
 * */
