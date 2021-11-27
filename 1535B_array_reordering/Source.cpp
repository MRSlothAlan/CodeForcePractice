#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
// practice for the contest tomorrow!
const int MAX = 200000;
int arr[MAX];
/*
even numbers have the first priority, not the largest one.
Please revise some stuff tomorrow!
*/
bool com(int l, int r) {
	return l % 2 < r % 2;
}
int gcd_iter(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		sort(arr, arr + n, com);
		// well, now find it.
		int res_cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (gcd_iter(arr[i], 2 * arr[j]) > 1) {
					res_cnt++;
				}
			}
		}
		printf("%d\n", res_cnt);
	}
	return 0;
}
/*
good pair of indices if 1 <= i < j <= n
and gcd(ai, 1aj) > 1.
*/