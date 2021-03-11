#include <iostream>
using namespace std;

template<class T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
#if 0
	int a = 10, b = 20;
	double d = 1.1, e = 2.2;
	Swap(a,b);
	cout << "a = " << a << ", b = " << b << endl;
	Swap(d,e);
	cout << "d = " << d << ", e = " << e << endl;
#endif
	int a = 10, b = 20;
	double d = 1.1, e = 2.2;
	Swap<int>(a,b); // 显式实例化
	cout << "a = " << a << ", b = " << b << endl;
	Swap<double>(d,e);
	cout << "d = " << d << ", e = " << e << endl;
}
