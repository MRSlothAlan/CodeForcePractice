#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

/*
can only increase by one.
If a number's count = 1, only 1 diversity
else, 2.
check overlapping numbers.
*/
const int MAX = 300000;
int dp[MAX];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		memset(dp, 0, sizeof(dp));
		int n; scanf("%d", &n);
		int max_val = 0;
		for (int i = 0; i < n; i++) {
			int tmp; scanf("%d", &tmp);
			dp[tmp]++;
			max_val = max_val < tmp ? tmp : max_val;
		}
		int res_cnt = 0;
		for (int i = 1; i <= max_val; i++) {
			if (dp[i] > 1) {
				dp[i]--;
				dp[i + 1]++;
			}
			if (dp[i] > 0) {
				res_cnt++;
			}
		}
		// check max_val + 1 as well.
		if (dp[max_val + 1] > 0) {
			res_cnt++;
		}
		printf("%d\n", res_cnt);
	}
	return 0;
}