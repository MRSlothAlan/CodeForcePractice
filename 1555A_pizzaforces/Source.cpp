#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <cmath>
#include <math.h>
#include <algorithm>
#define MIN_LLD(a, b) a < b ? a : b
typedef long long int lld;
/*
small : 6, mid : 8, large, 10
15, 20, 25 minutes
*/

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		lld n; scanf("%lld", &n);
		if (n <= 6) { printf("15\n"); }
		else {
			if ((n & 1)) {
				n++;
			}
			lld res_time = (lld)n * 2.5;
			// other options? No? Notice something obvious next time la.
			printf("%lld\n", res_time);
		}
	}
	return 0;
}
