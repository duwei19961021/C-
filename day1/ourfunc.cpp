#include <iostream>
void simon(int);

int main()
{
	using namespace std;
	int ret;
	cin >> ret;
	simon(ret);
	return 0;
}

void simon(int n)
{
	using namespace std;
	cout << "ret = " << n << endl;
}
