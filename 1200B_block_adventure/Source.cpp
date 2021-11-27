#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
/*
game's goal: move the character to the top of the nth column
action:
	remove top block.
	if has block in bag, take one and place at top of ith column
	if diff height <= k, move to NEXT column.

BTW, the HINT IS ACTUALLY KINDA WRONG.
*/
// #define MAX(a, b) a > b ? a : b;
const int MAX = 200;
long long int row[MAX];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		long long int n, m, k;
		// cols, blocks in bag, height diff k
		scanf("%lld %lld %lld", &n, &m, &k);
		for (int i = 0; i < n; i++) {
			scanf("%lld", &row[i]);
		}
		if (n == 1) { printf("YES\n"); }
		else {
			// m = block in bag.
			int i = 0;
			for (; i < n - 1; i++) {
				long long int tmp = row[i] - row[i + 1] + k;
				if (tmp > 0 && tmp > row[i]) {	// greedy, but not too much.
					tmp = row[i];
				}
				m += tmp;
				if (m < 0)
					break;
				/*
				long long int diff = row[i] - row[i + 1];
				diff = diff < 0 ? diff * -1 : diff;
				if (row[i] >= row[i + 1]) {	// greedy, fixed first mistake.
					m += row[i] - row[i + 1] + k;	// greedy. this might gives wrong ans, like when cur = 7, next = 1, k = 2.
				}
				else if (diff > k && row[i] < row[i + 1]) {
					long long int needed = row[i + 1] - row[i] - k;
					if (m < needed)
						break;
					else
						m -= needed;
				}
				*/
			}
			if (i >= n - 1) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}
	return 0;
}