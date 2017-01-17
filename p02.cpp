#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

void output(vector<vector<char>> v, int c);
string readForVector();
void assignV(vector<vector<char>>& v, string line);
string readForInstructions();
int findRowOfWS(vector<vector<char>> v);
int findColOfWS(vector<vector<char>> v);
bool modifyV(vector<vector<char>>& v, string instr);
int main()
{
	int counter = 1;
	while(true)
	{
		vector<vector<char>> v(5, vector<char>(5));
		string forVector = readForVector();
		if(forVector == "!")
		{
			break;
		}
		assignV(v, forVector);
		string instr = readForInstructions();
		if(counter > 1)
		{
			cout << endl;
		}
		if(!modifyV(v, instr))
		{
			cout << "Puzzle #" << counter << ":" << endl;
			cout <<	"This puzzle has no final configuration."<<endl;;
		} else 
		{
			output(v, counter);
		}	
		getline(cin, forVector);
		++counter;
	}
	return 0;
}
string readForVector()
{
	string line, result;
	for(int i = 0; i < 5; ++i)
	{
		getline(cin, line);
		if(line == "Z" and i==0)
		{
			result = "!";
			break;
		} 
		result += line;
	}
		
	return result;
}
void assignV(vector<vector<char>>& v, string line)
{
	istringstream sinp(line);
	char temp;
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
		{
			sinp.get(temp);
			v[i][j] = temp;
		}
	}
}
string readForInstructions()
{
	vector<char> v;
	char ch;
	while((cin >> ch))
	{
		if(ch == '0')
		{
			break;
		}
		v.push_back(ch);
	}
	string line = string(v.begin(), v.end());
	return line;
}

bool modifyV(vector<vector<char>>& v, string instr)
{
	istringstream sinp(instr);
	char temp;
	int row = findRowOfWS(v);
	int col = findColOfWS(v);
	while(sinp >> temp)
	{
		char x;
		if(temp=='A')
		{
			if(row < 1){ return false;}
			x = v[row - 1][col];
			v[row - 1][col] = v[row][col];
			v[row][col] = x;
			--row;
		}
		if(temp=='B')
		{
			if(row == v.size() - 1){return false;}
			x = v[row + 1][col];
			v[row + 1][col] = v[row][col];
			v[row][col] = x;
			++row;
		}
		if(temp=='L')
		{
			if(col < 1){return false;}
			x = v[row][col - 1];
			v[row][col - 1] = v[row][col];
			v[row][col] = x;
			--col;
		}
		if(temp == 'R') 
		{
			if( col == v[0].size() - 1){return false;}
			x = v[row][col + 1];
			v[row][col + 1] = v[row][col];
			v[row][col] = x;
			++col;
		}
	}
	return true;
}
int findRowOfWS(vector<vector<char>> v)
{
	for(int i = 0; i < v.size(); ++i)
	{
		for(int j = 0; j < v[i].size(); ++j)
		{
			if(v[i][j] == ' ')
			{
				return i;
			}
		}
	}
}
int findColOfWS(vector<vector<char>> v)
{
	for(int i = 0; i < v.size(); ++i)
	{
		for(int j = 0; j < v[i].size(); ++j)
		{
			if(v[i][j] == ' ')
			{
				return j;
			}
		}
	}
}
void output(vector<vector<char>> v, int c)
{
	cout << "Puzzle #" << c << ":" << endl;
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
		{
			if((v[i].size() - j) == 1)
			{
				cout << v[i][j];
			}
			else
			{
				cout << v[i][j] << ' ';
			}	
		}
		cout << endl;
	}
}