#include <iostream>
using namespace std;

class Person
{
public:
	// 利用成员函数重载 左移运算符
	//void operator<<(Person &p)
	//{
		
	//}
	int m_A;
	int m_B;
};

ostream &  operator<<(ostream &cout,Person &p)
{
	cout << "Person.m_A = " << p.m_A << " Person.m_B = " << p.m_B;
	return cout;
}

void test01()
{
	Person p;
	p.m_A = 10;
	p.m_B = 10;
	cout << p << endl;
	cout << "123" << endl;
}

int main()
{
	test01();
	return 0;
}
