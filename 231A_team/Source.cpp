#pragma warning(disable : 4996)
#include <cstdio>

int main() {
	// well, warm-ups.
	// last warm-up and go for some harder ones.
	int n, i; scanf("%d", &n);
	int cnt = 0;
	for (i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a && b || b && c || c && a) {
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}