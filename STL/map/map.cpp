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

void test02()
{
	map<char,int> first;
	map<char,int> second;
	first['a'] = 1;
	first['b'] = 2;
	first['c'] = 3;
	second = first;
	first = map<char,int>();
	cout << "first.size: " << first.size() << endl;
	cout << "second.size: " << second.size() << endl;
	cout << "second.max_size: " << second.max_size() << endl;

	cout << "'a': " << second.at('a') << endl;
	cout << "'b': " << second['b'] << endl;
}

void test03() // Modifiers
{
	map<string,int> Person;
	Person.insert(pair<string,int>("duwei",24));
	Person.insert(pair<string,int>("zhangsan",18));
	map<string,int>::iterator it = Person.end();
	Person.insert(pair<string,int>("lisi",40)); // 不强制新元素插入到map容器中的指定位置,具体顺序取决于它们的键 
	PrintMap(Person);
	Person.erase(Person.begin()); // 删除元素
	PrintMap(Person);
	Person.clear(); // 清空元素
	PrintMap(Person);
}

void test04()
{
	map<string,int> Student;
	Student["duwei"] = 24;
	Student["zhangsan"] = 18;
	Student["lisi"] = 40;
	PrintMap(Student);
	map<string,int>::iterator it = Student.find("duwei"); // 返回当前元素的迭代器,不存在则指向end
	cout << it->first << ":" << it->second << endl; // it是pair类型指针

	size_t count = Student.count("duwei"); // 返回key在map容器中出现的次数(其实最多也就一次,不是0就是1)
	if(count > 0)
		cout << "key \"duwei\" exists" << endl;
	else
		cout << "key \"duwei\" not exists" << endl;

	size_t count2 = Student.count("duwei1");
	if(count2 > 0)
		cout << "key \"duwei1\" exists" << endl;
	else
		cout << "key \"duwei1\" not exists" << endl;
}

int main()
{
	test04();
	return 0;
}
