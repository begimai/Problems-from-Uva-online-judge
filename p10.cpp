#include <iostream>

using namespace std;

int main()
{
	int numOfCases;
	unsigned int n, m;
	cin >> numOfCases;
	for(int i = 0; i < numOfCases; ++i)
	{
		cin >> n >> m;
		int forRows = n/3;
		int forCols = m/3;
		int res = forRows * forCols;
		cout <<  res  << endl;
	}
	return 0;
}