#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n); 
		int sum_ones = 0;
		int sum_zeros = 0;
		// 1. can just consider 1s, 0s separately.
		// 2. damn, what violate range? I keep one zero = violate range ... oh, n / 2.
		int val;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &val);
			if (val) { sum_ones++; }
			else { sum_zeros++; }
		}
		if ((sum_ones % 2) != 0) {
			sum_ones--;
		}
		if (sum_zeros > sum_ones) {
			printf("%d\n", sum_zeros);
			for (int i = 0; i < sum_zeros; i++) {
				printf("0 ");
			}
			printf("\n");
		}
		else {
			printf("%d\n", sum_ones);
			for (int i = 0; i < sum_ones; i++) {
				printf("1 ");
			}
			printf("\n");
		}
	}
	return 0;
}

/*
if ((i & 1)) {
	sum_odd += arr[i];
}
else {
	sum_even += arr[i];
}
*/

/*
if (sum_odd == sum_even) {
	// just print all of them
	printf("%d\n", n);
	for (int i = 1; i <= n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
else {
	// diu, you forgot to look at the obvious hints once again.
	memset(notskip, true, sizeof(notskip));
	int sum_exp = sum_odd > sum_even ? sum_even : sum_odd;
	// pick the smaller one.
	int idx = 0;
	int cur_sum = -1;
	if (sum_exp == sum_odd) {
		idx = 2;
		cur_sum = sum_even;
	}
	else {
		idx = 1;
		cur_sum = sum_odd;
	}
	int s_cnt = 0;
	for (; idx <= n && cur_sum > sum_exp; idx += 2) {
		if (arr[idx] == 1) {
			cur_sum--;
			notskip[idx] = false;
			s_cnt++;
		}
	}
	printf("%d\n", n - s_cnt);
	for (int i = 1; i <= n; i++) {
		if (notskip[i]) {
			printf("%d ", arr[i]);
		}
	}
	printf("\n");
}
*/