#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

/*
after cutting, each has len a b or c
after cutting, number of ribbon pieces = max.
*/
const int MAX = 4010;
#define INF 10000000;
int dp[MAX];
int val[3];

int main() {
	int n, a, b, c;
	for (int i = 0; i < MAX; i++) 
		dp[i] = -INF;
	scanf("%d %d %d %d", &n, &val[0], &val[1], &val[2]);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			if (i >= val[j]) {
				dp[i] = max(dp[i], dp[i - val[j]] + 1);
			}
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}