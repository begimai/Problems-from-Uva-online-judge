#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	long int counter = 0;
	while(getline(cin, input))
	{
		int s = input.size();
		for(int i = 0; i < s; ++i)
		{
			if(input[i] == char(34))
			{
				if(counter%2==1)
				{
					input.replace(i, 1, "''");
					++s;
				}
				else
				{
					input.replace(i, 1, "``");
					++s;
				}
				++counter;
			}
		}
		cout << input << endl;
	}
	return 0;
}