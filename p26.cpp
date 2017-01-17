#include <iostream>\

using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int i = 1; i <= T; ++i)
	{
		int L, W, H;
		cin >> L >> W >> H;
		if(L > 20 or W > 20 or H > 20)
		{
			cout << "Case " << i << ": bad" << endl;
		} else 
		{
			cout << "Case " << i << ": good" << endl;
		}
	}
	return 0;
}