#include <iostream>

using namespace std;

int main()
{
	int numOfCases;
	cin >> numOfCases;
	for(int i = 0; i < numOfCases; ++i)
	{
		long int result;
		int n;
		cin >> n;
		result = (n * 63 + 7492) * 5 -498;
		int temp = result;
		result = (temp % 100) / 10;
		if(result < 0)
		{
			result *= -1;
		}
		cout << result << endl;
	}
}