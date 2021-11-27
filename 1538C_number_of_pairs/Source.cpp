#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long int lld;
const int MAX = 300000;
const int MOD_VAL = 100000;
lld arr[MAX];
vector<lld> vec;


// get idx of the value required
int binary_search_get_idx(int lp, int rp, lld target) {
	int mid = (rp + lp) / 2;
	int ori_r = rp;
	while (arr[mid] != target && rp > lp) {
		if (arr[mid] > target) {
			rp = mid - 1;
		}
		else if (arr[mid] < target) {
			lp = mid + 1;
		}
		mid = (rp + lp) / 2;
		if (mid <= 0) {
			return 0;
		}
		else if (mid >= ori_r) {
			return ori_r;
		}
	}
	return mid;
}
// lower: l - val
// upper: r - val;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		vec.clear();
		lld n, l, r;
		scanf("%lld %lld %lld", &n, &l, &r);
		for (int i = 0; i < n; i++) {
			lld val; scanf("%lld", &val);
			vec.push_back(val);
		}
		// sort(arr, arr + n);	
		sort(vec.begin(), vec.end());
		lld ans = 0;
		// think about the edge cases?
		for (int i = 0; i < n; i++) {
			lld up = upper_bound(vec.begin(), vec.end(), r - vec[i]) - vec.begin();
			lld low = lower_bound(vec.begin(), vec.end(), l - vec[i]) - vec.begin();
			ans += up - low;
			if (l <= 2 * vec[i] && 2 * vec[i] <= r) {
				ans--;
			}
		}
		printf("%lld\n", ans / 2);
	}
	return 0;
}

/*
The problem can be divided into two classic ones:

Count the number of pairs ai+aj≤r;
Count the number of pairs ai+aj≤l−1.	// divide the problem into 2 sub-problems.
Let A — be the answer to the first problem,
and B — be the answer to the second problem.

Then A−B is the answer to the original problem.
The new problem can be solved by binary search.
Iterate over the first element of the pair.
Then you need to count the number of elements such that aj≤r−ai.
If you sort the array,
this value can be calculated by running a single binary search.
*/

/*
lld cnt = 0;
		for (int i = 0; i < n; i++) {
			int lower_idx =
				binary_search_get_idx(0, n - 1, l - arr[i]);
			int upper_idx =
				binary_search_get_idx(0, n - 1, r - arr[i]);
			if (upper_idx <= i) {

			}
			else if (arr[i] + arr[lower_idx] >= l && arr[i] + arr[upper_idx] <= r) {
				if (lower_idx <= i) {
					lower_idx = i + 1;
				}
				if (upper_idx - lower_idx >= 0) {
					cnt += upper_idx - lower_idx + 1;
				}
			}
		}
		printf("%lld\n", cnt);
*/

/*
1
5 5 8
5 1 2 4 3
*/
/*
for (int i = 0; i < n; i++) {
	for (int j = i + 1; j < n; j++) {
		lld tmp = arr[i] + arr[j];
		if (l <= tmp && tmp <= r)
			cnt++;
	}
}
*/

/*
	l = 5, r = 8
	5 1 2 4 3
	5 + 1 1 + 4 2 + 4 4 + 3
	5 + 2       2 + 3
	5 + 3
	must get time limit exceeded if naive.
	2 5 5 1 1
	1 1 2 5 5
	apply a binary search for value? or just see
	whether this is enough.
*/
