#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int T, N, tkn, nce, cnt, d[200000];
long long W, w8t[200000], sum;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %lld", &N, &W);
		tkn = 0;
		nce = 0;	// used as a flag
		cnt = 0;
		sum = 0;
		for (int n = 0; n < N; n++) {
			scanf("%lld", &w8t[n]);
			if (w8t[n] > W) w8t[n] = 0;	// filter out ones that must > W.
			d[n] = 0;	// init. selected array.
		}
		for (int n = 0; n < N; n++) {
			if (w8t[n] >= (W + 1) / 2) {	// already within range, right.
				tkn = 1;
				nce = n + 1;
				break;
			}
			else if (w8t[n] != 0) {	// smaller than (W + 1) / 2 so far
				sum += w8t[n];
				d[n] = 1;	// picked stuff
				cnt++;
			}
			if (sum >= (W + 1) / 2) {
				nce = n + 1;
				break;
			}
		}
		if (nce != 0) {
			if (tkn == 1) printf("1\n%d\n", nce);
			else {
				printf("%d\n", cnt);
				for (int n = 0; n < N; n++) if (d[n] == 1) printf("%d ", n + 1);
				printf("\n");
			}
		}
		else printf("-1\n");
	}
}