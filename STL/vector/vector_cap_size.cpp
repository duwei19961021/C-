#include <iostream>
using namespace std;
#include <vector>

void PrintVector(vector<int>v)
{
	cout << "[";
	for(vector<int>::iterator it = v.begin();it!=v.end();it++)
	{
		cout << *it;
		cout << ",";
	}
	cout << "]";
	cout << endl;
}

void test()
{
	vector<int>v1;
	for(int i=0;i<10;i++)
	{
		v1.push_back(i);
	}

	cout << "v1.empty() = " << v1.empty() << endl; // 判断容器是否为空
	cout << "v1.capacity() = " << v1.capacity() << endl; // 判断容器的容量
	cout << "v1.size() = " << v1.size() << endl; // 返回容器中元素的个数

	// 重新制定长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出长度的元素被删除
	v1.resize(5);
	PrintVector(v1);

	v1.resize(20,999); // 容器变长，则以 999 填充新位置，变短则删除末尾超出容器长度的元素。
	PrintVector(v1);
}

int main()
{
	test();
	return 0;
}
