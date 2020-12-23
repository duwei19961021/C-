#include <iostream>
using namespace std;
#include <deque>
#include <algorithm>

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
	deque<int>d;
	d.push_back(3);	
	d.push_back(2);	
	d.push_back(8);	
	d.push_back(9);	
	d.push_back(2);	
	d.push_back(7);	
	d.push_back(9);	
	d.push_back(4);	
	d.push_back(1);	

	PrintDeque(d);

	sort(d.begin(),d.end());
	PrintDeque(d);
}

int main()
{
	test01();
	return 0;
}
