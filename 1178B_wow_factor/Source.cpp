#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
typedef long long int l;
#define MAX(a, b) a > b ? a : b;
const l MAX_ = 2000000;
l dp[MAX_];
l dp_rev[MAX_];
char s[MAX_];

int main() {
	scanf("%s", &s); l len = strlen(s);
	l tmp = -1;
	l cur = 0;
	for (l i = 0; i < len; i++) {
		if (s[i] == 'v') {
			tmp++;
			if (tmp < 1) {
				dp[i] = 0;
			}
			else {
				dp[i] = tmp;
			}
		}
		else {
			if (tmp > 0) {
				cur += tmp;
			}	// MAX(cur, tmp);
			dp[i] = cur;
			tmp = -1;
		}
	}
	cur = 0; tmp = -1;
	for (l i = len - 1; i >= 0; i--) {
		if (s[i] == 'v') {
			tmp++;
			if (tmp < 1) {
				dp_rev[i] = 0;
			}
			else {
				dp_rev[i] = tmp;
			}
		}
		else {
			if (tmp > 0) {
				cur += tmp;
			}
			// cur = MAX(cur, tmp);
			dp_rev[i] = cur;
			tmp = -1;
		}
	}
	l res = 0;
	for (l i = 0; i < len; i++) {
		if (s[i] == 'o') {
			res += dp[i] * dp_rev[i];
		}
	}
	printf("%lld", res);
	return 0;
}