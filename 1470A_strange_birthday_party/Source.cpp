#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long int lld;
const int MAX = 600000;
lld present[MAX];
int k_val[MAX], pre_ptr;

bool com(const int& l, const int& r) {
	return l > r;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, m; scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d", &k_val[i]);
		}
		// the price of the present.
		for (int i = 0; i < m; i++) {
			scanf("%lld", &present[i]);
		}
		pre_ptr = 0;
		sort(k_val, k_val + n, com);
		// min cost of the party
		lld res_cost = 0;
		for (int i = 0; i < n; i++) {
			int k = k_val[i] - 1;
			if (pre_ptr < m && present[k] > present[pre_ptr]) {
				res_cost += present[pre_ptr];
				pre_ptr++;
			}
			else {
				res_cost += present[k];
			}
		}
		printf("%lld\n", res_cost);
	}
	return 0;
}

/*
own test case:
2
5 4
2 3 4 3 2
3 5 12 20
10 5
5 4 3 2 1 3 2 1 4 6
10 40 90 160 250

*/

/*
can buy a present j <= k, cost cj dollars.
or just give them cki dollars.
*/
/*
	2 3 4 3 2	(k)
	3 5 12 20	(j), 1, 2, 3, 4
	min cost?? 30.
first : 5 dollar, fixed
second: 12 dollar
third : how about give 3 dollar present?
		-> greedy, 5 dollar present.
forth : 5 dollar present?
fifth : 2 dollars.

well, 4 3 3 2 2
	  3 5 12 20 (incresing order).
4 -> 3 p
3 -> 5 p
3 -> 12 $	present ptr. check
2 -> 5 $
2 -> 5 $
*/