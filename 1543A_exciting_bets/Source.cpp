#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
typedef unsigned long long int llu;
llu min(llu a, llu b) {
	return a > b ? b : a;
}
llu max(llu a, llu b) {
	return a < b ? b : a;
}
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		llu a, b; scanf("%llu %llu", &a, &b);
		// determine the maximum excitment
		llu cur_lar = max(a, b);
		llu cur_low = min(a, b);
		llu val = cur_lar - cur_low;
		if (val > 0) {
			printf("%llu %llu\n", val, min(cur_lar % val, val - cur_lar % val));
		}
		else {
			printf("0 0\n");
		}
		
	}
	return 0;
}

/*
f a=b, the fans can get an infinite amount of excitement, and we can achieve this by applying the first operation infinite times.

Otherwise, the maximum excitement the fans can get is g=|a−b| and the minimum number of moves required to achieve it is min(amodg,g−amodg).
*/