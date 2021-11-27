#pragma warning(disable : 4996)
#include <cstring>
#include <cstdio>
#define MIN(a, b) a > b ? b : a;
const int MAX = 512;
int dp[MAX][MAX];
char s[MAX][MAX];
using namespace std;

bool match(int s_aid, int s_bid, int str_len_k, 
			int a_start, int b_start) {
	for (int i = 0; i < str_len_k; i++) {
		if (s[s_aid][a_start + i] != s[s_bid][b_start + i])
			return false;
	}
	return true;
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++i) { scanf("%s", &s[i]); }
	int k = strlen(s[1]);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < k; j++) {
			dp[i][j] = 1e9;
		}
	}
	for (int i = 1; i <= n; i++) {
		// same concept as mine, duplicate the substrings.
		for (int idx = k; idx < k * 2; idx++) { 
			s[i][idx] = s[i][idx - k]; 
		}
	}
	for (int i = 0; i < k; ++i) {
		dp[1][i] = i;	// same concept as me so far, cost of swapping sequencially.
	}
	// the DIFFERENCE lies in here, you got 89 corrects ans, he got FULL marks
	/*
	n = number of strings.
	e.g. abcabc
		 cabcab
		1	2	3	4	5	6
	1->	
	2->	
	*/
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < k; j++) {
			for (int prev = 0; prev < k; prev++) {
				// damn, CLEVER AS FUCK, that guy .
				// IF YOU CAN UNDERSTAND THIS, you CAN and you WILL be at another level.
				if (match(i, i - 1, k,
					j, prev)) {
					/*
					e.g.
						str a: xx|xxxxxxxxxx|xxxxxxxxxx
						str b: yyyyyyyy|yyyyyyyyyy|yyyy
						matches! So, dp[i - 1][prev], (all string equals to i - 1 s, moved j times)
						get min val.
					*/
					dp[i][j] = MIN(dp[i][j], dp[i - 1][prev] + j);
				}
			}
		}
	}
	int ans = 1e9;
	for (int i = 0; i < k; i++) {
		/*
		all i strings equals to ith strings, moved i times.
		*/
		ans = MIN(ans, dp[n][i]);
	}
	if (ans == 1e9) {
		printf("-1");
	}
	else {
		printf("%d", ans);
	}
	return 0;
}

/*
分析：以第一个字符串顺序为依照，依次枚举最终字符串以s[0][i]开头的情况，对每种情况去分别计算每个字符串需要的操作数并求和，最终再找到cnt[i]最小值即为答案。复杂度是n^4,可过。
*/