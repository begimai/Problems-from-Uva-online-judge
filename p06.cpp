#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
	int monthNum = 0;
	double downPaymaent = 0.0;
	double loan = 0.0;
	int numOfDepr = 0;
	
	while(true)
	{
		int result = 0;
		vector<int> months;
		vector<double> depr;
		cin >> monthNum >> downPaymaent >> loan >> numOfDepr;
		if(monthNum < 0){
			break;
		}
		
		for(int i = 0 ; i < numOfDepr; ++i)
		{
			int m;
			double p;
			cin >> m >> p;
			months.push_back(m);
			depr.push_back(p);
		}
		
		double carWorths = downPaymaent + loan;
		double constant = 0.0;
		double monthlyP = loan/(double)monthNum;
		double tipoLoan = loan;
		
		for(int i = 0; i <= monthNum; ++i)
		{
			for(int j = 0; j < months.size(); ++j)
			{
				if(months[j] == i){
					constant = depr[j];
				}
			}
			
			carWorths -= carWorths * constant;
			tipoLoan = loan - monthlyP*i;
			
			if(carWorths>tipoLoan){
				result = i;
				break;
			}
		}
		if(result == 1)
		{
			cout << result << " month" << endl;
		}
		else
		{
			cout << result << " months" << endl;
		}
	}
	return 0;
}
