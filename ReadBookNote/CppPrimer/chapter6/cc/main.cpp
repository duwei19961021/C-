#include <iostream>
#include "fun.h"
using namespace std;

int main(int argc, char* argv[])
{
	cout << sum(1,2) << endl;	

	for(size_t i = 0; i < argc; i++)
	{
		cout << argv[i] << endl;
	}
	return 0;
}
