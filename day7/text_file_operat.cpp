#include <iostream>
#include <fstream>
using namespace std;

void test01()
{
	ofstream ofs;
	ofs.open("data.txt",ios::out);
	ofs << "姓名: 张三" << endl;
	ofs << "性别: 男" << endl;
	ofs << "年龄: 18" << endl;
	ofs << "籍贯: 湖南" << endl;
	ofs.close();
}

int main()
{
	test01();
	return 0;
}
