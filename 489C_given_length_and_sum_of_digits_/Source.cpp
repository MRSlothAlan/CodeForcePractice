#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
char res[120];
int main() {
	int m, s; 
	scanf("%d %d", &m, &s);
	// largest value;
	if ((s == 0 && m > 1) || m * 9 < s) {
		printf("-1 -1");
	}
	else {
		// smallest number?
		int tmp_m = m, tmp_s = s, ptr = 0;
		while (tmp_m >= 2 && tmp_s > 9) {
			res[ptr++] = 9 + '0';
			tmp_s -= 9; tmp_m--;
		}
		if (tmp_m > 1 && tmp_s <= 9) {
			res[ptr++] = (tmp_s - 1) + '0'; tmp_m--;
			for (int i = 1; i < tmp_m; i++) {
				res[ptr++] = '0';
			}
			res[ptr++] = '1';
		}
		else if (tmp_m == 1 && tmp_s >= 0) {
			res[ptr++] = tmp_s + '0';
			tmp_m--;
		}
		strrev(res);
		printf("%s", res);
		// largest number?
		memset(res, '\0', sizeof(res));
		for (int i = 0; i < m; i++) {
			if (s > 9) {
				res[i] = '9'; s -= 9;
			}
			else if (s > 0) {
				res[i] = s + '0'; s = 0;
			}
			else {
				res[i] = '0';
			}
		}
		printf(" %s", res);
	}
	return 0;
}
/*
well, what if 2 2?
smallest value? 11
largest value? 20.

how about 2 1?
smallest value? 10
largest value? 10

how about 3 6?
smallest value? 105
largest value? 600
*/