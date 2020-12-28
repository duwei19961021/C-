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
	
	if(m.empty())
	{
		cout << "map is empty" << endl;
	}
	else
	{
		cout << "map is not empty" << endl;
		PrintMap(m);
	}

	map<string, int> n;
	n.insert(pair<string,int>("zhangsan",10));
	n.insert(pair<string,int>("lisi",19));
	n.insert(pair<string,int>("wanger",30));
	n.insert(pair<string,int>("mazi",18));

	cout << "before swap:" << endl;
	PrintMap(m);

	m.swap(n);

	cout << "after swap:" << endl;
	PrintMap(m);

	cout << "size:" << m.size() << endl;
}

int main()
{
	test01();
	return 0;
}
