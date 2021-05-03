#include <iostream>
using namespace std;

class Person
{
public:
	virtual ~Person()
	{
		cout << "~Person" << endl;
	}
};

class Student: public Person
{
public:
	~Student()
	{
		cout << "~Student" << endl;
	}
};

int main()
{
	/*
	Person p1;

	Student s1;

output:
	~Student // s1后入栈后销毁，销毁时先调用自己的析构函数
	~Person // 因为Student继承了Person类，所以派生类在销毁时还需要调用父类的析构函数去销毁属于父类的那部分数据
	~Person // 最后调用父类的析构函数
	*/

	/*
	1、如果父子类的析构函数不构成多态

	Person *p1 = new Person;

	Person *p2 = new Student;

	delete p1; // p1.destructor()

	delete p2; // p2.destructor() // 不构成多态就会按照类型去调用

output:
	~Person // 父类调用析构函数
	~Person	// 由于编译器的处理，析构函数名会被处理成destructor，delete父类指针，会调用父类的析构函数(屏蔽了子类函数的析构函数，它们是同名成员destructor)，此时Student类对象中属于父类的数据被析构函数销毁，但是子类的析构函数没有被调用，造成内存泄露。
	*/

	/*
	2、如果父子类的析构函数构成多态
	Person *p1 = new Person;

	Person *p2 = new Student;

	delete p1;

	delete p2;

output:
	~Person // 父类析构
	~Student // delete时，调用对象对应的析构函数
	~Person
	*/

	return 0;
}
