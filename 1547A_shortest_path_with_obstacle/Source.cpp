#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
int abs_val(int in_val) {
	return (in_val ^ (in_val >> 31)) - (in_val >> 31);
}
int main() {
	int t; scanf("%d", &t);
	int xa, ya, xb, yb, xf, yf;
	while (t--) {
		scanf("%d %d", &xa, &ya); 
		scanf("%d %d", &xb, &yb);
		scanf("%d %d", &xf, &yf);
		// nothing happens in normal cases.
		if (xa == xb && xb == xf) {
			if ((yf < yb && yf < ya) || (yf > yb && yf > ya)) {
				printf("%d\n", abs_val(xa - xb) + abs_val(ya - yb));
			}
			else {
				printf("%d\n", abs_val(ya - yb) + 2);
			}
		}
		else if (ya == yb && yb == yf) {
			if ((xf < xb && xf < xa) || (xf > xb && xf > xa)) {
				printf("%d\n", abs_val(xa - xb) + abs_val(ya - yb));
			}
			else {
				printf("%d\n", abs_val(xa - xb) + 2);
			}
		}
		else {
			printf("%d\n", abs_val(xa - xb) + abs_val(ya - yb));
		}
	}
	return 0;
}
// y => row, x => col.