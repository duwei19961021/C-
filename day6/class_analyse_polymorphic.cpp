#include <iostream>
using namespace std;

class Animal
{
public:
	virtual  void Speak()
	{
		cout << "Animal is Speaking." << endl;
	}
};

void test01()
{
	cout << sizeof(Animal) << endl; // 不加virtual,1,Speak()是非静态成员函数,不属于对象;添加virtual之后,8,Animal多了一个指针成员.
}


int main()
{
	test01();
	return 0;
}
