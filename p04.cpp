// g++  -std=c++11 337.cpp
 
#include <iostream>
#include <vector>

using namespace std;

void printScreen(const vector <vector<char>>& v);
void clearScreen(vector <vector<char>>& v);
void insertMode(vector <vector<char>>& v, int x, int y, char ch);
void eraseRight(vector <vector<char>>& v, int x, int y);

int main()
{
	int n;
	const int ROWS = 10, COLUMNS = 10;
	int caseNum = 1;

	while (cin >> n) {
		if(n == 0)
			break;

		cin.ignore();

		vector<vector<char>> v(ROWS, vector<char>(COLUMNS));
		clearScreen(v);
		
		int x = 0, y = 0;
		string commands;

		for(int i = 0; i < n; i++) {
			getline(cin, commands);

			bool circ = false;
			bool overMode = true;

			for(string::iterator it = commands.begin(); it!= commands.end(); it++) {

				if(!circ) {
					if (*it == '^')
							circ = true;
					else if(overMode) {
							v[x][y] = *it;
							if(y+1 < COLUMNS)
								y++;
						}
					else {
						insertMode(v, x, y, *it);
						if(y+1 < COLUMNS)
							y++;
					}
				}

				else {
					switch(*it) {
					case '^':
						v[x][y] = '^';	
						y++;
						break;
					case 'b':
						y = 0;
						break;
					case 'c':
						clearScreen(v);
						break;
					case 'd':
						if(x+1 < ROWS)
							x++;
						break;
					case 'e':
						eraseRight(v, x, y);
						break;	
					case 'h':
						x = 0;
						y = 0;
						break;	
					case 'i':
						overMode = false;
						break;	
					case 'l':
						if(y-1 >= 0)
							y--;
						break;	
					case 'o':
						overMode = true;
						break;	
					case 'r':
						if(y+1 < COLUMNS)
							y++;
						break;	
					case 'u':
						if(x-1 >= 0)
							x--;
						break;
					default:
						x = *it - '0';
						y = *(++it) - '0';
					}
					circ = false;
				}
			}
		}

		cout << "Case " << caseNum++ << endl;
		printScreen(v);
		
	}
	
	return 0;
}

void printScreen(const vector <vector<char>>& v) {
	cout << "+" << string(10, '-') << "+" << endl;
	for (int i = 0; i < v.size(); ++i) {
		cout << "|";
		for (int j = 0; j < v[i].size(); ++j) {
			cout << v[i][j];
		}
		cout << "|" << endl;
	}
	cout << "+" << string(10, '-') << "+" << endl;
}

void clearScreen(vector <vector<char>>& v) {
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			v[i][j] = ' ';
		}
	}
}

void insertMode(vector <vector<char>>& v, int x, int y, char ch) {
	v[x].insert(v[x].begin() + y, ch);
	v[x].erase(v[x].end() - 1);
}

void eraseRight(vector <vector<char>>& v, int x, int y) {
	for(int i = y; i < v[x].size(); i++)
		v[x][i] = ' ';
}