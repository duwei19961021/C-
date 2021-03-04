#include <iostream>
using namespace std;

class Person
{
public:
	friend ostream& operator<<(ostream& out,Person& p); // 友元函数: 有权访问类的所有私有（private）成员和保护（protected）成员
	// int i = 0;
	Person(int year, int month, int day, int age)
		:_year(year),
		 _month(month),
		 _day(day),
		 _age(age) // const 类型在定义时就要赋值,这里使用初始化列表相当于在定义时赋值(const int _age = age),引用类型(引用类型必须在定义时赋值)的成员也可以使用这种方式 
	{}
	
	/*	
	void operator<<(ostream& cout)
	{
		cout << this->_year << "-" << this->_month << "-" << this->_day << " age:" << this->_age << endl;	
	}
	*/

	/*
	// int i;i=0;
	Person(int year, int month, int day, int age)
	{
		this->_year = year;
		this->_month = month;
		this->_day = day;
		this->_age = age; // 如果不适用初始化列表,使用普通的构造函数赋值,这里则会报错: 向const类型赋值
	}
	*/

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << " age:" << _age << endl;
	}

private:
	int _year;
	int _month;
	int _day;
	const int _age;
};

ostream& operator<<(ostream& out,Person& p)
{
	cout << p._year << "-" << p._month << "-" << p._day << " age:" << p._age << endl;	
	return out;
}

int main()
{
	Person p(2020,3,4,25);
//	p << cout; // p.operator<<(cout);
	cout << p << p << p;
	return 0;
}
