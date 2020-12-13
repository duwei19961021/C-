#include <iostream>
using namespace std;

// 拷贝构造函数调用时机
// 1、使用一个已经创建完毕的对象来初始化一个新对象
// 2、值传递的方式给函数参数传值
// 3、值方式返回局部对象

class Person
{
public:
	Person()
	{
		cout << "Person 默认构造函数调用" << endl;
	}

	Person(int age)
	{
		cout << "Person 有参构造函数调用" << endl;
		m_Age = age;
	}

	Person(const Person &p)
	{
		cout << "Person 拷贝构造函数调用" << endl;
		m_Age = p.m_Age;
	}

	~Person()
	{
		cout << "Person 析构函数调用" << endl;
	}

	int m_Age;
};

//1、使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
	Person p1(20);
	Person p2(p1);
	cout << "p2.m_Age = " <<p2.m_Age <<endl;
}

void doWork(Person p)
{
	;
}

// 2、值传递的方式给函数参数传值
void test02()
{
	Person p; // 调用默认
	doWork(p); // 调用拷贝
}

// 3、值方式返回局部对象
Person doWork2()
{
	Person p1;
	return p1;
}

void test03()
{
	Person p = doWork2();
}

int main()
{
	// test01(); // 调用有参、拷贝、析构
	// test02(); // 调用默认、拷贝、析构
	test03();
	return 0;
}
