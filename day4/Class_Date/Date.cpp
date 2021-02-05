#include "Date.h"

void Date::PrintDate()
{
	cout << _year << "-" << _month  << "-" << _day << endl;
}

// 根据年月获取当月的天数
int Date::GetMonthDay(int year, int month)
{
	int monthArray[13] = {0, 31, 28, 31, 30, 30, 31, 30, 31, 30, 31, 30, 31};
	if(((year%4 == 0 && year%100 != 0) || year%400 == 0) && month == 2)
	{
		monthArray[2] = 29;
	}
	int days = monthArray[month];
	return days;
}

// 日期类构造函数
Date::Date(int year, int month, int day) // 缺省参数只能在声明时写,实现不能写
{
	if(year < 0)
	{
		cout << "日期不合法" << endl;
		return;
	}
	else if(month > 12 || month < 0)
	{
		cout << "日期不合法" << endl;
		return;
	}
	else if(day > GetMonthDay(year, month))
	{
		cout << "日期不合法" << endl;
		return;
	}
	_year = year;
	_month = month;
	_day = day;
}

// 拷贝构造
Date::Date(const Date& d)
{
	this->_year = d._year;
	this->_month = d._month;
	this->_day = d._day;
}

Date& Date:: operator=(const Date& d)
{
	this->_year = d._year;
	this->_month = d._month;
	this->_day = d._day;
	return *this;
}

// 日期类析构函数
Date::~Date()
{

}
