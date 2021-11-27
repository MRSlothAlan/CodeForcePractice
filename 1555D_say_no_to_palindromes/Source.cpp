#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MIN_(a, b) a < b ? a : b
const int MAX = 300000;
char allowed[3] = { 'a', 'b', 'c' };
char s[MAX];
int n, m, st, en;
int dp[10][MAX];

int main() {
	scanf("%d %d", &n, &m);
	scanf("%s", &s);
	// do it before the query.
	int dp_r = 0, len = strlen(s);
	do {
		int ptr = 0;
		if (s[0] != allowed[ptr]) {
			dp[dp_r][0] = 1;
		}
		else {
			dp[dp_r][0] = 0;
		}
		ptr++;
		for (int i = 1; i < len; i++) {
			if (ptr >= 3) { ptr = 0; }
			if (s[i] != allowed[ptr]) {
				dp[dp_r][i] = dp[dp_r][i - 1] + 1;
			}
			else {
				dp[dp_r][i] = dp[dp_r][i - 1];
			}
			ptr++;
		}
		dp_r++;
	} while (std::next_permutation(allowed, allowed + 3));
	while (m--) {
		int res_cnt = MAX;
		scanf("%d %d", &st, &en);
		st--; en--;
		for (int r = 0; r < dp_r; r++) {
			int tmp_cnt = 0;
			if (st <= 0) {
				tmp_cnt = dp[r][en];
			}
			else {
				tmp_cnt = dp[r][en] - dp[r][st - 1];
			}
			res_cnt = MIN_(res_cnt, tmp_cnt);
		}
		printf("%d\n", res_cnt);
	}
	return 0;
}

/*
Note that in the beautiful string 
si≠si−1 (because it is a palindrome of length 2) 
and si≠si−2 (because it is a palindrome of length 3). 
This means si=si−3, i.e. a beautiful string has the form 
abcabcabc..., up to the permutation of the 
letters a, b and c.

For each permutation of the letters a, b and c, 
we will construct a string t, of the form abcabcabc... of 
length n. Let's define an array a of length n as follows: 
ai=0 if si=ti 
(i.e. the character at the i-th position does not need to be 
changed) and ai=1 otherwise. 
Let's build an array pr of prefix sums of the array a. 
Now you can process a query of the number of positions 
that need to be replaced for the current line t in O(1).
*/

