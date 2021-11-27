#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
typedef long long int lld;
const int MAX = 200000;
lld arr[MAX];	// tastiness.
lld dp[MAX], dp_rev[MAX];	// the record of tastiness.
// the tutorial code fyr
/*
If there is at least a prefix or a suffix with non-positive sum, 
we can delete that prefix/suffix and end up with an array with sum ≥ the sum of the whole array. 
So, if that's the case, the answer is "NO".

Otherwise, all the segments that Adel can choose will have sum < than the sum of the whole array 
because the elements that are not in the segment will always have a strictly positive sum. So, in that case, the answer is "YES".
Time complexity: O(n)
*/
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		arr[0] = 0;
		// first value at 1, not 0.
		scanf("%lld", &arr[1]);
		dp[1] = arr[1];
		lld yesser_sum = 0;
		yesser_sum += arr[1];
		for (int i = 2; i <= n; i++) {
			scanf("%lld", &arr[i]);
			yesser_sum += arr[i];
			dp[i] = arr[i] + dp[i - 1];
		}
		dp_rev[n] = arr[n];
		for (int i = n - 1; i >= 0; i--) {
			dp_rev[i] = arr[i] + dp_rev[i + 1];
		}
		// the result.
		bool valid = true;
		// faster
		for (int i = 1; i <= n && valid; i++) {
			if (dp[i] <= 0 || dp_rev[i] <= 0) {
				valid = false;
				break;
			}
		}
		if (valid) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
		/*
		// She cannot include all cupcakes at all.
		for (int len = 1; len < n; len++) {
			int end_idx = len;
			int start_idx = 0; lld tmp_sum;
			for (; end_idx <= n; end_idx++) {
				tmp_sum = dp[end_idx] - dp[start_idx];
				if (tmp_sum >= yesser_sum) {
					valid = false;
					break;
				}
				start_idx++;
			}
		}
		*/
	}
	return 0;
}