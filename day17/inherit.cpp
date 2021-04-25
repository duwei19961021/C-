#include <string>
#include <iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		_name = "duwei";
		_sex = "man";
		_age = 24;
	}

	~Person()
	{
		cout << "~Person() in Person" << endl;	
	}
public:
	string _name;
	string _sex;
	int _age;
};

class Student: public Person
{
public:
	Student(int No)
	: Person()
	, _No(No)
	{}

	Student(const Student &s)
	: Person(s)
	, _No(s._No)
	{}

	Student& operator=(const Student &s)
	{
		if(this != &s)
		{
			Person::operator=(s);
			_No = s._No;
		}
		return *this;
	}	

	/*
	 * 1、父类的析构函数和子类的析构函数构成隐藏 -> 由于多态的需要，所有类的析构函数的名字会被统一处理成destructor
	 * 2、析构不需要显示调用，会自动调用。如果派生类中显示调用父类的析构函数，不符合规则。(先入栈的后析构)
	 */
	~Student()
	{
		Person::~Person();
	}

public:
	int _No;
};

int main()
{
	Student s(20);

	Student s2(s);

	Student s3 = s2;

	return 0;
}

/*
class Person
{
public:
	void speak()
	{
		cout << "speak(),I am Person" << endl;
	}

	void sleep()
	{
		cout << "sleep(),I am Person" << endl;
	}

public:
	int age;
	string name;

private:
	float weight;
};

class boy: public Person
{
public:
	void speak()
	{
		cout << "speak(),I am boy" << endl;
	}

	void sleep()
	{
		cout << "sleep(), I am boy" << endl;
	}
};

class girl: public Person
{
public:
	void speak()
	{
		cout << "speak(),I am girl" << endl;
	}

	void sleep()
	{
		cout << "sleep(), I am girl" << endl;
	}

};

int main()
{
	cout << "sizeof(Person) = " << sizeof(Person) << endl;

	cout << "sizeof(boy) = " << sizeof(boy) << endl;

	cout << "sizeof(girl) = " << sizeof(girl) << endl;


	return 0;
}
*/


/*
class Person
{
public:
	string _name = "duwei";
	int _age = 24;
	string _city = "hz";
};

class Student:public Person
{
public:
	string _name = "zhangsan";
	int _age = 25;
	string _home = "hunan";
};

int main()
{
	Student stu;

	cout << stu._name << endl;

	cout << stu.Person::_name << endl;

	return 0;
}
*/

