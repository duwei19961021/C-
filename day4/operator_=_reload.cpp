#include <iostream>
using namespace std;

class Person
{
public:
	Person(int age)
	{
		m_Age = new int(age);
	}

	~Person()
	{
		if(m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}

	Person& operator=(Person &p)
	{
		if (NULL != this->m_Age) // 先判断是否有属性在堆区，如果有先释放干净，再进行深拷贝
		{
			delete m_Age;
		}
		this->m_Age = new int(*p.m_Age);
		return *this; // p3 = p2 = p1 ,如果返回值是void,那么连等就会报错,在p2=p1函数调用执行完时还得返回p2本身才能继续赋值给p3
	}

	int *m_Age;
};

void test01()
{
	Person p1(18);
	Person p2(20);
	Person p3(30);
	p3 = p2 = p1;
	cout << "p1.m_Age = " << *p1.m_Age << endl;
	cout << "p2.m_Age = " << *p2.m_Age << endl;
	
	*p2.m_Age = 999;
	cout << "after:p1.m_Age = " << *p1.m_Age << endl;
    cout << "after:p2.m_Age = " << *p2.m_Age << endl;
}

int main()
{
	test01();
	return 0;
}
