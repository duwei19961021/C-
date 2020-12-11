#include <iostream>

int main()
{
	using namespace std;
	int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
	for(int i =0;i<10;i++)
	{
		cout << arr1[i] << endl;
	}

	int arr2[10] = {1};
	for(int i =0;i<10;i++)
	{
		cout << arr2[i] << endl;
	}

	int arr3 = {99,100,101};
	return 0;
}
