#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#define ABS(a) a < 0 ? a * -1 : a

int main() {
	int row_c = 3;
	int col_c = 3;
	int r = 0;
	int c = 0;
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			int tmp; 
			scanf("%d", &tmp);
			if (tmp == 1) {
				r = i;
				c = j;
			}
		}
	}
	int res = ABS((r - row_c));	// if you define a custome function, add bracket -> value = one.
	res += ABS((c - col_c));
	printf("%d", res);
	return 0;
}
/*
beautiful?
on 9
*/