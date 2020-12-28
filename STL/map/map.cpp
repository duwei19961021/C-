#include <iostream>
using namespace std;
#include <map>
#include <string>

void PrintMap(const map<string,int>&m)
{
	cout << "{";
	for(map<string,int>::const_iterator it = m.begin();it!=m.end();it++)
	{
		cout << "\""  <<it->first << "\":" << it->second << ",";
	}
	cout << "}"<<endl;
}

void test01()
{
	map<string, int> m;
	m.insert(pair<string,int>("jim",10));
	m.insert(pair<string,int>("tim",19));
	m.insert(pair<string,int>("tom",30));
	m.insert(pair<string,int>("bob",18));
	PrintMap(m);

	// 拷贝构造
	map<string,int>m2(m);
	PrintMap(m2);

	// 赋值
	map<string,int>m3;
	m3 = m2;
	PrintMap(m3);
}

int main()
{
	test01();
	return 0;
}
