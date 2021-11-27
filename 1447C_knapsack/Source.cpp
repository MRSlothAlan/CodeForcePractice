#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <math.h>
using namespace std;
typedef unsigned long long int llu;
const int MAX = 300000;
struct val {
	llu wi;
	int idx;
	val() {}
	val(int in_i, llu in_w) {
		this->idx = in_i;
		this->wi = in_w;
	}
};
val arr[MAX];
llu rec[MAX];
bool com(val l, val r) {
	return l.wi < r.wi;
}
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n;
		llu W;
		scanf("%d %llu", &n, &W);
		llu val;
		scanf("%llu", &val);
		arr[0].idx = 1;
		arr[0].wi = val;
		for (int i = 1; i < n; i++) {
			scanf("%llu", &val);
			arr[i].idx = i + 1;
			arr[i].wi = val;
		}
		sort(arr, arr + n, com);
		rec[0] = arr[0].wi;
		llu lower_limit = (llu)ceil(W / 2);
		if (rec[0] > W) {
			printf("-1\n");
		}
		else if (rec[0] >= lower_limit && rec[0] <= W) {
			printf("1\n");
			printf("%d\n", arr[0].idx);
		}
		else {
			int i = 1;
			for (; i < n; i++) {
				rec[i] += rec[i - 1] + arr[i].wi;
				if (rec[i] >= lower_limit) {
					break;
				}
			}
			if (rec[i] > W) {
				int j = 0;
				for (; j < i; j++) {
					llu tmp_diff = rec[i] - rec[j];
					if (tmp_diff >= lower_limit &&
						tmp_diff <= W) {
						break;
					}
				}
				if (j >= i) {
					printf("-1\n");
				}
				else {
					printf("%d\n", i - j + 1);
					for (; j <= i; j++) {
						printf("%d ", arr[j].idx);
					}
					printf("\n");
				}
			}
			else {
				printf("%d\n", i + 1);
				for (int j = 0; j <= i; j++) {
					printf("%d ", arr[j].idx);
				}
				printf("\n");
			}
		}
	}
	return 0;
}

/*
3
1 3
3
6 2
19 8 19 69 9 4
7 12
1 1 1 17 1 1 1

1
7 12
1 1 1 17 1 1 1
*/