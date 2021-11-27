#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
char in_str[100];
int cnt[30];
// paint it using pieces of chalk of two colors.
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%s", &in_str);
		memset(cnt, 0, sizeof(cnt));
		int len = strlen(in_str);
		for (int i = 0; i < len; i++) {
			cnt[in_str[i] - 'a']++;
		}
		int red_cnt = 0; int green_cnt = 0;
		for (int i = 0; i < 30; i++) {
			if (cnt[i] > 1) {
				red_cnt++; green_cnt++;
				cnt[i] = 0;
			}
		}
		int remaining_cnt = 0;
		for (int i = 0; i < 30; i++) {
			if (cnt[i] == 1) {
				remaining_cnt++;
			}
		}
		int to_add = remaining_cnt / 2;
		red_cnt += to_add;
		green_cnt += to_add;
		printf("%d\n", green_cnt);
	}
	return 0;
}
/*
each letter exactly one color / no color.
each 2 letters, painted in the same color, different
num red = num green
num of colored = max.

max num of one color.
codeforces
codefrs
2212111
archive
1111111
kza
113
*/