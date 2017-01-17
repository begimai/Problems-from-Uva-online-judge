#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void getStraightLimits(int& xa, int& xb, int& ya, int& yb, const int kx, const int ky, const vector<string>& board) {
	
	xa = kx;
	xb = kx;
	ya = ky;
	yb = ky;
	
	while(ya > 0) {
		ya--;
		if (board[ya][kx] != '.') {
			break;
		}
	}
	
	while(yb < 7) {
		yb++;
		if (board[yb][kx] != '.') {
			break;
		}
	}
	
	while(xa > 0) {
		xa--;
		if (board[ky][xa] != '.')
			break;
	}
	
	while(xb < 7) {
		xb++;
		if (board[ky][xb] != '.')
			break;
	}
}

bool checkStraight(const int& kx, const int& ky, const vector<string>& board, const bool& kingIsWhite) {
	int minX, maxX, minY, maxY;
	getStraightLimits(minX, maxX, minY, maxY, kx, ky, board);

	char rook = 'R', queen = 'Q';

	if(kingIsWhite) {
		rook = 'r';
		queen = 'q';
	}

	if(board[minY][kx] == rook || board[minY][kx] == queen 
			|| board[maxY][kx] == rook || board[maxY][kx] == queen
			|| board[ky][minX] == rook || board[ky][minX] == queen
			|| board[ky][maxX] == rook || board[ky][maxX] == queen)
		return true;
		
	
	return false;	
}

void getDiagonalLimits(int& xa, int& xb, int& ya, int& yb, int& xc, int& yc, int& xd, int& yd, const int& kx, const int& ky, const vector<string>& board) {
	
	xa = kx; ya = ky;
	xb = kx; yb = ky;
	xc = kx; yc = ky;
	xd = kx; yd = ky;
	
	while(xa > 0 && ya > 0) {
		if (board[--ya][--xa] != '.') {
			break;
		}
	}
	
	while(xb < 7 && yb > 0) {
		if (board[--yb][++xb] != '.') {
			break;
		}
	}
	
	while(xc > 0 && yc < 7) {
		if (board[++yc][--xc] != '.') {
			break;
		}
	}
	
	while(xd < 7 && yd < 7) {
		if (board[++yd][++xd] != '.') {
			break;
		}
	}
}

/*

(xa, ya)      (xb, yb)


(xc, yc)      (xd, yd)

*/

bool checkDiagonal(const int& kx, const int& ky, const vector<string>& board, const bool& kingIsWhite) {
	int xa, ya, xb, yb, xc, yc, xd, yd;
	getDiagonalLimits(xa, xb, ya, yb, xc, yc, xd, yd, kx, ky, board);

	char bishop = 'B', queen = 'Q';

	if(kingIsWhite) {
		bishop = 'b';
		queen = 'q';
	}

	if(board[ya][xa] == bishop || board[ya][xa] == queen
		|| board[yb][xb] == bishop || board[yb][xb] == queen
		|| board[yc][xc] == bishop || board[yc][xc] == queen
		|| board[yd][xd] == bishop || board[yd][xd] == queen )
		return true;
	
	return false;
}

bool checkKnight(const int& kx, const int& ky, const vector<string>& board, const bool& kingIsWhite) {
	for(int y = ky - 2; y <= ky + 2; y++) {
		if(y == ky || y < 0 || y > 7)
			continue;
		for(int x = kx - 2; x <= kx + 2; x++) {
			if(x == kx || x < 0 || x > 7 || (abs(ky - y) + abs(kx - x) != 3))
				continue;
			if(kingIsWhite) {
				if(board[y].find('n') == x)
					return true;
			}
			else {
				if(board[y].find('N') == x) 
					return true;
			}	
		}
	}
	return false;
}

bool checkPawn(const int& kx, const int& ky, const vector<string>& board, const bool& kingIsWhite) {
	int px = kx, py = ky;

	char pawn = 'P';

	if(kingIsWhite) {
		pawn = 'p';
		if(--py < 0)
			return false;
	}
	else {
		if(++py > 7)
			return false;
	}

	if((px < 7 && board[py][px+1] == pawn) || (px > 0 && board[py][px-1] == pawn))
		return true;

	return false;
}

bool getBoard(vector<string>& board, int& bkx, int& bky, int& wkx, int& wky) {
	int counter = 0;
	string row;

	for(int i = 0; i < 8; i++) {
		getline(cin, row);
		board.push_back(row);
		
		if(count(row.begin(), row.end(), '.') == 8)
			counter++;
		
		if(row.find('K') != string::npos) {
			wkx = row.find('K');
			wky = i;
		}
		
		if(row.find('k') != string::npos) {
			bkx = row.find('k');
			bky = i;
		}
	}		
		return (counter==8);
}

bool checkForCheck(const int& kx, const int& ky, const vector<string>& board, const bool& kingIsWhite) {
	return (checkStraight(kx, ky, board, kingIsWhite) || checkDiagonal(kx, ky, board, kingIsWhite) 
		|| checkKnight(kx, ky, board, kingIsWhite) || checkPawn(kx, ky, board, kingIsWhite));
}

int main() {
	bool finished = false;
	int game = 1;
	
	while(!finished) {

		vector<string> boardRows;
		int bkx = 0, bky = 0, wkx = 0, wky = 0;

		finished = getBoard(boardRows, bkx, bky, wkx, wky);
				
		if(!finished) {
			
			bool whiteCheck = checkForCheck(wkx, wky, boardRows, true);
			bool blackCheck = checkForCheck(bkx, bky, boardRows, false);
		
			cout << "Game #" << game << ": ";
			if(whiteCheck)
				cout << "white";
			else if(blackCheck)
				cout << "black";
			else
				cout << "no";
			cout << " king is in check." << endl;
			game++;
			cin.ignore();
		}
	}
	return 0;
}