#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int i = 0; i < T; ++i)
	{
		int n;
		cin >> n;
		
		int coord = 0;
		vector<int> v;
		for(int j = 0; j < n; ++j)
		{
			string instr;
			cin >> instr;
			if(instr == "LEFT")
			{
				v.push_back(-1);
			} else if(instr == "RIGHT")
			{
				v.push_back(1);
			} else
			{
				string sample;
				cin >> sample;
				int index;
				cin >> index;
				int temp = v[index - 1];
				v.push_back(temp);
			}
		}
		for(int j = 0; j < v.size(); ++j)
		{
			coord += v[j];
		}
		cout << coord << endl;
		
	}
	return 0;
}