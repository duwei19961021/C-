#include <iostream>
using namespace std;
#include <queue>
#include <string>

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}
	string m_Name;
	int m_Age;	
};

void test01()
{
	queue<Person> q;
	Person p1("zhangsan",10);
	Person p2("lisi",11);
	Person p3("wanger",19);

	q.push(p1);
	q.push(p2);
	q.push(p3);

	while(!q.empty())
	{
		cout << q.front().m_Name << ":" << q.front().m_Age << endl;
		q.pop();
	}
}

void test02() // constructor
{
	queue<int> myQueue;
	for(size_t i = 0; i < 10; i++)
	{
		myQueue.push(i);
	}
	while(!myQueue.empty())
	{
		cout << myQueue.front() << " " << "size = " << myQueue.size() << endl; // 访问队头元素(出口)
		myQueue.pop(); // 删除队头元素	
	}
}

int main()
{
	test02();
	return 0;
}
