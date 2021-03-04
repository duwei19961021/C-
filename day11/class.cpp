#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "调用无参构造" << endl;
		this->name = "null";
		this->age = 0;
	}
	Person(string name, int age)
	{
		cout << "调用有参构造函数" << endl;
		this->name = name;
		this->age = age;
	}

	Person(const Person& p)
	{
		cout << "调用拷贝构造函数" << endl;
		this->name = p.name;
		this->age = p.age;
	}

	Person& operator=(const Person p)
	{
		cout << "调用重载符=" << endl;
		this->age = p.age;
		this->name = p.name;	
		return *this;
	}

	void Info()
	{
		cout << this->name << "," << this->age << endl;
	}
private:
	string name;
	int age;
	string family[3];
};

int main()
{
	Person p1("duwei",25);
	Person p2;
	p2 = p1;
}
