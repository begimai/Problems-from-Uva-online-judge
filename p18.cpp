#include <iostream>

using namespace std;

int main()
{
	int numOfCases;
	cin >> numOfCases;
	for(int i = 1; i <= numOfCases; ++i)
	{
		int numOfWalls;
		cin >> numOfWalls;
		int high = 0, low = 0;
		int first;
		cin >> first;
		for(int j = 1; j < numOfWalls; ++j)
		{
			int t;
			cin >> t;
			if(t > first)
			{
				++high;
			} else if(t < first)
			{
				++low;
			}
			first = t;
		}
		cout << "Case " << i << ": " << high << " " << low <<endl;
	}
	
}