#include <string>
#include <iostream>
#include <cctype>
using namespace std;

int main()
{
#if 0
	// 定义和初始化string对象
	string s1; // 直接初始化
	string s2 = s1; // 拷贝初始化
	string s3 = "duwei"; // 拷贝初始化
	string s4(10,'c'); // 直接初始化,cccccccccc
	string s5 = "duwei\n1996";
	cout << s5 << endl;

	string s6;
	getline(cin,s6); // 从标准输入中读取一行赋值给s6
	cout << s6 ;

	string s7;
	if(s7.empty())
	{
		cout << "s7 is empty." << endl;
	}
	else
	{
		cout << "s7 is not empty." << endl;
	}

	string s8("duwei19961021");
	cout << "s8.size = " << s8.size() << endl;

	string s9("duwei");
	char c = s9[2];
	cout << c << endl;
	s9[2] = 's';
	cout << s9 << endl;
	
	string s10("duwei");
	string s11("1996");
	cout << s10 + s11 << endl; // 字符相加
	s10 += s11; // duwei1996
	cout << s10 << endl; // duwei1996
	s10 = s11;
	cout << s10 << endl; // 赋值

	if(s10 == s11) // 字符串的比较是区分大小写的
	{
		cout << "s10 == s11" << endl;
	}
	else
	{
		cout << "s10 != s11" << endl;
	}
	s10 = "duwei";
	string s12("zhangsan");
	if(s10 < s12)
	{
		cout << "s10 < s12" << endl;
	}

	string s13,s14;
	cin >> s13 >> s14; // 将第一个输入读入s13,第二个输入读入s14(如果读取字符串中出现空格就会被截断)
	cout << s13 << "," << s14 << endl;
	
	string s15;
	while(getline(cin,s15)) // 读取一整行，包括空白符
	{
		cout << s15 << endl;
	}

	string s16("sfasdfsfalksfjalje");
	string::size_type length = s16.size(); // string::size_type 是一个无符号整数且足够保存任何一个字符串对象的长度 
	cout << length << endl;

	// cctype库
	string s17("d6.");	
	cout << isalnum(s17[2]) << endl; // 是数字或者字母为真,否则为假	
	cout << isalnum(s17[0]) << endl;	
	cout << isalpha(s17[0]) << endl; // 判断是否是字母	
	cout << isalpha(s17[1]) << endl;
	cout << toupper(s17[0]) << endl;
#endif

	// 范围for
	string s18("abcSDFAS2345.*^^%%()^)defghijk");
	size_t count = 0;
	for(char& c:s18)
	{
		if(ispunct(c))
		{
			count++;	
		}
	}

	cout << count << endl;
}
