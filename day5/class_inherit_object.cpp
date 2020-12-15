#include <iostream>
using namespace std;

// 继承中的对象模型
class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son :public Base
{
public:
	int m_D;
};

void test01()
{
	cout << "sizeof(Son) = " << sizeof(Son) << endl; // 16,说明有四个成员: m_A、m_B、m_C、m_D,父类中的所有非静态成员都会被子类继承下去,父类中的私有成员属性是被编译器隐藏了,因此访问不到
}

int main()
{
	test01();
	return 0;
}
