#include <iostream>
using namespace std;

class Person
{
public:
	void PrintAge()
	{
	//	cout << this->_age;
	}

	void Show()
	{
		cout << "Show()" << endl;
	}
private:
	//int _age;
};

int main()
{
//	Person* p = nullptr;
//	p->Show();
//	p->PrintAge();
	Person p;
	cout << sizeof(Person) << endl; // 空对象也要分配1字节内存来代表它真实存在(即使没有任何成员)
	cout << sizeof(p) << endl;
	return 0;
}
