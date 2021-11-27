#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
typedef long long int lld;
/*
minimize the difference between both count of coins.
c1 + 2*c2 = n
*/
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		lld n; scanf("%lld", &n);
		lld one_cnt = n / 3;
		while ((n - one_cnt) % 2 != 0) {
			one_cnt++;
		}
		printf("%lld %lld\n", one_cnt, (n - one_cnt) / 2);
	}
	return 0;
}
/*
32?
10, 11 * 2
well, 
*/