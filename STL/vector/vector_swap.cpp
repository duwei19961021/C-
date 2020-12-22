#include <iostream>
using namespace std;
#include <vector>

void PrintVector(vector<int> v)
{
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	vector<int>v1;
	for (int i=0;i<10;i++)
	{
		v1.push_back(i);
	}

	PrintVector(v1);

	vector<int>v2;
	for(int i=0;i<10;i++)
	{
		v2.push_back(i+100);
	}
	PrintVector(v2);

	v1.swap(v2);
	PrintVector(v1);
	PrintVector(v2);
}

int main()
{
	test01();
	return 0;
}
