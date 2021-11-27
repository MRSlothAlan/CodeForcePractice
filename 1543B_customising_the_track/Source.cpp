#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
typedef long long int lld;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		lld sum_val = 0;
		for (int i = 0; i < n; i++) {
			int val; scanf("%d", &val);
			sum_val += val;
		}
		lld r = sum_val % n;
		printf("%lld\n", r * (n - r));
	}
	return 0;
}