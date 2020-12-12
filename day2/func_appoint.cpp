#include <iostream>
using namespace std;

void mySwap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void mySwapByPoint(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void mySwapByAppoint(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 10;
	int b = 99;

	mySwap(a,b); // 值传递，形参不会修饰实参
	cout << "mySwap a = " << a << endl;
	cout << "mySwap b = " << b << endl;

	mySwapByPoint(&a,&b); // 地址传递，形参会修饰实参
	cout << "mySwapByPoint a = " << a << endl;
    cout << "mySwapByPoint b = " << b << endl;
	
	mySwapByAppoint(a,b);
	cout << "mySwapByAppoint a = " << a << endl;
    cout << "mySwapByAppoint b = " << b << endl;
	return 0;
}
