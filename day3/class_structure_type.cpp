#include <iostream>
using namespace std;

/*
 * 构造函数的分类以及调用
 * 分类
 *     按照参数分类：无参(默认构造) 有参
 *     按照类型分类：普通构造 拷贝构造*/


class Person
{
public:
	Person()
	{
		cout << "普通、无参构造函数调用 Person()" << endl;
	}

	Person(int a)
	{
		cout << "有参构造函数调用 Person(int a)," << "a = " << a  << endl;
	}

	Person(const Person &p)
	{
		cout << "拷贝构造函数调用 Person(const Person &p)" << endl;
	}

	~Person()
	{
		static int i;
		cout << "析构函数调用 ~Person() " << i++ <<endl;
	}
};

int main()
{
	/*
	// 括号发
	Person p1; // 默认构造函数调用 不要加(), 编译器会认为是一个函数声明: Person p1();
	Person p2(10); //有参数构造函数调用
	Person p3(p2); // 拷贝构造函数调用
	*/
	
	/*
	// 显式法
	Person p1;
	Person p2 = Person(10); // 有参构造
	Person p3 = Person(p2); // 拷贝构造
	Person(99); // 匿名对象 特点：当指向结束后，系统会立即回收掉匿名对象
	// Person(p3); // 不要利用拷贝构造函数初始化匿名对象，编译器会认为 Person (p3) == Person p3;
	*/
	
	//隐式转换法
	Person p4 = 10; // 相当于 Person p4 = Person(10)
	Person p5 = p4;
	return 0;
}
