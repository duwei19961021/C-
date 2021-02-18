#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void Print(int val)
{
	cout << val  << endl;
}

void PrintVector(vector<int>& v)
{
	cout << "[ ";
	for(auto e:v)
	{
		cout << e << " ";
	}
	cout << "]" << endl;
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

void test02()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i*3/2);
	}
	vector<int> v2(v1);

	for(size_t i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl;

	for(vector<int>::iterator it = v2.begin(); it != v2.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	for(auto e:v2)
	{
		cout << e << " ";
	}
	cout << endl;

	for_each(v2.begin(),v2.end(),Print);
}

void test03()
{
	vector<int> v;
	v.insert(v.begin(),1);
	v.insert(v.begin(),2);
	v.insert(v.begin(),3);
	for(auto e:v)
		cout << e << " ";
}

void test04() // constructor
{
	vector<int> first;
	vector<int> second(4,999); // 初始化四个元素(999)		
	PrintVector(second);
	vector<int> third(second.begin(), second.end()); // 迭代器
	PrintVector(third);
	vector<int> fourth(third);
	PrintVector(fourth);
	int myInts[] = {1,3,5,7,3,2};
	vector<int> fifth(myInts,myInts + sizeof(myInts)/sizeof(int)); // 使用数组初始化vector
	PrintVector(fifth);
}

void test05() // operator
{
	vector<int> bar(5,9);
	cout << "bar: ";
	PrintVector(bar);
	vector<int> foo(3,1);
	cout << "foo: ";	
	PrintVector(foo);

	foo = bar;
	cout << "foo: ";
	PrintVector(foo);
}

void test06() // iterator
{
	int myInts[] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> v(myInts, myInts+sizeof(myInts)/sizeof(int));		

	for(vector<int>::iterator it = v.begin(); it != v.end(); it++) // 正向迭代器
	{
		cout << *it << " ";
	}

	cout << endl;

	for(vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++) // 逆向迭代器
	{
		cout << *it << " ";
	}
	
	cout << endl;
}

void test07() // capacity
{
	vector<int> v(3,1);
	cout << "size: " << v.size() << endl;
	cout << "max_size: " << v.max_size() << endl;	
	cout << "capacity: " << v.capacity() << endl;
	cout << "empty: " << v.empty() << endl;
	cout << endl;

	v.resize(5);
	cout << "size: " << v.size() << endl;
	cout << "max_size: " << v.max_size() << endl;	
	cout << "capacity: " << v.capacity() << endl;
	cout << "empty: " << v.empty() << endl;
	PrintVector(v); // [ 1 1 1 0 0 ],如果新开的size比原来的size大则新开的部分值为0(默认值)
	cout << endl;

	v.resize(2);
	cout << "size: " << v.size() << endl;
	cout << "max_size: " << v.max_size() << endl;	
	cout << "capacity: " << v.capacity() << endl;
	cout << "empty: " << v.empty() << endl;
	PrintVector(v); // [ 1 1 ],如果新开的size比原来的size小则多余部分会被移出,原值不发生改变 
	cout << endl;

	v.resize(8,100); // [ 1 1 100 100 100 100 100 100 ],原来的值不改变,新开辟的部分值为传参给定的值 
	cout << "size: " << v.size() << endl;
	cout << "max_size: " << v.max_size() << endl;	
	cout << "capacity: " << v.capacity() << endl;
	cout << "empty: " << v.empty() << endl;
	PrintVector(v);
}

void test08() // element access
{
	vector<int> v;
	for(int i = 0 ; i < 10 ; i++)
		v.push_back(i);
	PrintVector(v);

	cout << v[9] << endl; // operator[] 
	
	cout << v.at(3) << endl;

	cout << v.front() << endl; // Access first element

	cout << v.back() << endl; // Access last element 

	int *pFirst = v.data(); // 返回指向第一个元素的地址
	cout << *pFirst << endl;
	pFirst++;
	cout << *pFirst << endl;
}

void test09()
{
	vector<int> first;
	vector<int> second;
  	vector<int> 	third;

   	first.assign(10,100); // 初始化10个100
   	PrintVector(first);

   	auto it = first.begin() + 2;
   	second.assign(it,first.end()); // 迭代器区间
   	PrintVector(second);

	int myInts[] = {4,2,0,9};
	third.assign(myInts,myInts+sizeof(myInts)/sizeof(int));
	PrintVector(third);

	third.push_back(10);
	PrintVector(third);	

	third.pop_back();
	PrintVector(third);		
}

void test10()
{
	vector<int> v(3,100);
	PrintVector(v);
	vector<int>::iterator it = v.begin();
	cout << "insert(it,200): ";
	v.insert(it,200);
	PrintVector(v);

	v.clear();
	PrintVector(v);
}

int main()
{
	test10();
	return 0;
}
