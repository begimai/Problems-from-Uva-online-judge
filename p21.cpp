#include <iostream>
#include <array>
#include <string>

using namespace std;

int main()
{
	int T;
	cin >> T;
	
	for(int i = 1; i <= T; ++i)
	{
		string url[10];
		int count[10];
		int maxValue = 0;
		for(int j = 0; j < 10; ++j)
		{
			string temp;
			cin >> temp;
			url[j] = temp;
			
			int t;
			cin >> t;
			if(t > maxValue)
			{
				maxValue = t;
			}
			count[j] = t;
		}
		cout << "Case #" << i << ":" << endl; 
		for(int j = 0; j < 10; ++j)
		{
			if(count[j] == maxValue)
			{
				cout << url[j] << endl;
			}
		}
		
	}
	return 0;
}
