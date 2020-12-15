#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		this->m_A = 100;
	}

	void func()
	{
		cout << "I'm Base" << endl;
	}

	static void Go()
	{
		cout << "Base static Go()" << endl;
	}

	int m_A;
	static int m_B;
};

int Base::m_B = 100;

class Son: public Base
{
public:
	Son()
	{
		this->m_A = 200;
	}

	void func()
	{
		cout << "I'm Son" << endl;
	}

	static void Go()
	{
		cout << "Son static Go()" << endl;
	}

	int m_A;
	static int m_B;
};

int Son::m_B = 900;

void test01()
{
	Son s;
	cout << "Son s.m_A = " << s.m_A << endl; // 200
	cout << "Base s.m_A = " << s.Base::m_A << endl; // 100

	s.func(); // I'm Son
	s.Base::func(); // I'm Base

	// 通过对象访问
	cout << "By Object Base static int m_B = " << s.Base::m_B <<endl; // 父类静态成员的访问
	cout << "By Object Son static int m_B = "<< s.m_B <<endl; // 子类静态成员的访问

	// 通过类名
	cout << "By className Base static int m_B = "<< Son::m_B <<endl;
	cout << "By className Son static int m_B = "<< Base::m_B <<endl;
	
	// 第一个 :: 代表通过类名访问 第二个 :: 代表访问父类作用域下
	cout << "Base下m_A = " << Son::Base::m_B << endl;
}

void test02()
{
	Son s;
	// 通过作用域访问
	s.Go();
	s.Base::Go();

	// 通过类名
	Son::Go();
	Base::Go();	
}
int main()
{
	test02();
	return 0;
}
