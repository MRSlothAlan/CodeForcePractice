#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

const int MAX = 200;
char path[MAX];

int main() {
	// frog jump problem.
	// home : point n, starts from point 1
	// jump 1 <= j <= d
	int n, d; scanf("%d %d", &n, &d);
	// first && last char == 1.
	scanf("%s", &path);
	// try out a greedy one
	int cnt = 0;
	int i = 0, j;
	while(i < n - 1) {
		int prev_i = i;
		for (j = i + d; j > i; j--) {
			if (j < n && path[j] == '1') {
				i = j;
				cnt++;
				break;
			}
		}
		if (j <= prev_i)
			break;
	}
	if (i == n - 1) {
		printf("%d\n", cnt);
	}
	else {
		printf("-1\n");
	}
	return 0;
}