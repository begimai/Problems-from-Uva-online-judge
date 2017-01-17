#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string line;
	int counter = 1;
	while(cin >> line)
	{
		if(line == "#")
		{
			break;
		}
		string result = "UNKNOWN";
		string inpWords[] = {"HELLO", "HOLA", "HALLO", "BONJOUR", "CIAO", "ZDRAVSTVUJTE"};
		string outWords[] = {"ENGLISH", "SPANISH", "GERMAN", "FRENCH", "ITALIAN", "RUSSIAN"};
		int arrSize = sizeof(inpWords)/sizeof(inpWords[0]);
		for(int i = 0; i < arrSize; ++i)
		{
			if(line == inpWords[i])
			{
				result = outWords[i];
			}
		}
		cout << "Case " << counter << ": " << result << endl;
		++counter;
	}
	return 0;
}