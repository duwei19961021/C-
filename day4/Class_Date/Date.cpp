#include "Date.h"

void Date::PrintDate()
{
	cout << _year << "-" << _month  << "-" << _day << endl;
}

// 根据年月获取当月的天数
int Date::GetMonthDay(int year, int month)
{
	int monthArray[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
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

Date& Date::operator=(const Date& d)
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

Date& Date::operator+=(int day)
{
	this->_day += day; // 将日期先加上,然后根据天数计算月份该加多少,年该加多少
	while(this->_day > GetMonthDay(this->_year, this->_month)) // 当相加之后的天数大于本月天数时
	{
		this->_day -= GetMonthDay(this->_year, this->_month); // day要减去本月天数
		this->_month++; // month进一
		if(this->_month > 12) // month大于13 year要进一且month要减去一年即12个月
		{
			this->_year++;
			this->_month -= 12;
		}
	}
	return *this;
}

Date Date::operator+(int day)
{
	Date ret(*this); // 利用拷贝构造函数创建一个新的ret,然后对ret进行加等,不会影响原值。
	ret += day;
	return ret;
}

Date& Date::operator-=(int day)
{
	this->_day -= day;		
	while(this->_day < 1)
	{
		this->_day += GetMonthDay(this->_year, --this->_month); // 向上个月借天数
		if(this->_month == 1) // 这里特别注意：当month为1的时候要向12月借天数,虽然进入循环month会等于13,但是再次进入循环时,month会先自减即12月
		{
			this->_month += 12;
			this->_year--;
		}
	}
	return *this;
}

Date Date::operator-(int day)
{
	Date ret(*this);
	ret -= day;
	return ret;
}

// 前置++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator++(int)
{
	Date ret(*this);
	ret+=1;
	return ret;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date ret(*this);
	ret -= 1;
	return *this;
}

bool Date::operator>(const Date& d)
{
	return (this->_year > d._year || (this->_year == d._year && this->_month > d._month) || (this->_year == d._year && this->_month == d._month && this->_day > d._day));
}

bool Date::operator==(const Date& d)
{
	return this->_year == d._year && this->_month == d._month && this->_day == d._day;
}

bool Date::operator>=(const Date& d)
{
	return (*this > d || *this == d);
}

bool Date::operator<(const Date& d)
{
	return !(*this > d || *this == d);
}

bool Date::operator<=(const Date& d)
{
	return !(*this > d || *this == d) || (*this == d);
}

bool Date::operator!=(const Date& d)
{
	return (this->_year != d._year || this->_month != d._month || this->_day != d._day);
}

int Date::operator-(const Date& d)
{
	Date max = *this, min = d;
	int flag = 1;
	if(*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while(min != max)
	{
		++n;
		min += 1;
	}
	return n*flag;
}
