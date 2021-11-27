#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
string current;
string correct;
vector<int> indice;
int main() {
	cin >> current >> correct;
	int len = current.length();
	int len_cor = correct.length();
	if (current.substr(1, len - 1) == correct) {
		indice.push_back(1);
	}
	for (int i = 1; i < len - 1; i++) {
		if (current.substr(0, i) == correct.substr(0, i) 
			&& current.substr(i + 1, len - i + 1) == correct.substr(i, len_cor - i)) {
			indice.push_back(i + 1);
		}
	}
	if (current.substr(0, len - 1) == correct) {
		indice.push_back(len);
	}
	printf("%d\n", indice.size());
	if (indice.size() > 0) {
		for (int d : indice) {
			printf("%d ", d);
		}
	}
	return 0;
}

/*
number of pos, such that after deleting,
the first str == second str.

time limit exceeded.

The simplest solution is to find two numbers l and r - the length of the longest common prefix and the length of the longest common suffix of two strings, respectively. If l + 1 < n - r then there is no solution. Here n is the length of the first string. Otherwise we should output positions from max(n - r, 1) to min(l + 1, n).
*/