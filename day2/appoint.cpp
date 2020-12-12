#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	int &b = a;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	
	b = 999;
	cout << "a = " << a << endl;
    cout << "b = " << b << endl;
	
	cout << "&a = " << &a << endl;
	cout << "&b = " << &b << endl;

	int n = 10;
	int &m = n; // 引用必须要初始化

	int c = 20;
	m = c; // 赋值操作，而不是更改引用
	cout << "n = " << n  << endl;
	cout << "m = " << m << endl;
	cout << "c = " << c << endl;

	return 0;
}
