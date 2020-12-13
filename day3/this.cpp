#include <iostream>
using namespace std;

/*
 * 1、解决名称冲突
 * 2、返回对象本身用*this
 * */

class Person
{
public:
	Person(int age)
	{
		this->age = age;
	}

	Person& PersonAddAge(Person &p)
	{
		// this是指向对象的指针，而 *obj 指向的就是对象本体 
		this->age += p.age;
		return *this;
	}
	int age;
};

void test01()
{
	Person p(24);
	cout << p.age << endl;
}

void test02()
{
	Person p1(10);

	Person p2(9);

	p2.PersonAddAge(p1).PersonAddAge(p1);

	cout << "p2的年龄为: " << p2.age  <<endl;
}

int main()
{
	test02();
	return 0;
}
