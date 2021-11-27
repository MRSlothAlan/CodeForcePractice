#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
const int MAX = 5001;

ll arr[2][MAX];
ll cache[MAX][MAX];

int main() {
	int n, i; 
	scanf("%d", &n);
	ll sum_val = 0;
	for (i = 0; i < n; i++) scanf("%lld", &arr[0][i]);
	for (i = 0; i < n; i++) {
		scanf("%lld", &arr[1][i]);
		sum_val += arr[0][i] * arr[1][i];
	}
	ll max_diff = 0;
	// let the left and right pointer be the interval to be reversed
	// start from the right side
	// at the left point, keep expanding the interval
	// while using the values in the middle
	// [left](within left + 1,..., right - 1)[right]
	// original sum : a[l]*b[l] + (prev. calculated sum) + a[r]*b[r]
	// new sum : inverted indices : a[1]*b[r] + (prev. calculated sum) + a[r]*b[l]
	// get their difference, add that to the sum.

	// remove duplicated calculations. Learn that smart move.
	int left, right;
	for (left = n - 1; left >= 0; --left) {
		for (right = left + 1; right < n; ++right) {
			cache[left][right] = cache[left + 1][right - 1] -
				arr[0][left] * arr[1][left] - arr[0][right] * arr[1][right] +
				arr[0][left] * arr[1][right] + arr[0][right] * arr[1][left];
			max_diff = max(max_diff, cache[left][right]);
		}
	}
	printf("%lld\n", max_diff + sum_val);
	/*
	for (int len = 1; len <= n; len++) {
		for (int toRev = 0; toRev < 2; toRev++) {
			// interval to reverse.
			int another = toRev == 0 ? 1 : 0;
			for (int start = 0; start + len - 1 < n; start++) {
				ll tmp_sum = 0;
				int rev_end = start + len - 1;

				if (cache[0][start - 1] > 0) {
					tmp_sum += cache[0][start - 1];
				}
				else {
					ll val = 0;
					for (int f = 0; f < start; f++) {
						val += arr[0][f] * arr[1][f];
					}
					cache[0][start - 1] = val;
					tmp_sum += val;
				}
				int rev_idx = rev_end;
				for (int i = start; i <= rev_end; i++) {
					tmp_sum += arr[another][i] * arr[toRev][rev_idx];
					rev_idx--;
				}
				if (cache[rev_end + 1][n - 1] > 0) {
					tmp_sum += cache[rev_end + 1][n - 1];
				}
				else {
					ll val = 0;
					for (int b = rev_end + 1; b < n; b++) {
						val += arr[0][b] * arr[1][b];
					}
					cache[rev_end + 1][n - 1] = val;
					tmp_sum += val;
				}
				max_cnt = max(tmp_sum, max_cnt);
			}
		}
	}
	printf("%d\n", max_cnt);
	*/
	return 0;
}

/*
Very good question to see the power of interval dp.
Already have done so in your first loop
But you still don't quite 'get' the meaning of reducing subproblems
i.e. you calculating them anyway, and treat the array as a
lookup table only.
*/

/*
If you can understand the mechanism
many medium ~ medium hard interview questions can be tackled.
*/