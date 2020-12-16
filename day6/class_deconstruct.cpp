#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
	Animal()
	{
		cout << "Animal 的构造函数调用" << endl; 
	}

	// 利用虚析构可以解决 父类指针释放子类对象时不干净问题
	/*
	virtual ~Animal() // 解决方法1：虚析构
	{
		cout << "Animal 的虚析构函数调用" << endl;
	}
	*/

	virtual ~Animal() = 0; // 解决方法2：纯虚析构,需要声明&实现;有了纯虚析构之后,这个类也属于抽象类,无法实例化对象

	virtual void speak() = 0;	
};

Animal::~Animal()
{
	cout << "Animal 的纯虚析构函数调用" << endl;
}

class Cat :public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat 的构造函数调用"  << endl;
		this->m_Name = new string(name);
	}

	virtual ~Cat()
	{
		if(this->m_Name != NULL)
		{
			cout << "Cat 的析构函数调用" << endl;
			delete this->m_Name;
			this->m_Name = NULL;
		}
	}

	void speak()
	{
		cout << *this->m_Name <<" cat is speaking" << endl;
	}
	string *m_Name;
};

void test()
{
	Animal *animal = new Cat("tom");
	animal->speak();
	// 父类指针在析构时，不会调用子类中析构函数，导致子类如果有堆区属性，会出现内存泄露
	delete animal;
}

int main()
{
	test();
	return 0;
}

/*
 * 1. 虚析构或纯虚析构就是用来解决通过父类指针释放子类对象
 * 2. 如果子类中没有堆区数据，可以不写虚析构或者纯虚析构
 * 3. 拥有纯虚析构函数的类也属于抽象类
 * */
