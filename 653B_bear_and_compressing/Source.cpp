#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
/*
somehow related to suffix stuff.
*/
char rec[50][5], res[50];
int res_cnt;
int n, q;

void opt(char in_c, int in_len) {
	if (in_c == 'e') {
		for (int i = 0; i < q; i++) {
			opt(res[i], 2);
		}
	}
	else if (in_len == n) {
		if (in_c == 'a')
			res_cnt++;
	}
	else {
		for (int i = 0; i < q; i++) {
			if (rec[i][0] == in_c) {
				opt(res[i], in_len + 1);
			}
		}
	}
}

int main() {
	// length of the initial string and the number of 
	// available operations
	// thanks the initial length is max 6.
	scanf("%d %d", &n, &q);
	for (int i = 0; i < q; i++) {
		scanf("%s", &rec[i]); scanf("%s", &res[i]);
	}
	res_cnt = 0;
	if (n == 2) {
		for (int i = 0; i < q; i++) {
			if (res[i] == 'a') {
				res_cnt++;
			}
		}
	}
	else {
		opt('e', 0);	// the start.
	}
	printf("%d", res_cnt);
	return 0;
}


/*
damn, 
*/