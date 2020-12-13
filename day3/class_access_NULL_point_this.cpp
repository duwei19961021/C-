#include <iostream>
using namespace std;

/*
 * 空指针是可以调用成员函数的，但是需要注意有没有用到this指针
 * 如果用到this指针，需要加以判断保证代码健壮性
 * */

class Person
{
public:
	void showClassName()
	{
		cout << "this is Person class" << endl;
	}

	void showPersonAge()
	{
		if(NULL == this) // 加判断防止崩溃
		{
			return;
		}
		cout << "age = " << this->m_Age << endl;	
	}
	
	int m_Age;

};

void test01()
{
	Person *p = NULL;
	// p->showClassName();
	p->showPersonAge(); // 访问空指针报错	
}

int main()
{
	test01();
	return 0;
}
