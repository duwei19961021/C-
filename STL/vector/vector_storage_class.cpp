#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}
	string m_Name;
	int m_Age;
};

void test01()
{
	vector<Person *> v;
	Person p1("张一",10);
	Person p2("张二",20);
	Person p3("张三",30);
	Person p4("张四",40);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);

	for(vector<Person *>::iterator it = v.begin();it != v.end();it++)
	{
		cout << (*it)->m_Name << ":" << (*it)->m_Age  <<endl;
	}
}

int main()
{
	test01();
	return 0;
}
