#include <iostream>
using namespace std;

/*
 * 函数重载的满足条件
 * 1、同一个作用域下
 * 2、函数名称相同
 * 3、函数参数类型不同，或者个数不同，或者顺序不同
 * 4、返回值不能作为重载条件
 * */

void func()
{
	cout << "func 调用" << endl;
}

void func(int a)
{
	cout << "func(int a) 调用" << endl;
}

void func(double a)
{
	cout << "func(double a) 调用" << endl;
}


void func(int a, double b)
{
	cout << "func(int a, double b) 调用" << endl;
}

void func(double a, int b)
{
	cout << "func(double a, int b) 调用" << endl;
}

int main()
{
	func(10);
	func();
	func(3.14);
	func(1,3.14);
	func(3.14,1);
	return 0;
}
