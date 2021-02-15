/*
 * 字符串相乘
 * 链接：https://leetcode-cn.com/problems/multiply-strings/
 */

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	string addStrings(string num1, string num2)
	{
		int end1 = num1.size() - 1, end2 = num2.size() - 1;	
		string retStr;
		int next = 0;
		while(end1 >=0 || end2 >= 0)
		{
			int val1 = 0, val2 = 0;
			if(end1 >= 0)
				val1 = num1[end1] - '0';
			if(end2 >= 0)
				val2 = num2[end2] - '0';
			int ret = val1 + val2 + next;
			if(ret > 9)
			{
				ret -= 10;
				next = 1;
			}
			else
			{
				next = 0;
			}
			retStr.insert(retStr.begin(),ret+'0');
			end1--;
			end2--;
		}
		if(next == 1)
		{
			retStr.insert(retStr.begin(),'1');	
		}
		return retStr;
	}
    string multiply(string num1, string num2) 
	{
		string retStr = "0";
		if(num1 == "0" || num2 == "0")
			return retStr;
		int flag = 0; // 内部的循环完成一次flag+1,利用flag来判断在tmpStr后增加的0的个数(第一次flag=0,因为乘的是各位。第二次flag=1,因为乘的是十位。)
		for(int end1 = num1.size() - 1;end1 >= 0; end1--)
		{
			string tmpStr;
			int next = 0;
			int val1 = 0, val2 = 0;
			for(int end2 = num2.size() - 1;end2 >= 0; end2--)
			{
				val1 = num1[end1] - '0';
				val2 = num2[end2] - '0';
				int ret = val1 * val2 + next;
				if (ret > 9)
				{
					next = ret / 10;
					ret %= 10;
				}
				else
				{
					next = 0;
				}
				tmpStr.insert(tmpStr.begin(), ret+'0');	
			}
			if(next > 0)
			{
				tmpStr.insert(tmpStr.begin(),next+'0'); // 内层循环结束需要判断next的值,如果大于0则需要进位。
			}
			for(int i = 0; i < flag ; i++) // 根据flag的值在tmpStr后面添加0
			{
				tmpStr.push_back('0');
			}
			retStr = addStrings(retStr,tmpStr);
			flag+=1;
		}
		return retStr;
    }
};

int main()
{
	Solution sl;
	string ret = sl.multiply("369943444444444444444444444444444444","29");
	cout << ret << endl;
	return 0;
}
