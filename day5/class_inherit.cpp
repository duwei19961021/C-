#include <iostream>
using namespace std;

// 继承实现
class Person
{
public:
	void Say()
	{
		cout << "saying" << endl;
	}

	void Swim()
	{
		cout << "swimming" << endl;
	}

	void Run()
	{
		cout << "Running" << endl;
	}
};


// class 子类:继承方式
// 子类: 也称派生类
// 父类: 也称基类
class Man: public Person
{
public:
	void BeMan()
	{
		cout << "Be a Man"<< endl;
	}
};

class WoMen:public Person
{
public:
	void BeWoMem()
	{
		cout << "Be a WoMen" << endl;
	}
};

void test01()
{
	Man man;
	man.Say();
}

int main()
{
	test01();
	return 0;
}
