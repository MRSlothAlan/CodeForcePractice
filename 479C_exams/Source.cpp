#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lld;
// a : expected, b : allowed.
struct rec {
	lld a, b;
	rec() {}
	rec(lld in_a, lld in_b) {
		this->a = in_a;
		this->b = in_b;
	}
};
// aware of the case:
/*
4 3
4 2
4 1
4 1
.. etc.
*/
bool com(rec l, rec r) {
	return (l.a < r.a) || 
			(l.a == r.a && l.b < r.b);
}
vector<rec> R;
int main() {
	// take exactly n exams
	int n; scanf("%d", &n);
	R.clear();
	for (int i = 0; i < n; i++) {
		// date of the exam?
		// the early date of passing the ith exam.
		lld a, b; scanf("%lld %lld", &a, &b);
		R.push_back(rec(a, b));
	}
	sort(R.begin(), R.end(), com);
	lld res_date = 0;
	for (int i = 0; i < n; i++) {
		rec cur = R[i];
		if (cur.b >= res_date) {
			res_date = cur.b;
		}
		else {
			res_date = cur.a;
		}
	}
	printf("%lld", res_date);
	return 0;
}