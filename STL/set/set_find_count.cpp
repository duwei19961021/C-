#include <iostream>
using namespace std;
#include <set>

void test01()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(50);
	s1.insert(30);
	s1.insert(70);
	s1.insert(40);

	set<int>::iterator pos = s1.find(80);
	if(pos != s1.end())
	{
		cout << "找到元素：" << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

void test02()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(50);
	s1.insert(30);
	s1.insert(70);
	s1.insert(40);

	int num1 = s1.count(30);
	cout << "num1 = " << num1 << endl;

	int num2 = s1.count(300);
	cout << "num2 = " << num2 << endl;
	// 对于set，统计结果要么是0要么是1

}	

int main()
{
	test01();
	test02();
	return 0;
}
