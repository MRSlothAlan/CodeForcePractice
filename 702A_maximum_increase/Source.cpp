#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
/*
	1 5 9 6 9 8 6 2 
dp	1 2 3 1 2 1 1 1
*/
const int MAX = 1e6;
int dp[MAX];
int arr[MAX];

int main() {
	int n; scanf("%d", &n);
	scanf("%d", &arr[0]);
	for (int i = 0; i < n; i++) dp[i] = 1;
	int max_len = 1;
	for (int i = 1; i < n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] > arr[i - 1]) {
			dp[i] += dp[i - 1];
			if (dp[i] > max_len) {
				max_len = dp[i];
			}
		}
	}
	printf("%d\n", max_len);
	return 0;
}