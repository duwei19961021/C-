#include <iostream>
#include <string>
using namespace std;

void find_char(string &str) // 2、而在函数中形参的类型并不是常量引用，和传入的实参类型不同(string &str , const string &str)不能进行初始化操作
{
	cout << str << endl;
}

int main()
{
	find_char("duwei"); // 1、传入的是一个常量
	// error: invalid initialization of non-const reference of type ‘std::string& {aka std::basic_string<char>&}’ from an rvalue of type ‘const char*’
	return 0;
}
