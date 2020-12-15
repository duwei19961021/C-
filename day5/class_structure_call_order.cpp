#include <iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person的构造函数 Person()调用"  << endl;
	}

	~Person()
	{
		cout << "Person的析构函数 ~Person()调用"  << endl;
	}
	int m_A = 999;
};

class Son: public Person
{
public:
	Son()
	{
		cout << "Son构造函数 Son()调用" << endl;
	}

	~Son()
	{
		cout << "Son析构函数 ~Son() 调用" << endl;
	}
};

void test01()
{
	Son s;
	/* 继承中的构造和析构顺序如下:
	 * 构造父类 => 构造子类 => 析构子类 => 析构父类
	 * */
}

int main()
{
	test01();
	return 0;
}
