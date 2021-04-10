#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	Person() = default;
	
	Person(int age, string name): _age(age), _name(name) {}

	int getAge() const
	{
		return _age;
	}

	void setAge(int age) const
	{
		_age = age;
	}
private:
	mutable int _age;
	string _name;	
};

int main()
{
	const Person p(24, "duwei");
	cout << p.getAge() << endl;
	p.setAge(12);
	cout << p.getAge() << endl;
}
