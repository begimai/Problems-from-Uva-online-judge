#include <iostream>

using namespace std;

int main()
{
	unsigned int numOfCases, numOfFarmers, areaInSqMeters, 
	numOfAnimals, degreeOfEnvFriendly;
	cin >> numOfCases;
	for(int i = 0; i < numOfCases; ++i)
	{
		int result = 0;
		cin >> numOfFarmers;
		for(int j = 0; j < numOfFarmers; ++j)
		{
			cin >> areaInSqMeters;
			cin >> numOfAnimals;
			cin >> degreeOfEnvFriendly;
			result += areaInSqMeters  * degreeOfEnvFriendly ;
		}
		cout << result << endl;
	}
	return 0;
}