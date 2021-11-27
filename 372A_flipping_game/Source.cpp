#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 200;
int arr[MAX];
int alt[MAX];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		alt[i] = arr[i] == 1 ? 0 : 1;
	}
	int cur_sum = 0;
	// well.
	for (int len = 1; len <= n; len++) {	// exactly one move.
		for (int idx = 0; idx < n; idx++) {
			int tmp = 0;
			for (int k = 0; k < idx; k++) {
				tmp += arr[k];
			}
			int e = idx + len;
			for (int s = idx; s < e; s++) {
				tmp += alt[s];
			}
			for (int l = e; l < n; l++) {
				tmp += arr[l];
			}
			if (tmp > cur_sum)
				cur_sum = tmp;
		}
	}
	// opt version of the code?
	printf("%d\n", cur_sum);
	return 0;
}

/*
if (n == 1) {
	if (arr[0] == 1)
		printf("0\n");
	else
		printf("1\n");
}
else {
	int res_max = -1;
	int tmp_zeros = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 1) {
			res_max = max(res_max, tmp_zeros + one_sum);
			tmp_zeros = 0;
		}
		else {
			tmp_zeros++;
		}
	}
	res_max = max(res_max, tmp_zeros + one_sum);
	printf("%d\n", res_max);
}
*/