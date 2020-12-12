#include <iostream>
using namespace std;

const double PI = 3.141592654;

class Circle
{
public:
		int m_r;
		double calculateCircle()
		{
			return 2 * PI * m_r;
		}
		double calculateArea()
		{
			return PI * m_r * m_r;
		}
};

int main()
{
	Circle c1;
	c1.m_r = 6;

	double circle = c1.calculateCircle();
	cout << circle << endl;

	double area = c1.calculateArea();
	cout << area << endl;
	return 0;
}
