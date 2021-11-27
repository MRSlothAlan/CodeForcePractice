#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

/*
condition: each problem, (but the last one)
there should be a problem, dp > dc, dp <= 2dc.
*/
const int MAX = 400000;
int arr[MAX];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) { scanf("%d", &arr[i]); }
	if (n == 1) { printf("1"); }
	else {
		int res_cnt = 1;
		int cur = 1;
		for (int i = 1; i < n; i++) {
			if (arr[i - 1] < arr[i] && arr[i] <= 2 * arr[i - 1]) { cur++; }
			else { cur = 1; }
			res_cnt = res_cnt > cur ? res_cnt : cur;
		}
		printf("%d\n", res_cnt);
	}
	return 0;
}