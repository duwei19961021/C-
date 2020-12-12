#include <iostream>
using namespace std;

int *func()
{
	int *p = new int(10);
	return p;
}

int *func2()
{
	int *arr = new int[10];
	for (int i=0;i<10;i++)
	{
		arr[i] = i;
	}
	return arr;
}

int main()
{
	int *p = func();
	cout << *p << endl;
	cout << *p << endl;
	delete p;

	int *arr = func2();
	for (int i=0;i<10;i++)
    {
        cout << arr[i] << endl;
    }
	
	delete[] arr;
	return 0;
}
