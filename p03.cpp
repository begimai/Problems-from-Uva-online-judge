#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


bool isLegalState(int k, int q);
bool isLegalMove(int q, int m, int k);
bool isMoveAllowed(int k, int m);
void output(bool isLState, bool isLMove, bool isMAllowed, int k, int m);
int main()
{
	int king, queen, move;
	while(cin >> king >> queen >> move)
	{
		bool isLState = isLegalState(king, queen);
		bool isLMove = isLegalMove(queen, move, king);
		bool isMAllowed = isMoveAllowed(king, move);
		output(isLState, isLMove, isMAllowed, king, move);
	}
	return 0;
}

bool isLegalState(int k, int q)
{
	if(k == q)
	{
		return false;
	}
	return true;
}
bool isLegalMove(int q, int m, int k)
{
	if(m == k or m == q)
	{
		return false;
	}
	if((m - q) % 8 != 0 and m / 8 != q / 8 )
	{
		return false;
			
	} 
	if (((k - q) % 8 == 0 and (k - m) % 8 == 0) or (k / 8 == q / 8 and k / 8 == m / 8))
        {
            if (k <= max(q, m) and k >= min(q, m))
            {
                return false;
            }
        }
	
	return true;
}
bool isMoveAllowed(int k, int m)
{
	if((max(k, m) - min(k, m)) == 8 or (max(k, m) - min(k, m) == 1 and k / 8 == m / 8))
	{
		return false;
	}
	return true;
}
void output(bool isLState, bool isLMove, bool isMAllowed, int k, int m)
{
	if(!isLState)
	{
		cout << "Illegal state" << endl;
	} else if(!isLMove)
	{
		cout << "Illegal move" << endl;
	} else if(!isMAllowed)
	{
		cout << "Move not allowed" << endl;
	} else if((k == 0 and m == 9) or (k == 7 and m == 14) or (k == 56 and m == 49) or (k == 63 and m == 54))
	{
		cout << "Stop" << endl;
	} else
	{
		cout << "Continue" << endl;
	}
}