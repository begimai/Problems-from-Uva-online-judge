#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int N, c;
	cin >> N;
	cout << "Lumberjacks:" << endl;
	
	for(int i = 0; i < N; ++i)
	{
		bool isItUp = true;
		bool isItOrdered = true;
		vector<int> l;
		for(int j = 0; j < 10; ++j)
		{
			cin >> c;
			l.push_back(c);
		}
		if(l[0] > l[1])
		{
			isItUp = false;
		}			
		
		if (isItUp) {
 
            for (int j = 1; j < 10; ++j) {
                if (l[j] < l[j - 1]) 
				{
					isItOrdered = false;
				}
            }
 
        } else {
 
            for (int j = 1; j < 10; ++j) 
			{
                if (l[j] > l[j - 1]) 
				{
					isItOrdered = false;
				}
			}
        }
		if(isItOrdered)
		{
			cout << "Ordered" << endl;
		} else
		{
			cout << "Unordered" << endl;
		}
	}
	return 0;
}