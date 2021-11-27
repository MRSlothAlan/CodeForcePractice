#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

/*
x = cost of 1x1 tile
y = cost of 1x2 tile.	(row : 1, col : 2);
	'*' : black, '.' : white
*/
/*
Notice that rows can be solved completely separately of each other. Each tile takes either one or two squares but it's always in the same row.

So let's take a look at a single row. There are sequences of dot characters separated by some asterisks. Once again each of these sequences can be solved independently of the others.

Thus, we have these empty strips of empty squares 1×k which, when solved, can be summed up into the whole answer.

There are two cases, depending on if a 1×2 is cheaper than two 1×1 tiles.

If it is then we want to use of many 1×2 tiles as possible. So given k, we can place ⌊k2⌋ 1×2 tiles and cover the rest k−2⋅⌊k2⌋=k mod 2 squares with 1×1 tiles.

If it isn't cheaper then we want to cover everything with 1×1 tiles and never use 1×2 ones. So all k should be 1×1.

The easier way to implement this might be the following. Let's update the price of the 1×2 tile with the minimum of y and 2⋅x. 
This way the first algorithm will produce exactly the same result of the second one in the case when a 1×2 tile isn't cheaper than two 1×1 ones.

Overall complexity: O(nm) per testcase.
*/
#define MIN(a, b) a > b ? b : a;
char map[1500];
int dp[1500];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, m, x, y, j; 
		scanf("%d %d %d %d", &n, &m, &x, &y);
		int res_cost = 0;

		int OneIsCheaper = x * 2 > y ? false : true;
		for (int i = 0; i < n; i++) {
			scanf("%s", &map);
			j = 0;
			if (OneIsCheaper) {
				for (; j < m; j++) {
					if (map[j] == '.') 
						res_cost += x;
				}
			}
			else {
				for (j = 0; j < m; j++) dp[j] = 0;
				j = 1;
				while (j < m) {
					if (map[j] == '.' && map[j - 1] == '.') {
						dp[j] = 1;  dp[j - 1] = 1;
						res_cost += y;
						j += 2;
					}
					else {
						dp[j] = 0;
						j++;
					}
				}
				for (j = 0; j < m; j++) {
					if (dp[j] == 0 && map[j] == '.')
						res_cost += x;
				}
			}
		}
		printf("%d\n", res_cost);
	}
	return 0;
}

/*
if (map[0] == '.')
	dp[0] = x;
else
	dp[0] = 0;
int j = 1;
for (; j < m; j++) {
	if (map[j] == '.') { dp[j] = x + dp[j - 1]; }
	else { dp[j] = dp[j - 1];  }
}
j = 1;
while (j < m) {
	if (map[j] == '.' && map[j - 1] == '.') {
		dp[j] = MIN(dp[j], y);
		dp[j - 1] = dp[j];
		dp[j + 1] = MIN(dp[j] + x, dp[j]);	// the value here.
		j += 2;
	}
	else {
		dp[j] = MIN(dp[j - 1], dp[j]);
		j++;
	}
}
res_cost += dp[m - 1];
*/