#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
const int len = 110000;
char s[len];
int dp[len];

/*
Precalculate some array Ai, 
that Ai = 1, if si = si + 1, else Ai = 0. 
Now for any query (l, r), you need to find sum of Ai, that (l ≤ i < r). 
It is standart problem. 
For solving this problem you can precalcutate some another array Sum, 
where Sumi = A1 + A2 + ... + Ai. Then sum of interval (l, r) is Sum_r — Sum_{l-1}.
*/
int main() {
	scanf("%s", &s);	// only consist of characters . and #
	int m; scanf("%d", &m);
	int n = strlen(s);
	int prev_u = -1;
	// init
	if (s[0] == s[1]) { dp[0] = 1; }
	for (int i = 1; i < n - 1; i++) {
		if (s[i] == s[i + 1]) { 
			dp[i] = 1 + dp[i - 1]; 
		}
		else {
			dp[i] = dp[i - 1];
		}
	}
	dp[n - 1] = dp[n - 2];
	while (m--) {
		int l, r; scanf("%d %d", &l, &r);
		l -= 2; r -= 2;
		int res_val; 
		if (l < 0) {
			res_val = dp[r];
		}
		else {
			res_val = dp[r] - dp[l];	// exclude all values before l.
		}
		/*
		for (int i = l; i < r; i++) {
			res_val += dp[i];
		}
		*/
		printf("%d\n", res_val);
	}
	return 0;
}