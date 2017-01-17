#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void calculate(vector<int>& mains, vector<int>& steps);
void findMain(vector<char>& v);
void changeUser(bool& isItFirstUser);
int doInstr(const char& temp);
bool isItMain(const char& temp);
void getChars(string& input);
string readFromInput();
int main()
{
	string input = readFromInput();
	while(input != "#")
	{
		
		getChars(input);
		input = readFromInput();
	}
	return 0;
}

void getChars(string& input)
{
	istringstream sinp(input);
	string temp;
	vector<char> v;
	while(sinp >> temp)
	{
		v.push_back(temp[1]);
	}
	findMain(v);
}

void calculate(vector<int>& mains, vector<int>& steps)
{
	bool isItFirstUser = steps[0]%2==0 ? true:false;
	int firstPScore = 0, secondPScore = 0, moves = mains[0]; 
	for(int i = 0; i < mains.size(); ++i)
	{
		if((steps[i] + mains[i]) < mains[i+1])
		{
			if(isItFirstUser)
			{
				firstPScore += steps[i] + moves;
				moves = 0;
			} else
			{
				secondPScore += steps[i] + moves;
				moves = 0;
			}
		} else 
		{
			if((mains[i+1] - steps[i] - mains[i]) % 2 == 0)
			{
				changeUser(isItFirstUser);
			}
			moves += mains[i+1] - mains[i];
		}	
	} 
	int r = (firstPScore > secondPScore)?1:2;
	cout << r << " " << (r==1 ? firstPScore : secondPScore) + moves << endl;
}

void findMain(vector<char>& v)
{
	vector<int> mains;
	vector<int> steps;
	for(int i = 0; i < v.size(); ++i)
	{
		if(isItMain(v[i]))
		{
			mains.push_back(i);
			cout << i << " main   " ;
			steps.push_back(doInstr(v[i]));
			cout << doInstr(v[i]) << " steps" << endl;
		}
	}
	calculate(mains, steps);
}

bool isItMain(const char& temp)
{
	if(temp == 'A' or temp == 'K' or temp == 'Q' or temp == 'J')
	{
		return true;
	}
	return false;
}

int doInstr(const char& temp)
{
	if(temp == 'A')
	{
		return 4;
	} else if(temp == 'K')
	{
		return 3;
	} else if(temp == 'Q')
	{
		return 2;
	} else if(temp == 'J')
	{
		return 1;
	}
}

void changeUser(bool& isItFirstUser)
{
	if(isItFirstUser)
	{
		isItFirstUser = false;
	} else
	{
		isItFirstUser = true;
	}
}

string readFromInput()
{
	string result, temp;
	for(int i = 0; i < 4; ++i)
	{
		getline(cin, temp);
		if(temp == "#" and i == 0)
		{
			return temp;
		}
		result += temp;
	}
	return result;
}
