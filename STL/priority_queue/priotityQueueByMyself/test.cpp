#include "PriorityQueue.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	duwei::priority_queue<int, vector<int>, Less<int>> pq;
	pq.push(11);
	pq.push(3);
	pq.push(5);
	pq.push(0);
	pq.push(3);
	pq.push(8);
	pq.push(6);

	while(pq.size() != 0)
	{
		cout << pq.top() << " ";
		pq.pop();	
	}
	
	cout << endl;

	vector<int> v;
	v.push_back(3);
	v.push_back(9);
	v.push_back(9);
	v.push_back(5);
	v.push_back(1);
	v.push_back(7);

	duwei::priority_queue<int> pq2(v.begin(), v.end());

	while(pq2.size() != 0)
	{
		cout << pq2.top() << ",";
		pq2.pop();
	}
	cout << endl;
	return 0;
}
