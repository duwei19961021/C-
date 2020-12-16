#include <iostream>
using namespace std;

class Animal
{
public:
	int m_Age;
};

// 利用虚继承 解决棱形继承的问题
// 在继承之前加上关键字 virtual 变为虚继承
// Animal 类称为 虚基类
class Sheep :virtual public Animal{};

class Tuo :virtual public Animal{};

class SheepTuo: public Sheep, public Tuo{};

void test01()
{
	SheepTuo st;
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 28;

	// 当棱形继承，两个父类拥有相同数据，需要加以作用域区分
	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
	cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;

	// m_Age 这份数据我们知道 只有一份就可以了，棱形继承导致数据有两份，资源浪费
	
}

int main()
{
	test01();
	return 0;
}
