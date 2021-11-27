#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b
typedef long long int lld;
const int MAX = 100100;
const lld INF = 999999999;
lld rec[2][MAX];
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int m; scanf("%d", &m);	// number of columns.
		// first row
		scanf("%lld", &rec[0][0]);
		for (int c = 1; c < m; c++) {
			scanf("%lld", &rec[0][c]);
			rec[0][c] += rec[0][c - 1];
		}
		for (int c = 0; c < m; c++) {
			scanf("%lld", &rec[1][c]);
		}
		for (int c = m - 2; c >= 0; c--) {
			rec[1][c] += rec[1][c + 1];
		}
		lld bob_val = 0, res_val = INF;
		// time limit exceeded.
		for (int c = 0; c < m; c++) { // Alice's move
			// printf("\nAlice : %d\n", rec[0][c] + rec[1][c]);
			bob_val = 0;
			// wait, no negative numbers.
			bob_val = MAX(rec[0][m - 1] - rec[0][c], rec[1][0] - rec[1][c]);
			res_val = MIN(res_val, bob_val);
		}
		printf("%lld\n", res_val);
	}
	return 0;
}

/*
game, 2 rows, m columns, each cell, a coins.
both A and B at (1, 1)
	=> go to (2, m)
can move right / down
A moves, collect all the coins
B moves, collect coins he visited, A didn't
score = B's coins.
*/

/*
for (int b_c = 0; b_c < m; b_c++) {
	lld tmp_val = 0;
	if (b_c > c) {
		tmp_val += rec[0][b_c] - rec[0][c];
	}
	if (b_c < c) {
		tmp_val += rec[1][b_c] - rec[1][c];
	}
	if (b_c == c) {
		tmp_val = 0;
	}
	// printf("Bob: %d ", tmp_val);
	bob_val = MAX(tmp_val, bob_val);
}
*/

/*

3
3
1 3 7
3 5 1
3
1 3 9
3 5 1
1
4
7
well, the idea:
1 3 7
3 5 1

1 4 11
9 6 1

if path 2, 10 = A.
9 - 6 = 3.
if path 3, 12 = A
if path 1, 10 = A

*/