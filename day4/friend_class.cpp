#include <iostream>
#include <string>

using namespace std;

class GodGay;

// 类做友元
class Building
{
	friend class GodGay;
public:
	Building();
public:
	string m_SittingRoom;
private:
	string m_BedRoom;
};

// 类外写成员函数

Building::Building()
{
	this->m_BedRoom = "卧室";
	this->m_SittingRoom = "客厅";
}

class GodGay
{
	GodGay();
public:
	void visit() // 访问Building中的属性
	{
		
	}
	Building* build;
};

// 类外写成员函数
GodGay::GodGay()
{
	// 实例化 Building 对象
	Building build = new Building;
}

void GodGay::visit()
{
	cout << "GodGay 访问 Building => " << build->m_SittingRoom << endl;
}

void test01()
{
	GodGay gg;
	gg.visit();
}

int main()
{
	test01();
	return 0;
}
