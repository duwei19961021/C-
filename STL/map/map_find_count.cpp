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

	map<string,int>::iterator pos = m.find("jim");

	if(pos != m.end())
	{
		cout << pos->first << ":" << pos->second << endl;
	}

	cout << m.count("bob") << endl; // 1 存在，0不存在
}

int main()
{
	test01();
	return 0;
}
