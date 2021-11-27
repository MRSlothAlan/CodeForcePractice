#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

const int MAX = 100;
int M[MAX][MAX];
// bool valid[MAX][MAX];
char tmp[MAX];

/*
Let's see how the matrix looks like after some sequence of shoots:

The matrix consists of 0, or
There is at least one 1 at position (n,i) or (i,n), 
and any 1 not at position (n,j) or (j,n) must have 1 below or right.

If the second condition is violated, then the 1 in the corresponding cell would continue its flight. 
Thus, it is necessary and sufficient to verify that the matrix satisfies the condition above.
*/

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		// memset(valid, false, sizeof(valid));
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", &tmp); int len = strlen(tmp);
			for (int j = 0; j < len; j++) {
				M[i][j] = tmp[j] - '0';
			}
		}
		bool invalid = false;
		for (int r = 0; r < n - 1 && !invalid; r++) {
			for (int c = 0; c < n - 1 && !invalid; c++) {
				if (M[r][c] == 1) {
					if (M[r][c + 1] != 1 && M[r + 1][c] != 1) {
						invalid = true;
					}
				}
			}
		}
		if (!invalid) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}

/*
5
4
0010
0011
0000
0000
2
10
01
2
00
00
4
0101
1111
0101
0111
4
0100
1110
0101
0111
*/

/*
for (int r = 0; r < n; r++) {
	int c = n - 1;
	for (; c >= 0 && M[r][c] == 1; c--) {}
	for (; c >= 0 && M[r][c] == 0; c--) {}
	if (c <= -1) {
		for (c = n - 1; c >= 0; c--) {
			valid[r][c] = true;
			if (M[r][c] == 1) {
				int r_a = r - 1;
				for (; r_a >= 0 && M[r][c] == 1; r_a--) {
					valid[r_a][c] = true;
				}
			}
		}
	}
}
for (int c = 0; c < n; c++) {
	int r = n - 1;
	// for (; r >= 0 && valid[r][c]; r--) {}
	for (; r >= 0 && M[r][c] == 1; r--) {}
	for (; r >= 0 && M[r][c] == 0; r--) {}
	if (r <= -1) {
		for (r = n - 1; r >= 0; r--) {
			valid[r][c] = true;
		}
	}
}
bool invalid = false;
for (int r = 0; r < n && !invalid; r++) {
	for (int c = 0; c < n && !invalid; c++) {
		if (M[r][c] == 1 && !valid[r][c]) {
			invalid = true;
		}
	}
}
if (invalid) {
	printf("NO\n");
}
else {
	printf("YES\n");
}
*/