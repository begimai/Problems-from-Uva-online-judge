#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int i = 1; i <= T; ++i)
	{
		int N;
		cin >> N;
		
		int resultForM = 0;
		int resultForJ = 0;
		for(int j = 0; j < N; ++j)
		{
			int temp;
			cin >> temp;
			
			resultForM += temp / 30 + 1;
			resultForJ += temp / 60 + 1;
		}
		resultForJ *= 15;
		resultForM *= 10;
		if(resultForM < resultForJ)
		{
			cout << "Case " << i << ": Mile " << resultForM << endl;
		} else if(resultForM > resultForJ)
		{
			cout << "Case " << i << ": Juice " << resultForJ << endl;
		} else 
		{
			cout << "Case " << i << ": Mile Juice " << resultForJ << endl;
		}
		
	}
	return 0;
}