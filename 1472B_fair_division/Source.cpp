#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
/*
n candies, either 1 / 2 grams
divide, A & B, same weight.
*/
const int MAX = 101;
int one_n, two_n;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		one_n = 0; two_n = 0;
		for (int i = 0; i < n; i++) {
			int w; scanf("%d", &w);
			if (w == 1) { one_n++; }
			else { two_n++; }
		}
		int sum = one_n + two_n * 2;
		if (sum % 2 != 0) {
			printf("NO\n");
		}
		else {
			// sum = even, at least 2 candies, w = 1
			// true.
			if (one_n >= 2) {
				printf("YES\n");
			}
			else if (one_n == 0 && (two_n & 1) == 0) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
			/*
			if ((one_n & 1) == 0 && (two_n & 1) == 0) {
				printf("YES\n");
			}
			else {
				// case 2: some combination of 1s -> 2.
				two_n += one_n / 2;
				one_n %= 2;
				if (one_n == 0 && (two_n * 2) % 2 == 0) {
					printf("YES\n");
				}
				else {
					printf("NO\n");
				}
			}
			*/
		}
	}
	return 0;
}