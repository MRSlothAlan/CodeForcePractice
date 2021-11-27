#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
typedef long long int lld;
/* 
move first table only...?
*/
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		lld W, H; scanf("%lld %lld", &W, &H);
		lld x1, y1, x2, y2; scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
		lld w, h; scanf("%lld %lld", &w, &h);
		lld w_1 = x2 - x1, h_1 = y2 - y1;
		if (w_1 + w > W && h_1 + h > H) {
			printf("-1\n");
		}
		else {
			// too many edge cases.

		}
	}
	return 0;
}