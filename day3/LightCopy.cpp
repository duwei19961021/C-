#include <iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person 的默认构造函数 Person()" << endl;
	}

	Person(int age, int height)
	{
		m_Age = age;
		m_Height = new int(height);
		cout << "Person 的默认有参构造函数 Person(int age)" << endl;
	}

	Person(Person &p)
	{
		
	}

	~Person()
	{
		cout << "Person 的析构函数 ~Person()" << endl;
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;
		}
	}

	int m_Age;
	int *m_Height;
};

int main()
{
	Person p1(18, 160);
	cout << "p1.m_Age = " << p1.m_Age << " p1.m_Height = " << p1.m_Height <<endl;

	Person p2(p1);
	cout << "p2.m_Age = " << p2.m_Age << " p2.m_Height = " << p2.m_Height <<endl;

	return 0;
}

/*
 * p1 实例化时执行有参构造函数，在堆区创建了一个变量heitht
 * 紧接着p2进行实例化，指向拷贝构造函数，p1中的m_Height 指针拷贝(浅拷贝)给了p2中的m_Height
 * 根据栈的先进后出原则，调用p2的析构函数释放对象，再调用p1的析构函数释放对象，发生了两次delete，m_Hegiht被释放两次报错
 * */
