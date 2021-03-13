#include <iostream>
using namespace std;

/*
 * operator new / operator delete 是c++申请/释放内存的标准库函数，不是new/delete的重载，用法和malloc/free相同
 * new 等价于 operator new + 构造函数
 * operator new 等价于 malloc + malloc失败抛异常
 * operator delete 等价于 free
 * delete 等价于 先析构再operator delete
 */
class Person
{
public:
	Person(int i)
	{
		_id = i;
		cout << "Person()" << endl;
	}

	~Person()
	{
		cout << _id << endl;
		cout << "~Person" << endl;
	}
	int _id;
};

int main()
{
//	Person* p = (Person*)operator new(sizeof(Person)); // 不会调用构造和析构函数
//	cout << p->_id << endl;
//	operator delete(p);
	
//	Person* pArr = new Person[3]; // Person没有默认构造函数,因此这里new会失败
	Person* pArr = (Person*)operator new(sizeof(Person)*3); // 相当于使用malloc,对象里的是随机值

	new(pArr)Person(3); // 显示调用构造函数去初始化一块已有空间 -- 定位 new(replacenew)
	new(pArr+1)Person(30);
	new(pArr+2)Person(300);
	for(int i = 0; i < 3; i++)
	{
		cout << pArr[i]._id << endl;
	}

	cout << "----------------------" << endl;
	for(int i = 0; i < 3; i++)
	{
		(pArr+i)->~Person();
	}
	operator delete(pArr);
	return 0;
}
