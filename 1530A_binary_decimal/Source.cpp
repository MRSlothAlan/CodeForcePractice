#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
const int MAX = 12;
char s[MAX];
int dp[MAX];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%s", &s); int len = strlen(s);
		for (int i = 0; i < len; i++) {
			dp[i] = s[i] - '0';
		}
		int cnt = 0;
		bool all_zero = false;
		while (!all_zero) {
			all_zero = true;
			for (int i = 0; i < len; i++) {
				if (dp[i] > 0) {
					all_zero = false;
					dp[i]--;
				}
			}
			if (!all_zero)
				cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}

// recall last time, times 10^k with n...
// just divide by n.