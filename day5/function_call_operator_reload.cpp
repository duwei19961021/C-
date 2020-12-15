#include <iostream>
#include <string>
using namespace std;

class MyPrint
{
public:
	void operator()(string test)
	{
		cout << test << endl;
	}
};

class MyAdd
{
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};

void test01()
{
	MyPrint myprint;
	myprint("hello world"); // 仿函数
}

void test02()
{
	MyAdd myadd;
	cout << myadd(1,3) << endl;
}

int main()
{
	test02();
	return 0;	
}
