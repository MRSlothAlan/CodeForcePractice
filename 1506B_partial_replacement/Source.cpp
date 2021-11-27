#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
const int MAX = 60;
char s[MAX];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, k; scanf("%d %d", &n, &k);
		scanf("%s", &s);
		int len = strlen(s);
		int left = 0;
		for (; left < len && s[left] != '*'; left++) {}
		s[left] = 'x';
		int right = len - 1;
		for (; right >= 0 && s[right] != '*' && s[right] != 'x'; right--) {}
		s[right] = 'x';
		int res_cnt = 0;
		if (right <= left) {
			res_cnt = 1;
		}
		else {
			res_cnt = 2;
			int cur_i = left;
			int next_i = left + k;
			if (next_i < right) {
				for (; cur_i < right;) {
					for (; next_i > cur_i; next_i--) {
						if (s[next_i] == '*') {
							res_cnt++;
							cur_i = next_i;
							break;
						}
					}
					next_i = cur_i + k >= right ? right : cur_i + k;
					if (s[next_i] == 'x')
						break;
				}
			}
		}
		printf("%d\n", res_cnt);
	}
	return 0;
}

/*
given a number k, string s, replace some * with x.
first & last => *

8 3
*****..*

*/