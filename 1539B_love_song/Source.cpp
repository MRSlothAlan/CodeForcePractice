#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

const int MAX = 100100;
char s[MAX];
int dp[MAX];
// stupid
// you will face some really hard problems
// LATER, not in here.
/*

Accepted, BUT YOU CAN DO MUCH BETTER THAN THIS.
first version runtime : > 2000ms
second : 1153ms
third  : 93ms, WOW.

*/
int main() {
	int n, q; 
	scanf("%d %d", &n, &q);
	scanf("%s", &s);
	dp[0] = s[0] - 'a';
	for (int i = 1; i < n; i++) {
		dp[i] = (s[i] - 'a') + dp[i - 1];	// prefix concept.
	}
	while (q--) {
		int l, r; scanf("%d %d", &l, &r);
		int res_len = (r - l) + 1;
		l -= 1; 
		r -= 1;
		res_len += dp[r];
		if (l - 1 >= 0) {
			res_len -= dp[l - 1];
		}
		// also, different starting point.
		/*
		for (int i = l; i <= r; i++) {
			res_len += dp[i];
		}*/
		printf("%d\n", res_len);
	}
	return 0;
}