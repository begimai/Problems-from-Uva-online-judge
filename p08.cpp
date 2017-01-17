#include <iostream>

using namespace std;

int main()
{
	unsigned int a, b, c, d;
	while(cin >> a >> b >> c >> d)
	{
		if(a==0 and b==0 and c==0 and d==0)
		{
			break;
		}
		int result = 360*2 + 360;
		int aTOb, bTOc, cTOd;
		aTOb = a < b ? (40-b+a):(a-b);
		result += aTOb*9;
		bTOc = b < c ? (c-b):(40-b+c);
		result += bTOc*9;
		cTOd = c < d ? (40-d+c):(c-d);
		result += cTOd*9;
		cout << result << endl;
	}
	return 0;
	
}