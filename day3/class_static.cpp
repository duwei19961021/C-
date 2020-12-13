#include <iostream>
using namespace std;

// 静态成员函数
// 所有对象共享同一个函数
// 静态成员函数只能访问静态成员变量

class Person
{
public:
	static void func()
	{
		m_A = 99; // 共享
		// m_B; 静态成员函数不能访问非静态成员变量
		cout << "static void func() 调用" << " m_A = "  << m_A  <<endl;		
	}
	static int m_A; // 静态成员变量，类内声明，类外初始化
	int m_B;
};

int Person::m_A = 0; // 类外初始化

void test01()
{
	// 1、通过对象访问
	Person p;
	p.func();	
	// 2、通过类名访问
	Person::func();	
}

int main()
{
	test01();
	return 0;
}
