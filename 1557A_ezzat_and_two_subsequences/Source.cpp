#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
typedef long double ld;
const int MAX = 200000;
ld arr[MAX];
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		scanf("%Lf", &arr[0]);
		ld arr_cur_max = arr[0];
		ld cur_sum = arr[0];
		for (int i = 1; i < n; i++) {
			scanf("%Lf", &arr[i]);
			if (arr[i] > arr_cur_max) {
				arr_cur_max = arr[i];
			}
			cur_sum += arr[i];
		}
		cur_sum -= arr_cur_max;
		printf("%.10Lf\n", arr_cur_max + cur_sum / (n - 1));
	}
	return 0;
}
/*
previous code:
ld arr_avg_for[MAX],
	arr_avg_rev[MAX];
		arr_avg_for[0] = arr[0];
		arr_avg_rev[0] = arr[0];
			arr_avg_for[i] = arr[i] + arr_avg_for[i - 1];
			arr_avg_rev[i] = arr[i];
					for (int i = 0; i < n; i++) {
			arr_avg_for[i] /= (i + 1);
		}
		arr_avg_rev[n - 2] += arr_avg_rev[n - 1];
		for (int i = n - 3; i >= 0; i--) {
			arr_avg_rev[i] += arr_avg_rev[i + 1];
		}
		for (int i = n - 1; i >= 0; i--) {
			arr_avg_rev[i] /= (n - i);
		}
		ld max_val = arr_avg_for[0] + arr_avg_rev[1];
		for (int i = 1; i < n - 1; i++) {
			ld tmp = arr_avg_for[i] + arr_avg_rev[i + 1];
			if (tmp > max_val) {
				max_val = tmp;
			}
		}

*/