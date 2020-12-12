#include <iostream>
using namespace std;

int add(int a, int b = 10, int c = 20)
{
	return a+b+c;
}

int main()
{
	cout << "ret = " << add(10) << endl;
	cout << "ret = " << add(1,2,3) << endl;
	return 0;
}
