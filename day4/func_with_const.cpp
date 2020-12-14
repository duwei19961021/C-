#include <iostream>
using namespace std;

class Person
{
public:
	// this 指针的本质是指针常量，指针的指向是不可修改的
	// Person* const this
	
	void showPerson() const // 在成员函数后面加const，修饰的是this的指向，让指针指向的值也不可修改
	{
		// this->m_A = 100; // error: assignment of member ‘Person::m_A’ in read-only object
		this->m_B = 99;
		cout << "showPerson()" << endl;
	}

	void func()
	{
		;
	};

	int m_A;
	mutable int m_B; // 特殊变量，即在常函数中也可以修改这个值
};

void test01()
{
	Person p;
	p.showPerson();
}

void test02()
{
	Person p1;
	const Person p = p1;
	// p.m_A = 99; error: assignment of member ‘Person::m_A’ in read-only object
	p.showPerson(); // 常对象只能调用常函数	
	p.m_B = 100;
	// p.func(); // error passing ‘const Person’ as ‘this’ argument of ‘void Person::func()’ discards qualifiers
}

int main()
{
	test02();
	return 0;
}
