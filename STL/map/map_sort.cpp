#include <iostream>
using namespace std;
#include <string>
#include <map>

void PrintMap(const map<string,int>&m)
{
	cout << "{";
	for(map<string,int>::const_iterator it = m.begin();it!=m.end();it++)
	{
		cout << "\""  <<it->first << "\":" << it->second << ",";
	}
	cout << "}"<<endl;
}

class MyCompare
{
public:
	bool operator()(string v1, string v2)
	{
		return v1 > v2;
	}
};

void test01()
{
	map<string, int, MyCompare> m;
	m.insert(pair<string,int>("jim",10));
	m.insert(pair<string,int>("tim",19));
	m.insert(pair<string,int>("tom",30));
	m.insert(pair<string,int>("bob",9));
	m.insert(pair<string,int>("zhangsan",21));
	m.insert(pair<string,int>("lisi",11));
	m.insert(pair<string,int>("duwei",99));
	m.insert(pair<string,int>("mazi",32));
	PrintMap(m);
}

int main()
{
	test01();
	return 0;
}
