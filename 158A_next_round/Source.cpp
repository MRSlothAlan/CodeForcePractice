#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

const int MAX = 60;
int scores[MAX];

int main() {
	int n, k;
	// n contestant, k-th place.
	scanf("%d %d", &n, &k);
	memset(scores, 0, MAX);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &scores[i]);
	}
	int min_score = scores[k];
	int res_cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (scores[i] >= min_score && scores[i] > 0) {
			res_cnt++;
		}
	}
	printf("%d\n", res_cnt);
	return 0;
}