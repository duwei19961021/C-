#include <iostream>
#include <string>
using namespace std;

int out_function;
string global_str;

int test()
{
	int in_test;
	cout << "in_test = " << in_test << endl; // 随机值
}

int main()
{
#if 0
	cout << "bool: "<< sizeof(bool) << endl;
	bool b = 100;
	cout << "b = " << b << endl; 
	int a = 3.1415;
	cout << "a = " << a << endl;
	int d = 3.6999; // 3,只会保留小数点前的部分
	cout << "d = " << d << endl;
	unsigned char e = -1;
	cout << "e = " << e << endl;
	
	// 列表初始化
	int num1 = 1;
	int num2 = {2};
	int num3{3};
	int num4(4);	
	cout << num1 << " " << num2 << " " << num3 << " " << num4 << endl;

	// 默认初始化: 内置内省的遍历未被显示的初始化,它的值由位置决定,定义与任何函数体之外的变量被初始化为0。定义在函数体之内的变量不被初始化。
	int in_function;
	cout << "out_function = " << out_function << endl; // 0	
	cout << "in_function = " << in_function << endl; // 0
	test();
	int local_int;
	cout << "global_str = " << "\"" << global_str << "\"" << endl;
	cout << "local_int = " << local_int << endl;
#endif
	return 0;
}
