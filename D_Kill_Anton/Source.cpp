#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int levenshteinDistance(string str1, string str2) {
	// Write your code here. try to do it yourself
	  // construct a table, initialize with zeros
	  // height = str2 + 1
	  // width = str1 + 1
	int col = str1.length() + 1;
	int row = str2.length() + 1;
	vector<vector<int>> edits(row, vector<int>(col, 0));
	/*
	The relation:
		if letters = same:
			just put the value of the upper left element
			REASON:
				same word cost 0 edits. Therefore the edits in the previous operation
				is recorded.
		else:
			check min(upper, left, upper-left), and + 1
			REASON:
				edits can involve insert / delete / substitude.
				Since different letters, therefore must +1 to
				whatever minimal operations/
	*/
	// code
	// initialize
	for (int i = 0; i < row; i++)
		edits[i][0] = i;
	for (int j = 0; j < col; j++)
		edits[0][j] = j;



	// row for str2, col for str1
	for (int r = 1; r < row; r++)
	{
		for (int c = 1; c < col; c++)
		{
			// don't mess up with the strings haha
			if (str2[r - 1] == str1[c - 1]) {
				edits[r][c] = edits[r - 1][c - 1];
			}
			else {
				edits[r][c] = 1 + min(edits[r - 1][c - 1], min(edits[r - 1][c], edits[r][c - 1]));
			}
		}
	}
	return edits[row - 1][col - 1];
}


int main() {
	// permutation of a.
	// swap 2 adjacent characters each second.
	
	return 0;
}