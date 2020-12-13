#include <iostream>
#include <string>
using namespace std;

class Phone
{
	public:
		Phone(string pName)
		{
			cout << "Phone 的构造函数调用" << endl;
			m_PhoneName = pName;	
		}

		~Phone()
		{
			cout << "Phone 析构函数调用" << endl;
		}

		string m_PhoneName;
};

class Person
{
	public:
		// Phone m_Phone = pName 相当于隐式转换
		Person(string name, string pName):m_Name(name), m_Phone(pName) // Phone m_Phone = pName
		{
			cout << "Person 的构造函数调用" << endl;
		} 

		~Person()
		{
			cout << "Person 的析构函数调用" << endl;
		}
	string m_Name;
	Phone m_Phone;
};

int main()
{
	Person person("张三","iphone 8");
	cout << "name = "<< person.m_Name << ", phone = " << person.m_Phone.m_PhoneName << endl;
	return 0;
}

/*
 * 构造的顺序：先调用对象成员的构造，再调用本类的构造
 * 析构的顺序与构造相反
 * */
