#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int x, y;
	while(cin >> x >> y)
	{
	int x1 = x;
	int y1 = y;
	if(x > y)
	{
		swap(x, y);
	}
	
	int maxLength = 0;
	int cycleLength;
	
	while(x <= y)
	{
		cycleLength = 1;
		int n = x;
		while(n != 1)
		{
			n = (n%2 == 0) ? n/2:3*n+1;
			++cycleLength;
		}
		if(maxLength < cycleLength) 
		{
			maxLength = cycleLength;
		}		
		++x;
	}
	cout << x1 << " " << y1 << " " << maxLength << endl;
}
	return 0;
}