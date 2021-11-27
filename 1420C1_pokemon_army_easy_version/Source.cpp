#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int lld;
const int MAX = 600000;
// pokemon army
int arr[MAX];
lld d1, d2;

/*

The easy version of the task can be solved in different ways. For example, you can use the dynamic programming method.

Let d1i – be the maximum possible sum of a subsequence on a prefix from the first i elements,
provided that the length of the subsequence is odd. Similarly enter d2i, only for subsequences of even length.
Then d1i and d2i are easy to recalculate:

d1i+1=max(d1i, d2i+ai),	
.
d2i+1=max(d2i, d1i−ai).
. The initial values are d10=−∞, d20=0. The answer will be stored in max(d1n,d2n).

This solution works for O(n) in time. Its main drawback is that it cannot be used to solve a complex version
of a task where a different approach is needed.
*/

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, q; scanf("%d %d", &n, &q);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		if (n == 1) {
			printf("%d\n", arr[0]);
		}
		else {
			// this is only possible when integers are distinct.
			// this is something new.
			d1 = -MAX; d2 = 0;
			for (int i = 0; i < n; i++) {
				d1 = max(d1, d2 + arr[i]);	// learn this, every even sequence = +
				d2 = max(d2, d1 - arr[i]);	// odd val - arr[i] => even part
			}
			printf("%lld\n", max(d2, d1));
		}
	}
	return 0;
}


// my previous work:

/*
for (int i = 0; i < n; i++) {
			if (arr[i] != min_v) {
				cur_min[i] = min_v; checked[i] = true;
			}
			else {
				checked[min_v] = true;
				while (chk_ptr <= n && checked[chk_ptr]) {
					chk_ptr++;
				}
				min_v = chk_ptr;
				cur_min[i] = min_v;
			}
		}
		memset(checked, false, sizeof(checked));
		chk_ptr = n;
		for (int i = 0; i < n; i++) {
			if (arr[i] != max_v) {
				cur_max[i] = max_v; checked[i] = true;
			}
			else {
				checked[max_v] = true;
				while (chk_ptr >= 1 && checked[chk_ptr]) {
					chk_ptr--;
				}
				max_v = chk_ptr;
				cur_max[i] = max_v;
			}
		}
		// last value's cur_max can be ignored actually.
		// can't do that.
		lld res_sum = 0;
		for (int i = 0; i < n; i++) {
			lld tmp = arr[i] - cur_min[i] + cur_max[i];
		}
		int idx = 0;
		printf("%lld\n", res_sum);
*/