#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

const int MAX = 200000;
int dp[MAX];

int main() {
	int n; scanf("%d", &n);
	dp[0] = 0;
	int max_val = 0;
	for (int i = 1; i <= n; i++) {
		int price; scanf("%d", &price);
		dp[price]++;
		max_val = price > max_val ? price : max_val;
	}
	for (int i = 1; i <= max_val; i++) {
		dp[i] += dp[i - 1];
	}
	int q; scanf("%d", &q);
	while (q--) {
		long long int coins; scanf("%lld", &coins);
		if (coins >= max_val) {
			printf("%d\n", dp[max_val]);
		}
		else {
			printf("%d\n", dp[coins]);
		}
	}
	return 0;
}

/*
case : 
3
435 482 309
7
245
241
909
745
980
29
521
*/