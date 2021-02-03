#include <iostream>
using namespace std;

// 加号运算符重载
class Person
{
public:
	// 1、成员函数重载+号
	/*
	Person operator+(Person &p)
	{
		Person temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;	
		return temp;
	}
	*/
	int m_A;
	int m_B;
};

// 2、全局函数重载+号
Person operator+(Person &p1, Person &p2)
{
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}

void test01()
{
	Person p1;
	p1.m_A = 10;
	p1.m_B = 10;
	
	Person p2;
	p2.m_A = 20;
	p2.m_B = 20;
	Person p3 = p1 + p2; // 1、成员函数重载本质: Person p3 = p1.operator + (p2)	 2、全局函数重载本质: Person p3 = operator+(p1,p2)
	cout << "p3.m_A = " << p3.m_A << " p3.m_B = " << p3.m_B << endl; 
}

class Date
{
public:
	Date(int year, int month, int day)
	{
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}

	bool operator==(const Date& d2) // operator==(Date d1, Date d2)，此函数是类的内部函数，在调用传参时会给其传上一个默认参数：this指针，即相当于 operator==(Date& this, d1, d2)，由于this的存在，d1已经没有必要传参了，所以最终形式是：operator==(Date d2)， 相当于 d1.operator==(d2)
	{
		return this->_year == d2._year
			&& this->_month == d2._month
			&& this->_day == d2._day;
	}

	bool operator>(const Date& d2)
	{
		return this->_year > d2._year || (this->_year == d2._year && this->_month > d2._month) || (this->_year == d2._year && this->_month == d2._month && this->_day > d2._day);
	}
	
	void PrintDate()
	{
		cout << "time: " << _year << "-" << _month << "-" << _day << endl;
	}

//private:
	int _year;
	int _month;
	int _day;
};


void test02()
{
	Date d1(2020,2,1);
	Date d2(2020,2,3);
	if(d1 == d2)
		cout << "==" << endl;
	if(d1 > d2)
		cout << ">" << endl;
	else
		cout << "<=" << endl;
}

int main()
{
	test02();
	return 0;
}
