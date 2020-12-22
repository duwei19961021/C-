#include <iostream>
using namespace std;
#include <vector>

// vector容器 预留空间
void test01()
{
	vector<int>v;
	int num = 0;
	int *p = NULL;
	
	v.reserve(100000); // 预留空间,减少因扩容产生的内存拷贝次数

	for(int i=0;i<10000;i++)
	{
		v.push_back(i);
		if(p!=&v[0])
		{
			p = &v[0];
			num++;
		}
	}
	cout << "num = " << num << endl; // 不使用reserve: num = 15; 使用reserve: num = 1
}

int main()
{
	test01();
	return 0;
}
