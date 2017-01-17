#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int numOfParticipants, budget, numOfHotels, numOfWeeksToChoose;
	while(cin >> numOfParticipants >> budget >> numOfHotels >> numOfWeeksToChoose)
	{	
		vector<int> forPrices;
		int minPrice = -1;
		for(int i = 0; i < numOfHotels; ++i)
		{
			int tempForPrice;
			cin >> tempForPrice;
			forPrices.push_back(tempForPrice);
			for(int j = 0; j < numOfWeeksToChoose; ++j)
			{
				int tempForBeds;
				cin >> tempForBeds;
				if(tempForBeds > numOfParticipants and 
				  budget >= (tempForPrice * numOfParticipants))
				{
					if(minPrice < 0 or minPrice > tempForPrice)
					{
						minPrice = tempForPrice;
					}
				}
			}
		}
		if(minPrice < 0) 
		{
			cout << "stay home" << endl;
		}
		else 
		{
			cout << minPrice * numOfParticipants << endl;
		}		
	}
	return 0;
}