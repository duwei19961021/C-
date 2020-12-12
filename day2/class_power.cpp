#include <iostream>
#include <string>
using namespace std;

/*
 * 访问权限
 * 1、公共权限 public		成员 类内可以访问 类外可以访问
 * 2、保护权限 protected	成员 类内可以访问 类外不可以访问 子类可以访问
 * 3、私有权限 private		成员 类内可以访问 类外不可以访问
 * */

class Person
{
public:
	string m_Name;

protected:
	string m_Car;

private:
	int m_Password;

public:
	void func()		
	{
		m_Name = "张三";
		m_Car = "bmw";
		m_Password = 123456;
	}
};

int main()
{
	Person p1;

	p1.m_Name = "李四";
	// p1.m_Car = "bench" 保护权限内容，在类外无法访问
	// p1.m_Password = 123 私有权限内容，在类外无法访问
	return 0;	
}
