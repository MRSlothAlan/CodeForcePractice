#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#define MAX(a, b) a > b ? a : b;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int red_max = 0, red_prev = 0, blue_max = 0, blue_prev = 0;
		int n; scanf("%d", &n);
		while (n--) {
			int r; scanf("%d", &r);
			red_max = MAX(red_max, red_prev + r);
			red_prev = red_prev + r;
		}
		int m; scanf("%d", &m);
		while (m--) {
			int b; scanf("%d", &b);
			blue_max = MAX(blue_max, blue_prev + b);
			blue_prev = blue_prev + b;
		}
		int res = MAX(0, red_max + blue_max);
		printf("%d\n", res);
	}
	return 0;
}