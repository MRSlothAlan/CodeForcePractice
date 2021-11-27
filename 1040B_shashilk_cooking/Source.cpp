#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
// turn over all n skewers with the minimal possible number of actions
int rec[2000], rec_ptr;
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	if (n <= k) {
		printf("1\n1");
	}
	else if (k == 0) {
		// can be zero ha
		printf("%d\n", n);
		for (int i = 1; i <= n; i++) {
			printf("%d ", i);
		}
	}
	// else if (n / k == 2) {
	else if ( n <= k * 2 + 1 ) {
		printf("1\n%d", k + 1);	// the mid point.
	}
	else {
		// judge where to adjust values.
		int cur = (n & 1) == 0 ? k + 1: k; 
		int interval = k * 2 + 1;
		rec_ptr = 0;
		// for all starting points, get the vals.
		for (int start = 1; start <= k + 1; start++) {
			cur = start;
			for (; cur <= n; cur += interval) {
				rec[rec_ptr++] = cur;
			}
			if (rec[rec_ptr - 1] + k >= n) {
				// ok.
				break;
			}
			else {
				rec_ptr = 0;
			}
		}
		printf("%d\n", rec_ptr);
		for (int i = 0; i < rec_ptr; i++) {
			printf("%d ", rec[i]);
		}
	}
	return 0;
}

/* 
题解：当k=0时，需要翻n次；当n≤2×k+1时，
只需要中间的翻一次；当n>2×k+1时，要具体确定关系，
判断从哪里开始翻。
*/