#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		int cur = 1, next = 2;
		if ((n & 1)) {
			while (cur + 2 < n) {
				printf("%d %d ", next, cur);
				cur += 2; next += 2;
			}
			printf("%d %d %d\n", next, n, cur);
		}
		else {
			while (next < n) {
				printf("%d %d ", next, cur);
				cur += 2; next += 2;
			}
			printf("%d %d\n", next, cur);
		}
	}
	return 0;
}