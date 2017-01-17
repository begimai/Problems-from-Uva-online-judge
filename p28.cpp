#include <iostream>

using namespace std;

int main()
{
	int a, b;
	while(cin >> a >> b)
	{
		if(a == -1 and b == -1)
		{
			break;
		}
		int t1 = (b-a) < (a-b) ? a-b : b-a;
		int t2 = (100 + a - b) < (100 + b - a) ? (100 + a - b) : (100 + b - a);
		int result = t1;
		result = t1 > t2 ? t2 : t1;
		cout << result << endl;
	}
	return 0;
}