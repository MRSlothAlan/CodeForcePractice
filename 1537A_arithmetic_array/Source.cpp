#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
typedef long long int lld;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		lld n; scanf("%lld", &n);
		lld sum_ = 0;
		for (int i = 0; i < n; i++) {
			lld val; scanf("%lld", &val);
			sum_ += val;
		}
		// ah, asking you how many numbers to be added?
		lld res = sum_ - n;
		if (res < 0) {
			// em, you can only append a non-negative integer.
			res = 1;
		}
		printf("%lld\n", res);
	}
	return 0;
}