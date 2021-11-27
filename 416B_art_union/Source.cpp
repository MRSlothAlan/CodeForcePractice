#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

const int MAX = 10;
long int dp[MAX];

int main() {
	// number of pictures, number of painters.
	int m, n; scanf("%d %d", &m, &n);
	memset(dp, 0, sizeof(dp));
	scanf("%d", &dp[1]);
	// init. first picture.
	for (int i = 2; i <= n; i++) {
		scanf("%d", &dp[i]);
		dp[i] += dp[i - 1];
	}
	printf("%d ", dp[n]);
	for (int i = 2; i <= m; i++) {	// number of pictures.
		// init. first painter.
		int ti; scanf("%d", &ti);
		dp[1] += ti;
		for (int i = 2; i <= n; i++) {
			scanf("%d", &ti);
			if (dp[i - 1] <= dp[i]) {
				dp[i] += ti;
			}
			else {
				dp[i] = dp[i - 1] + ti;
			}
		}
		printf("%d ", dp[n]);
	}
	return 0;
}

/*
ri = moment, n-th painter stopped working on the ith picture.

Each picture is first painted by the first painter, then by the second one, and so on. 
That is, after the j-th painter finishes working on the picture, it must go to the (j + 1)-th painter (if j < n);

each painter works on the pictures in some order: first, he paints the first picture, then he paints the second picture and so on;

each painter can simultaneously work on at most one picture. However, the painters don't need any time to have a rest;

as soon as the j-th painter finishes his part of working on the picture, the picture immediately becomes available to the next painter.

1: 2 5
2: 3 1
3: 5 3
4: 10 1

last painter stop working on the i-th picture ?
*/