#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	cin >> T;
	int result = 0;
	string input;
	for(int i = 1; i <= T; ++i)
	{
		cin >> input;
		if(input == "donate")
		{
			int temp; 
			cin >> temp;
			result += temp;
		} else 
		{
			cout << result << endl;
		}
	}
	return 0;
}