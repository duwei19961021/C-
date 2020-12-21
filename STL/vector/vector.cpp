#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void Print(int val)
{
	cout << val  << endl;
}

void test01()
{
	vector<int> v; // 创建vector容器

	v.push_back(10); // 插入数据
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);

	/*
	// 第一种遍历方式
	vector<int>::iterator itBgein = v.begin(); // 起始迭代器，指向容器的第一个元素
	vector<int>::iterator itEnd = v.end(); // 结束迭代器，指向容器的最后一个元素的下一个位置

	while(itBgein != itEnd)
	{
		cout << *itBgein << endl;
		itBgein++;
	}
	*/

	/*
	// 第二种遍历方式
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << endl;	
	}
	*/

	// 第三种遍历方式
	for_each(v.begin(),v.end(),Print);
}

int main()
{
	test01();
	return 0;
}
