#include <iostream>
using namespace std;

/*
 * c++中，类的成员变量和成员函数分开存储
 * 只有非静态成员变量才属于类的对象上
 * */

class Person1
{
	
};

void test01()
{
	Person1 p;
    Person1 q;
    cout << "&p = " << &p << endl;
    cout << "&q = " << &q << endl; // 空对象拥有独立的内存
    cout << "test01() size of p = " << sizeof(p) << endl; // 空对象占用内存空间为1
}

//

class Person2
{
	int m_A; // 非静态变量属于类的对象上
	static int m_B; // 静态成员变量不属于类的对象上
	static void func(){} // 静态成员函数 不属于类对象上
	void func2(){} // 非静态成员函数 不属于类对象上
};

void test02()
{
	Person2 p;
	cout << "test02() size of p = " << sizeof(p) << endl; // 4,非静态变量属于类的对象上
}

int main()
{
	test02();
	return 0;
}
