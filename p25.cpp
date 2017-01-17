#include <iostream>
#include <string>

using namespace std;

int main()
{
	int numOfCases;
	cin >> numOfCases;
	for(int i = 0; i < numOfCases; ++i)
	{
		string temp;
		cin >> temp;
		if(temp.length() > 3)
		{
			cout << "3" << endl;
		} else
		{
			if(temp[0] == 'o' && temp[1] == 'n') 
			{
				cout << "1" << endl;
			} else if(temp[0] == 'o' && temp[2] == 'e')
			{
				cout << "1" << endl;	
			} else if(temp[1] == 'n' && temp[2] == 'e') 
			{
				cout << "1" << endl;
			} else if(temp[0] == 't' && temp[1] == 'w') 
			{
				cout << "2" << endl;
			} else if(temp[0] == 't' && temp[2] == 'o') 
			{
				cout << "2" << endl;
			} else if(temp[1] == 'w' && temp[2] == 'o') 
			{
				cout << "2" << endl;
			}
		}
	}
	return 0;
}