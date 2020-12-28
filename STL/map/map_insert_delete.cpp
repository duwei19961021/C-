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
	map<string,int>m;
	m.insert(pair<string,int>("zhangsan",20));

	m.insert(make_pair("lisi",18));

	m.insert(map<string,int>::value_type("wanger",30));

	m["mazi"]=40;

	PrintMap(m);

	m.erase(m.begin());

	PrintMap(m);

	m.erase("mazi");
	PrintMap(m);

	m.clear();
	PrintMap(m);
}

int main()
{
	test01();
	return 0;
}
