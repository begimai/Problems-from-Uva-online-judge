#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	while(cin >>n)
	{
		if(n == 0)
		{
			break;
		}
		int boarder1, boarder2;
		cin >> boarder1 >> boarder2;
		
		string result;
		int x, y;
		for(int i = 0; i < n; ++i)
		{
			cin >> x >> y;
		if(x == boarder1 or y == boarder2)
		{
			result = "divisa";
		} else if(x > boarder1 and y > boarder2)
		{
			result = "NE";
		} else if(x < boarder1 and y < boarder2)
		{
			result = "SO";
		} else if(x < boarder1 and y > boarder2)
		{
			result = "NO";
		} else 
		{
			result = "SE";
		}
		cout << result << endl;
		}	
	}
	return 0;
}