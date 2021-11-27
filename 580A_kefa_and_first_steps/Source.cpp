#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

const int MAX = 100100;
int arr[MAX];
int dp[MAX];
/* Maximum non-decreasing subsegment */

int main() {
	int n; scanf("%d", &n);
	dp[0] = 0;
	int max_val = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]); dp[i] = 1;
		if (arr[i] >= arr[i - 1]) {
			dp[i] += dp[i - 1];
			max_val = dp[i] > max_val ? dp[i] : max_val;
		}
	}
	printf("%d\n", max_val);
	return 0;
}