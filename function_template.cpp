#include <iostream>
using namespace std;

// 交换两个整型
void swapInt(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

// 交换两个浮点数
void swapFloat(float &a, float &b)
{
	float temp = a;
	a = b;
	b = temp;
}

// 函数模板
template<typename T> //声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T是一个通用数据类型
void Swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test01()
{
	int a = 10;
	int b = 20;
	// 两种方式使用函数模板
	// 1、自动类型退导
	Swap(a,b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "###################################" << endl;
	// 2、显式指定类型
	Swap<int>(a,b);	
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

int main()
{
	test01();
	return 0;
}
