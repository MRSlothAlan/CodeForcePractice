#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
typedef long long int lld;

const lld MAX = 2000000;
char a[MAX], b[MAX];
// minimum cost to make string a like b
// swap any 2 bits, cost = i - j, abs
// switch bit, cost = 1
int main() {
	lld n; scanf("%lld", &n);
	scanf("%s", &a);
	scanf("%s", &b);
	// check from edge toward center.
	int l_ = 0, r_ = n - 1;
	lld res_cnt = 0;
	// well, it won't work every time? 
	// update : yup you're right, just find all the cost 1 swap la.
	// they are like the cheapest opt possible.
	// b is the one to be converted.
	for (int i = 1; i < n; i++) {
		if (a[i] == b[i - 1] && a[i - 1] == b[i] && a[i] != a[i - 1]) {
			res_cnt++;
			char tmp = b[i]; b[i] = b[i - 1]; b[i - 1] = tmp;
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			res_cnt++;
		}
	}
	printf("%lld", res_cnt);
	/*
	while (l_ < r_) {
		// first case:
		if (a[l_] != b[l_] && a[r_] != b[r_]) {
			if (r_ - l_ < 2) { res_cnt++; }
			else { res_cnt += 2; }
		}
		else if (a[l_] != b[l_]) {
			res_cnt++;
		}
		else if (a[r_] != b[r_]) {
			res_cnt++;
		}
		l_++;
		r_--;
	}
	if (l_ == r_ && a[l_] != b[l_]) {
		res_cnt++;
	}
	printf("%lld", res_cnt);
	*/
	return 0;
}
/*
100
001, switch 2 times or swap one time.

0 vs 2
1 vs 1

case:
0101
0011

0 vs 3
1 vs 2
2 vs 1 (break)

cost is 1 by swapping...
how to detect this?
10001
01011
*/