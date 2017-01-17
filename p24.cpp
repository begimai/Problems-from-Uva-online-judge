#include <iostream>

using namespace std;

int main()
{
	int N;
	int counter = 1;
	while(cin >> N)
	{
		if(N == 0)
		{
			break;
		}
		int result = 0;
		for(int i = 0; i < N; ++i)
		{
			int temp;
			cin >> temp;
			if(temp == 0)
			{
				--result;
			} else 
			{
				++result;
			}
		}
		cout << "Case " << counter << ": " << result << endl;
		++counter;
	}
	return 0;
}