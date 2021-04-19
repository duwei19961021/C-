#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<char, int> m;
	string s1,s2;
	getline(cin, s1);
	getline(cin, s2);
	for(size_t i = 0; i < s2.size(); i++)
	{
		m[s2[i]] = 1;
	}

	for(string::iterator it = s1.begin(); it != s1.end(); it++)
	{
		if(m[*it] == 1)
		{
			cout << *it << endl;
			it = s1.erase(it);
		}
	}
	cout << s1 << endl;
	return 0;
}
