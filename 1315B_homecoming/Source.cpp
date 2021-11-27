#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
const int MAX = 6 * 1e5;
char s[MAX];
long int dp[MAX];
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		memset(dp, 0, sizeof(dp));
		int a, b, p;	// cost of bus ticket, tram ticket, amount of money.
		scanf("%d %d %d", &a, &b, &p);
		scanf("%s", &s); int len = strlen(s) - 1;
		// A = bus station, B, tram station.
		// find closest crossroad i to go on foot the first, so he has enough money.
		char prev = s[len - 1];
		dp[len - 1] = prev == 'B' ? b : a;
		// exception case: what if last step is the destination?
		for (int i = len - 2; i >= 0; i--) {
			if (prev != s[i]) {
				dp[i] = dp[i + 1];
				dp[i] += s[i] == 'B' ? b : a;
			}
			else {
				dp[i] = dp[i + 1];
			}
			prev = s[i];
		}
		int res = len;
		for (; res >= 0 && dp[res] <= p; res--) {}
		if (res >= len - 1) {
			res = len + 1;
		}
		else if (res < 0) {
			res = 1;
		}
		else {
			res += 2;	// idx + one step forward.
		}
		printf("%d\n", res);
	}
	return 0;
}

/*
5
2 2 1
BB
1 1 1
AB
3 2 8
AABBBBAABB
5 3 4
BBBBB
2 1 1
ABABAB
*/

/*
2
1
3
1
6
*/