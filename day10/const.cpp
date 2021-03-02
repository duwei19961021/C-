#include <iostream>
using namespace std;

class Date
{
public:
	Date()
	{
		_year = 2020;
		_month = 3;
		_day = 2;
	}
	void Print() const // 将this变为const类型,否则无法调用
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	const Date d;
	d.Print();
	return 0;
}
