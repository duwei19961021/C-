#include "Date.h"

int main()
{
	Date d(2020,3,24);
	Date d2(d);
	d2.PrintDate();
	d2 -= 90;
	d2.PrintDate();
	return 0;
}
