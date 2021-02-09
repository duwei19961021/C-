#include <iostream>
using namespace std;
#include <string>

/*
 * 模板原理：编译器根据调用函数模板和类模板的类型，实例化出对应的函数和类。
 * string的本质是一个类，内部维护着一个char*
 */

void test01()
{
	string s1;
	const char * str = "hello world";
	string s2(str);
	cout << "s2 = "<< s2 << endl;

	string s4(10,'a');
	s4+="bb";
	cout << s4 << endl;
}

void test02()
{
	string s1;
	string s2("duwei");
	string s3(s2);
	string s4(10,'a'); // 初始化字符串10个'a'
	string s5 = "hello";
	string s6 = s2;
	cout << s1 << endl << s2 << endl << s3 << endl << s4 << endl << s5 << endl << s6 << endl; 
	s6.push_back('x');
	cout << s6 << endl;
	s6.append("1996");
	cout << s6 << endl;
	s6 += "1021";
	cout << s6 << endl;
}

void test03() // 构造函数
{
	string s1 = "duwei1996";	
	string s2("zhangsan1998",8); // 使用前八个字符初始化
	cout << s2 << endl;
	string s3("lisi1997",4,4); // 初始化s3，使用从下标为4的字符开始连续的4个字符（如果第二个参数时候string::npos则表示一直到末尾）
	cout << s3 << endl;
	string s4("lisi1997",2,string::npos); // string::npos的值是-1，但是其类型为无符号整数,所以其值是42亿，表示到字符串的末尾
	cout << s4 << endl;
}

void test04() // 遍历
{
	string s1("duwei19961021");
	for(size_t i = 0; i < s1.size(); ++i)
		cout << s1[i] << "-";
	cout << endl;

	// 迭代器
	for(string::iterator it = s1.begin(); it != s1.end(); it++)
			cout << *it << "~";
	cout << endl;

	for(auto ch:s1) // c++11
	{
		cout << ch << " ";
	}
	cout << endl;

	for(string::reverse_iterator rit = s1.rbegin(); rit != s1.rend(); rit++) // 反向迭代器
			cout << *rit << "^";
	cout << endl;
}

int main()
{
	test04();
	return 0;
}
