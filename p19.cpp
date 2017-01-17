#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int i = 1; i <= T; ++i)
	{
		vector<int> speeds;
		int N;
		cin >> N;
		for(int j = 0; j < N; ++j)
		{
			int temp;
			cin >> temp;
			speeds.push_back(temp);
		}
		sort(speeds.begin(), speeds.end());
		cout << "Case " << i << ": " << speeds[speeds.size()-1] << endl;
	}
	return 0;
}