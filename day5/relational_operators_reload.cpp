#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	bool operator==(Person &p)
	{
		if(this->m_Age == p.m_Age && this->m_Name == p.m_Name)
		{
			return true;
		}
		return false;
	}

	bool operator!=(Person &p)
	{
		if(this->m_Age != p.m_Age || this->m_Name != p.m_Name)
		{
			return true;
		}
		return false;
	}

	string m_Name;
	int m_Age;
};


void test01()
{
	Person p1("Tom", 18);
	Person p2("Tom", 18);
	if (p1 == p2)
	{
		cout << "p1 == p2" << endl;
	}
	else
	{
		cout << "p1 != p2" << endl;
	}
}

void test02()
{
	Person p1("Tom", 19);
	Person p2("Tom", 18);
	if (p1 != p2)
	{
		cout << "p1 != p2" << endl;
	}
	else
	{
		cout << "p1 == p2" << endl;
	}
}

int main()
{
	test02();
	return 0;
}
