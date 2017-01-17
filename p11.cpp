#include <iostream> 

using namespace std;

int main()
{
	unsigned int n;
	while(true)
	{
		unsigned int result, temp = 0; 
		cin >> n;
		if(n == 0)
		{
			break;
		}
		while((n/10) != 0 )
		{
			result = 0;
			temp = n;
			while (temp != 0)
			{
				result += temp % 10;
				temp /= 10;
			}
			n = result;
		}
		
		cout << n << endl;
	}
	return 0;
}