#include "Date.h"

int main()
{
	Date d(2020,3,24);
	Date d2(d);
	d2.PrintDate();
	d2 -= 90;
	d2.PrintDate();
	for(int i = 0; i < 10; i++)
		++d2;
	d2.PrintDate();
	if(d > d2)
		cout << ">" << endl;
	return 0;
}
