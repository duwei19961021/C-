#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int arr[9] = {6,3,1,7,5,8,9,2,4};
	queue<int> qq;
	for(int i = 0; i < 9; i++)
	{
		qq.push(arr[i]);
	}

	queue<int> ret;
	while(!qq.empty())
	{
		ret.push(qq.front());
//		cout << "ret.push(" << qq.front()  << ")" << endl;
		qq.pop();
		qq.push(qq.front());
//		cout << "qq.push(" << qq.front() << ")" << endl; 
		qq.pop();
	}
	while(!ret.empty())
	{
		cout << ret.front();
		ret.pop();
	}
	cout << endl;
	return 0;
}
