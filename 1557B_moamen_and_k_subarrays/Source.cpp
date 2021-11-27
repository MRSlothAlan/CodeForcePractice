#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long int lld;
const int MAX = 200000;
struct val {
	int i;
	lld num;
	val(){}
	val(int in_i, lld in_n) {
		this->i = in_i;
		this->num = in_n;
	}
};
val arr[MAX];
bool com (val l, val r) {
	return l.num < r.num;
}
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, k; scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++) {
			lld num; scanf("%lld", &num);
			arr[i] = val(i, num);
		}
		sort(arr, arr + n, com);
		int idx = 0;
		while (idx < n && k > 0) {
			val prev_v = arr[idx];
			idx++;
			for (; idx < n &&
				arr[idx].i == prev_v.i + 1; idx++) {
				prev_v = arr[idx];
			}
			k--;
		}
		if (idx >= n) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
	return 0;
}
/* 
1
7 5
6 -1 -2 3 7 5 9
*/