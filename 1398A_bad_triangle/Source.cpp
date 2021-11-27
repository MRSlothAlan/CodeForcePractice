#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

const int MAX = 100000;
int in_val[MAX];

int main() {
	int t, n, i; 
	scanf("%d", &t);
	// bad triangle
	while (t--) {
		scanf("%d", &n);	// length of array a, accending order.
		for (i = 1; i <= n; i++) {
			scanf("%d", &in_val[i]);
		}
		int a, b, c;
		// init values
		a = 1; b = 2; c = n;
		if (in_val[a] + in_val[b] <= in_val[c]) {
			printf("%d %d %d\n", a, b, c);
		}
		else {
			printf("-1\n");
		}
	}

	return 0;
}