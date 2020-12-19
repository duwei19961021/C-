#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void test01()
{
	ifstream ifs;

	ifs.open("data.txt",ios::in);

	if(!ifs.is_open()) // 判断文件是否打开成功
	{
		cout << "open file failed."  << endl;
		return ;
	}

	// 读数据
	/*
	// 1
	char buf[1024] = {0};
	while(ifs >> buf)
	{
		cout << buf << endl;
	}
	ifs.close();
	*/

	/*
	// 2
	char buf[1024] = {0};
	while(ifs.getline(buf,sizeof(buf)))
	{
		cout << buf << endl;	
	}
	ifs.close();
	*/
	
	// 3
	string buf;
	while(getline(ifs,buf))
	{
		cout << buf << endl;	
	}
	ifs.close();

	/*
	// 4
	char c;
	while(EOF != (c=ifs.get()))
	{
		cout << c << endl;	
	}
	ifs.close();
	*/
}

int main()
{
	test01();
	return 0;
}
