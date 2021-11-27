#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a < b ? b : a
/*
a = 0, ff (gym, contest)
a = 1, ft
a = 2, tf
a = 3, tt.

rest / contest (2) / gym (1)
// min number of days to have a rest.
no sport / contest on any 2 con. days.
*/
const int MAX = 120;
int arr[MAX];
int dp[3][MAX];
int n, res_cnt;

/*
void naive_recur(bool prev_gym, int cur_cnt, int cur_day) {
	if (cur_day >= n) {
		res_cnt = MIN(res_cnt, cur_cnt);
	}
	else {
		switch (arr[cur_day]) {
		case(0):
			naive_recur(prev_gym, cur_cnt, cur_day + 1);
			break;
		case(1):
			if (prev_gym) {
				naive_recur(!prev_gym, cur_cnt + 1, cur_day + 1);
			}
			else {
				naive_recur(prev_gym, cur_cnt, cur_day + 1);
			}
			break;
		case(2):
			if (!prev_gym) {
				naive_recur(!prev_gym, cur_cnt + 1, cur_day + 1);
			}
			else {
				naive_recur(prev_gym, cur_cnt, cur_day + 1);
			}
			break;
		case(3):
			naive_recur(!prev_gym, cur_cnt + 1, cur_day + 1);
			naive_recur(prev_gym, cur_cnt, cur_day + 1);
			break;
		}
	}
}
*/

int main() {
	scanf("%d", &n);
	res_cnt = 0;
	for (int i = 1; i <= n; i++) { scanf("%d", &arr[i]); }
	dp[1][0] = 0;	// G
	dp[2][0] = 0;	// C
	dp[1][1] = 0;	// G
	dp[2][1] = 0;	// C
	// count the working days.
	// edit: the person can intentionally rest.
	// init
	// edit: use dp[0] to encode rest day.
	dp[1][1] = dp[2][0];
	dp[2][1] = dp[1][0];
	if (arr[1] == 1) {
		dp[2][1]++;
	}
	else if (arr[1] == 2) {
		dp[1][1]++;
	}
	else if (arr[1] == 3) {
		dp[1][1]++;
		dp[2][1]++;
	}
	dp[0][1] = MAX(dp[1][0], dp[2][0]);	// great, use this to encode rest day
	for (int day = 2; day <= n; day++) {
		dp[1][day] = dp[2][day - 1];
		dp[2][day] = dp[1][day - 1];
		dp[0][day] = MAX(dp[1][day - 1], dp[2][day - 1]);
		if (arr[day] == 1) {
			dp[2][day] = MAX(dp[0][day - 1] + 1, dp[2][day] + 1);
		}
		else if (arr[day] == 2) {
			dp[1][day] = MAX(dp[0][day - 1] + 1, dp[1][day] + 1);
		}
		else if (arr[day] == 3) {
			dp[1][day] = MAX(dp[0][day - 1] + 1, dp[1][day] + 1);
			dp[2][day] = MAX(dp[0][day - 1] + 1, dp[2][day] + 1);
		}
	}
	res_cnt = MIN(MIN(n - dp[1][n], n - dp[2][n]), n - dp[0][n]);
	printf("%d", res_cnt);
	return 0;
}

/*
100
3 2 3 3 3 2 3 1 3 2 2 3 2 3 3 3 3 3 3 1 2 2 3 1 3 3 2 2 2 3 1 0 3 3 3 2 3 3 1 1 3 1 3 3 3 1 3 1 3 0 1 3 2 3 2 1 1 3 2 3 3 3 2 3 1 3 3 3 3 2 2 2 1 3 1 3 3 3 3 1 3 2 3 3 0 3 3 3 3 3 1 0 2 1 3 3 0 2 3 3

Output
23
Answer
16
Checker Log
wrong answer expected '16', found '23'
close
*/

/*
other people's way

#include <cstdio>
#include <vector>

int main(){

	const int N = 3; //Number of possible activities in a day;
	const int INF = 10000;  //A really large number

	int n; scanf("%d\n", &n);
	std::vector<std::vector<int> > dp(N, std::vector<int>(n + 1, 0));
	//First row: Do nothing; Second row: Do sports; Third row: Do programming

	for(int p = 1; p <= n; p++){
		int a; scanf("%d", &a);
		dp[0][p] = 1 + std::min(dp[0][p - 1], std::min(dp[1][p - 1], dp[2][p - 1]));
		dp[1][p] = (a == 0 || a == 1) ? INF : std::min(dp[0][p - 1], dp[2][p - 1]);
		dp[2][p] = (a == 0 || a == 2) ? INF : std::min(dp[0][p - 1], dp[1][p - 1]);
	}



	printf("%d\n", std::min(dp[0][n], std::min(dp[1][n], dp[2][n])));

	return 0;
}
*/