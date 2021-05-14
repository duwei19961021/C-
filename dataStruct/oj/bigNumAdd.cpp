#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> bigNumAdd(string num1, string num2)
{
	reverse(num1.begin(),num1.end());
	reverse(num2.begin(),num2.end());
	vector<int> result;
	int flag = 0;

	size_t size1 = num1.size();
	size_t size2 = num2.size();
	size_t i = 0;
	while(i < size1 && i < size2)
	{
		int ret = num1[i]-'0' + num2[i]-'0' + flag;
		if(ret > 9)
		{
			ret %= 10;
			flag = 1;
		}
		else
		{
			flag = 0;
		}
		result.push_back(ret);
		i++;
	}

	while(i < size1)
	{
		int ret = num1[i]-'0' + flag;
		if(ret > 9)
		{
			ret %= 10;
			flag = 1;	
		}
		else
		{
			flag = 0;	
		}
		result.push_back(ret);
		i++;
	}

	while(i < size2)
	{
		int ret = num2[i]-'0' + flag;
		if(ret > 9)
		{
			ret %= 10;
			flag = 1;	
		}
		else
		{
			flag = 0;	
		}
		result.push_back(ret);
		i++;
	}

	if(flag > 0)
	{
		result.push_back(1);
	}	
	reverse(result.begin(),result.end());
	return result;
}

int main()
{
	string num1, num2;
	cin >> num1;
	cin >> num2;	
	vector<int> ret = bigNumAdd(num1,num2);
	for(size_t i = 0; i < ret.size(); i++)
	{
		cout << ret[i];
	}
	return 0;
}
