#include <iostream>

using namespace std;

bool isPalindrome(const string& line);
bool isMirrored(const string& line);


int main() {
	string line;
	while(getline(cin, line)) {
		bool pal = isPalindrome(line);
		bool mir = isMirrored(line);

		cout << line << " -- is ";

		if(pal && mir)
			cout << "a mirrored palindrome." << endl;
		else if(mir)
			cout << "a mirrored string." << endl;
		else if(pal)
			cout << "a regular palindrome." << endl;
		else
			cout << "not a palindrome." << endl;

		cout << endl;
	}

	return 0;
}

bool isPalindrome(const string& line) {
	int mid = line.size() / 2;

	for(int i = 0; i < mid; i++) {
		if(line[i] != line[line.size() - i - 1])
			return false;
	}

	return true;
}

bool isMirrored(const string& line) {
	int mid = line.size() / 2;

	if(line.size() % 2 != 0)
		mid++;

	const string straight = "AEHIJLMOSTUVWXYZ12358";
	const string reverses = "A3HILJMO2TUVWXY51SEZ8";

	for(int i = 0; i < mid; i++) {
		int pos = straight.find(line[i]);

		if(reverses[pos] != line[line.size() - i - 1])
			return false;
	}

	return true;
}