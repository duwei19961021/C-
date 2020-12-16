#include_next <iostream>
using namespace std;

class Base
{
public:
	// 只要有一个纯虚函数，这个类称为抽象类
	// 1、无法实例化对象
	// 2、抽象类的子类 必须要重写父类中的纯虚函数，否则也属于抽象类
	virtual void func() = 0; // 纯虚函数
};


void test01()
{
	// 抽象类无法实例化对象
	// Base b;  error: cannot declare variable ‘b’ to be of abstract type ‘Base’ 
	// new Base;  error: cannot allocate an object of abstract type ‘Base’
}

int main()
{
	test01();
	return 0;
}
