#include <iostream>
using namespace std;

int& Add(int a, int b)
{
	int c = a + b;
	return c;
}

int main()
{
	/*
	int a = 10;
	int &b = a;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	
	b = 999;
	cout << "a = " << a << endl;
    cout << "b = " << b << endl;
	
	cout << "&a = " << &a << endl; // a b 地址相同
	cout << "&b = " << &b << endl;

	int n = 10;
	int &m = n; // 引用必须要初始化

	int c = 20;
	m = c; // 赋值操作，而不是更改引用
	cout << "n = " << n  << endl;
	cout << "m = " << m << endl;
	cout << "c = " << c << endl;

	// 指针和引用在初始化赋值时,权限可以缩小但是不可以放大
	const int n1 = 10;
	// int& m1 = n1;
	const int& m1 = n1;
	int p = 20;
	const int &q = p;

	double dd = 2.2222;
	int i = dd; // dd在这里经过复杂的运算转换成一个整数,产生一个临时变量,i等于这个临时变量,而临时变量具有常性。
	cout << "i = " << i << endl;
	// int& ri = dd; error: invalid initialization of reference of type ‘int&’ from expression of type ‘double’
	const int& ri = dd;	
	*/

	int& ret = Add(1,2); 
	Add(3,4);
	cout << "Add(1,2) = " << ret << endl;

	return 0;
}
