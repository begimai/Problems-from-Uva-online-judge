#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int x;
	cin >> x;
	vector<int> vect;
	
	while(x != 0)
	{
		vect.push_back(x);
		cin >> x;
	}
	cout << "PERFECTION OUTPUT" << endl;
	for(int i = 0; i < vect.size(); ++i)
	{
		int summ = 0;
		string result = "";
		for(int j = 1; j < vect[i]; ++j)
		{
			if(vect[i]%j == 0)
			{
				summ += j;
			}
		}
		if(summ > vect[i])
		{
			result = "ABUNDANT";
		} else if (summ < vect[i])
		{
			result = "DEFICIENT";
		} else
		{
			result = "PERFECT";
		}
		cout << right << setw(5) << vect[i] << "  " <<
		result << endl;
	}
	cout << "END OF OUTPUT" << endl;
	
	return 0;
}