#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		printf("%d\n", n);
		for (int i = 1; i < n; i++) {
			printf("%d ", i);
		}
		printf("%d\n", n);
	}
	return 0;
}
/*
choose m such that 1 <= m <= 1000.
*/