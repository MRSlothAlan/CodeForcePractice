#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

const int MAX = 105;
int map[MAX][MAX];

// finish at cell n, m.
// move to right or down.
// move right, cost x, down, y.
// init: diagonal = must have same values.

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, m, k;
		// stand at cell 1,1
		scanf("%d %d %d", &n, &m, &k);
		for (int r = 1; r <= n; r++) {
			map[r][1] = r - 1;
			for (int c = 2; c <= m; c++) {
				map[r][c] = map[r][c - 1] + r;
			}
		}
		if (map[n][m] == k) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}