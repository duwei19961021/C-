#include <iostream>
using namespace std;
#include <vector>

void PrintVector(vector<int> v)
{
	cout << "[";
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << ",";
	}
	cout << "]";
	cout << endl;
}

void test01()
{
	vector<int> v;

	// 通过vector类的接口
	for(int i = 0; i < 10 ; i++)
	{
		v.push_back(i);
	}

	PrintVector(v);

	// 通过区间方式进行构造
	vector<int> v2(v.begin(),v.end());
	PrintVector(v2);

	// n个elem方式构造
	vector<int>v3(10,999);
	PrintVector(v3);

	// 拷贝构造
	vector<int>v4(v3);
	PrintVector(v4);
}

int main()
{
	test01();
	return 0;
}
