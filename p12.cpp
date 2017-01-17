#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int numOfCases;
	cin >> numOfCases;
	for(int i = 0; i < numOfCases; ++i)
	{
		vector<int> v;
		int numOfStores, result = 0;
		cin >> numOfStores;
		for(int j = 0; j < numOfStores; ++j)
		{
			int position;
			cin >> position;
			v.push_back(position);
		}
		sort(v.begin(), v.end());
		for(int j = v.size() - 1; j >= 0; --j)
		{
			int temp = 0;
			if(j==0)
			{
				temp = v[j] - v[v.size()-1];
			} else
			{
				temp = v[j] - v[j - 1];
			}
			if(temp < 0)
			{
				temp *= -1;
			}
			result += temp;
		}
		cout << result << endl;
	}
	return 0;
}