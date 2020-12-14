#include <iostream>
#include <string>

using namespace std;

class Building
{
	friend void VeryGoodFriend(Building *build); // 在类里声明函数,并且添加关键字friend
public:
	Building()
	{
		this->m_SittingRoom = "客厅";
		this->m_BedRoom = "卧室";
	}

public:
	string m_SittingRoom;

private:
	string m_BedRoom;
};

// 全局函数
void GoodFriend(Building *build) // 访问公共函数
{
	cout << "access class Building public:m_SittingRoom = " << build->m_SittingRoom << endl;	
}

void VeryGoodFriend(Building *build) // 访问公共函数
{
	cout << "access class Building public:m_SittingRoom = " << build->m_BedRoom << endl;	
}

void test01()
{
	Building p;
	GoodFriend(&p);
}

void test02()
{
	Building p;
	VeryGoodFriend(&p);
}

int main()
{
	test02();
	return 0;
}
