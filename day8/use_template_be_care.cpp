#include <iostream>
using namespace std;

template<class T>

void Swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

// 1、自动类型退导，必须退导出一致的数据类型T才可以使用
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';

	Swap(a,b); // 正确

	// Swap(a,c); error: no matching function for call to ‘Swap(int&, char&)’,推导出的类型不一致的T类型
	
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

template<class T>
void func()
{
	cout << "func() 调用" << endl;
}

void test02()
{
	// 2、模板必须要确定出T的数据类型，才可以使用
	func<int>();
}

int main()
{
	test01();
	test02();
	return 0;
}
