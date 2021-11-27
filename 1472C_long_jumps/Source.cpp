#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

const int MAX = 300000;
int a[MAX];
int dp[MAX];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		memset(dp, 0, sizeof(dp));
		for (int i = n; i >= 1; i--) {
			dp[i] = a[i];	// cur_val.
			int j = i + a[i];	// rel. prev_val.
			// the expected next idx of cur_val
			if (j <= n) {
				dp[i] += dp[j];
			}
		}
		int max_score = 0;
		for (int i = 1; i <= n; i++) {
			if (dp[i] > max_score)
				max_score = dp[i];
		}
		/*
		int cur_idx = 0;
		int cur_score = 0;
		for (int i = 1; i <= n; i++) {
			cur_idx = i; cur_score = 0;
			while (cur_idx <= n) {
				cur_score += a[cur_idx];
				cur_idx += a[cur_idx];
			}
			max_score = max_score < cur_score ? cur_score : max_score;
		}
		*/
		printf("%d\n", max_score);
		// good night guys.
	}
	return 0;
}