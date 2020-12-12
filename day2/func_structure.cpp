#include <iostream>
using namespace std;

int i ;

class Person
{
public:
	Person() // 构造函数
	{
		++i;
		cout << "调用Person构造函数" <<endl;
	}
	~Person() // 析构函数
	{
		cout << "调用Person析构函数" <<endl;
	}
};

void test01()
{
	Person p;
}

int main()
{
	test01();
	test01();
	test01();
	test01();
	test01();
	Person p1;
	cout << "i = "  << i << endl;
	return 0;
}
