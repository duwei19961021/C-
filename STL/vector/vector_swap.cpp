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

void test02()
{
	vector<int>v;
	for(int i=0;i<10000;i++)
	{
		v.push_back(i);
	}

	cout << "v的容量为: " << v.capacity() << endl; // 16384
	cout << "v的大小为: " << v.size() << endl; // 10000

	v.resize(3);
	cout << "v的容量为: " << v.capacity() << endl; // 16384
    cout << "v的大小为: " << v.size() << endl; // 3

	// 利用swap收缩内存
	vector<int>(v).swap(v); // vector<int>()是一个匿名容器,利用v(3个元素)进行初始化,然后与v进行交换,匿名的容器由系统回收
	cout << "v的容量为: " << v.capacity() << endl; // 3
    cout << "v的大小为: " << v.size() << endl; // 3
}

int main()
{
	test02();
	return 0;
}
