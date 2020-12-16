#include <iostream>
using namespace std;

/*
 * 多态:
 * 	静态多态:
 * 		函数重载
 * 		运算符重载
 * 	动态多态:
 * 		派生类和函数实现运行时多态
 * 
 */

class Animal
{
public:
	// 虚函数
	virtual void Speak()
	{
		cout << "Animal is Speaking" << endl;
	}
};

class Cat: public Animal
{
public:
	void Speak()
	{
		cout << "Cat is Speaking" << endl;
	}
};

// 地址早绑定 在编译阶段就确定了函数的地址                                   
// 如果想让Cat类去执行Speak(),那么这个函数就不能早绑定,需要在运行时绑定,地址晚绑定 (line 17,在Speak前添加关键字virtual)
void doSpeak(Animal &ani)
{
	ani.Speak();
}

void test01()
{
	Cat ani;
	doSpeak(ani);
}

int main()
{
	test01();
	return 0;
}
