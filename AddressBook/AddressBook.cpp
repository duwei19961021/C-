#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#define MAX 1000

struct Person
{
	string m_Name;
	int m_Sex; // 1 男, 2 女
	int m_Age;
	string m_Phone;
	string m_Addr;
};

struct AddressBooks
{
	struct Person personArray[MAX]; 
	int m_Size;
};

void addPerson(AddressBooks *abs)
{
	if(abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加。" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		cout << "请输入性别：(1男，2女)" << endl;
		int sex = 0;
		cin >> sex;
		abs->personArray[abs->m_Size].m_Sex = sex;
		cout << "请输入年龄：" << endl;
		int age;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age= age;
		cout << "请输入手机号码：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone= phone;
		cout << "请输入地址：" << endl;
		string addr;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr= addr;
	}
	abs->m_Size++;
	cout << "添加成功" << endl;
	system("clear");
}
void ShowMenu(void)
{
	cout << "*************************" << endl;
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

int main()
{
	AddressBooks abs;
	abs.m_Size = 0;

	int select = 0;
	while(true){
		ShowMenu();
		cin >> select;
		switch(select)
		{
		case 1: // 添加联系人
				addPerson(&abs);
				break;
		case 2: // 显示联系人
				break;
		case 3: // 删除联系人
				break;
		case 4: // 查找联系人
				break;
		case 5: // 修改联系人
				break;
		case 6: // 清空联系人
				break;
		case 0: // 退出通讯录
				cout << "欢迎下次使用" << endl;
				return 0;
				break;
		default:
				cout << "选择错误" << endl;
				break;
		}
	}
	return 0;	
}
