#include <iostream>
#include <cmath>
#include <string>


using namespace std;

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		string temp;
		cin >> temp;
		int len = temp.length();
		while (temp == "0")
		{
			break;
		}
		if(temp == "1" or temp == "4" or temp == "78")
		{
			cout << "+" << endl;
		} else if(temp[len - 1] == '5' and temp[len - 2] == '3')
		{
			cout << "-" << endl;
		} else if(temp[len - 1] =='4' and temp[0] == '9')
		{
			cout << "*" << endl;
		} else
		{
			cout << "?" << endl;
		} 
	}
	return 0;
}