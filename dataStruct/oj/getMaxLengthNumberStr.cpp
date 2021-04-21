#include <iostream>
#include <string>
using namespace std;

bool isNumber(char c)
{
	return c >= '0' && c <= '9';
}

void solution(string& s, string& ret)
{
	string tmp;
	for(size_t i = 0; i < s.size(); i++)
	{
		while(isNumber(s[i]))
		{
			tmp.push_back(s[i]);
			i++;
		}

		if(tmp.size() > ret.size())
		{
			ret = tmp;
		}
		tmp.resize(0);
	}	
}

int main()
{
	string s;

	string ret;

	getline(cin, s);

	cout << s << endl;

	solution(s, ret);

	cout << ret << endl;
	return 0;
}
