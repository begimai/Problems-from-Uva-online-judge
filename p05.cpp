#include <iostream>

using namespace std;

int main()
{
	long int x, y;
	cin >> x >> y;
	while(x != 0 or y !=0)
	{
		int holder = 0;
		int summ = 0;
		while(x > 0 or y > 0)
		{
			if((x%10 + y%10 +holder) > 9){
				++summ;
				holder = (x%10 + y%10 + holder ) / 10;
			}
			else{
				holder =0;
			}
			x /= 10;
			y /= 10; 
		}
		
		if(summ == 0)
		{
			cout << "No carry operation." << endl;
		} else if(summ ==1)
		{
			cout << "1 carry operation." << endl;
		} else
		{
			cout << summ <<" carry operations." << endl;
		}
		cin >> x >> y;
	}
}