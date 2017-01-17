#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int numOfCases;
	cin >> numOfCases;
	int salaries[4];
	for(int i = 1; i <= numOfCases; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			int t;
			cin >> t;
			salaries[j] = t;
		}
		sort(salaries, salaries + 3);
		cout << "Case " << i << ": " << salaries[1] << endl;
		
	}
	return 0;
}