#include <iostream>
using namespace std;

class Father
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son1: public Father
{
public:
	void func()
	{
		this->m_A = 10; // 父类中的公共权限成员 在子类中依然是公共权限
		this->m_B = 20; // 父类中的保护权限成员 在子类中依然是保护权限
		// this->m_C = 30; //error: ‘int Father::m_C’ is private. 父类中的私有成员，子类访问不到
	}
};

void test01()
{
	Son1 s1;
	s1.m_A = 100; // 公共权限，能正常访问
	// s1.m_B = 200; error: ‘int Father::m_B’ is protected  保护权限，只能在类内访问
	// s1.m_C = 300; error: ‘int Father::m_C’ is private 私有权限，子类无法访问
}

class Son2: protected Father
{
public:
	void func()
	{
		this->m_A = 100; // 父类中的公共成员在子类中变为保护权限
		this->m_B = 100; // 父类中的保护成员在子类中变为保护权限
		// this->m_C = 100; error: ‘int Father::m_C’ is private ,父类的私有成员子类无法访问
	}
};

void test02()
{
	Son2 s2;
	/*
	s2.m_A = 200; error: ‘int Father::m_A’ is inaccessible, 在子类中变为了保护权限，在子类外无法访问。 
	s2.m_B = 200; error: ‘int Father::m_B’ is protected, 在子类中也是保护权限，在子类外无法访问。
	s2.m_C = 200; error: ‘int Father::m_C’ is private
	
	*/
}

class Son3: private Father
{
public:
	void func()
	{
		this->m_A = 100; // 父类中公共成员在子类中变为私有
		this->m_B = 100; // 父类中保护成员在子类中变为私有
		// this->m_C = 100; error: ‘int Father::m_C’ is private, 父类中私有成员子类无法访问
	}
};

void test03()
{
	Son3 s3;
	/*
	s3.m_A = 1000;
	s3.m_B = 1000;
	s3.m_C = 1000;
	私有成员在类外均无法访问
	*/
}

int main()
{
	test03();
	return 0;
}
