#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 200000;
long long int stones[MAX], dp[MAX], dp_s[MAX];

int main() {
	int n; scanf("%d", &n);
	scanf("%lld", &stones[0]); dp[0] = stones[0];
	for (int i = 1; i < n; i++) {
		scanf("%lld", &stones[i]);
		dp[i] = stones[i];
		dp[i] += dp[i - 1];
	}
	sort(stones, stones + n);
	dp_s[0] = stones[0];
	for (int i = 1; i < n; i++) {
		dp_s[i] = stones[i] + dp_s[i - 1];
	}
	int q; scanf("%d", &q);
	while (q--) {
		int t, l, r; scanf("%d %d %d", &t, &l, &r); l--; r--;
		if (t == 1) {
			if (l == 0) {
				printf("%lld\n", dp[r]);
			}
			else {
				printf("%lld\n", dp[r] - dp[l - 1]);
			}
		}
		else if (t == 2) {	// sort
			if (l == 0) {
				printf("%lld\n", dp_s[r]);
			}
			else {
				printf("%lld\n", dp_s[r] - dp_s[l - 1]);
			}
		}
	}
	return 0;
}