#include <iostream>
using namespace std;
#include <deque>

void PrintDeque(const deque<int>d)
{
	cout << "[";
	for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)
	{
		cout << *it << " ";
	}
	cout << "]" << endl;
}

void test01()
{
	deque<int>d1;
	d1.push_back(9); // 尾插
	d1.push_back(99);
	d1.push_back(999);
	d1.push_front(8); // 头插
	d1.push_front(88);
	d1.push_front(888);
	PrintDeque(d1);

	d1.pop_back(); // 尾删
	d1.pop_front(); // 头删
	PrintDeque(d1);

	d1.insert(d1.begin(),1000);
	PrintDeque(d1);
	d1.insert(d1.begin(),3,10000);
	PrintDeque(d1);

	// 按照区间进行插入
	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);
	d2.push_back(4);
	d2.push_back(5);
	d2.push_back(6);

	d1.insert(d1.begin(),d2.begin(),d2.end()); // 将d2从d1的起始位置插入
	PrintDeque(d1);
}

void test02()
{
	deque<int>d1;
    d1.push_back(9); // 尾插
    d1.push_back(99);
    d1.push_back(999);
    d1.push_front(8); // 头插
    d1.push_front(88);
    d1.push_front(888);
	PrintDeque(d1);

	deque<int>::iterator it = d1.begin();
	it++;
	d1.erase(it);
	PrintDeque(d1);

	d1.erase(d1.begin(),d1.end());
	PrintDeque(d1);

	d1.push_back(9); // 尾插
    d1.push_back(99);
    d1.push_back(999);
    d1.push_front(8); // 头插
    d1.push_front(88);
    d1.push_front(888);
	d1.clear();
	PrintDeque(d1);
}

int main()
{
	// test01();
	test02();
	return 0;	
}
