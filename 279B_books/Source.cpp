#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#define MAX(a, b) a > b ? a : b
typedef long long int lld;

/* wait, MUST read consecutive books. */
const int MAX = 200000;
lld arr[MAX];
int main() {
	lld n, t; scanf("%lld %lld", &n, &t);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	lld cur_sum = 0;
	int prev_ptr = 0; int next_ptr = 0;
	// how about 1 2 9 2
	// t = 4?
	lld max_cnt = -1;
	while (next_ptr < n) {
		cur_sum += arr[next_ptr];
		while (cur_sum > t) {
			cur_sum -= arr[prev_ptr++];
			if (prev_ptr >= next_ptr)
				break;
		}
		if (prev_ptr == next_ptr &&
			cur_sum > t) {
			next_ptr++; prev_ptr++;
			if (next_ptr < n)
				cur_sum = arr[next_ptr];
			next_ptr++;
		}
		else {
			max_cnt = MAX(max_cnt, next_ptr - prev_ptr);
			next_ptr++;
		}
	}
	printf("%lld", max_cnt + 1);	// well yes.
	return 0;
}