#pragma warning(disable : 4996)
#include <cstdio>
#include <algorithm>
using namespace std;
/*
d days ago, exam
*/
const int MAX = 31;
int mint[MAX], maxt[MAX];
int d, sumTime;
bool checked;

// int bk[MAX];

int main() {
	int i, minTime, maxTime;
	// TLE
	scanf("%d %d", &d, &sumTime);
	checked = false;
	int min_bound = 0, max_bound = 0;
	for (i = 0; i < d; i++) {
		scanf("%d %d", &minTime, &maxTime);
		// poop fuck.
		// I'm back.
		// to be completely honest, I have think of min max range to check YES or NO first
		// but I thought recursive is quick enough, but I am wrong anyway.
		mint[i] = minTime; min_bound += minTime;
		maxt[i] = maxTime; max_bound += maxTime;
	}
	// solve(0, 0); // time limit exceeded.
	/*if (!checked) {
		printf("NO\n");
	}*/
	if (min_bound > sumTime || max_bound < sumTime) {
		printf("NO\n");
	}
	else {
		// 我们判断在min[i]的基础上增加时间，是否可以选择到max[i]。
		printf("YES\n");
		int t;
		for (i = 0; i < d; i++) {
			t = min(mint[i] + sumTime - min_bound, maxt[i]);
			printf("%d ", t);
			sumTime -= (t - mint[i]);	// this might actually be wrong it just turns out that it is kinda right.
		}
	}
	return 0;
}

/*
another greedy:
output all the max values first, then a bunch of min values
sum -= a1;
			for (int i = 0; i < n - 1; i++) {
				 if (b [i] - a [i] <sum) {// first sequentially allocated in order of the largest
					System.out.print(b[i] + " ");
					sum -= b[i] - a[i];
				} else {
					System.out.print((a[i] + sum) + " ");
					sum = 0;
				}
			}
			System.out.println(a[n - 1] + sum);

*/

/*
some old code...
don't make the same mistake in the up-coming competitions.

void solve(int idx, int tmp_sum) {	// init idx = 0
	if (checked)
		return;
	if (idx >= d) {
		if (tmp_sum == sumTime) {
			printf("YES\n");
			for (int i = 0; i < d; i++) {
				printf("%d ", bk[i]);
			}
			checked = true;
			return;
		}
	}
	else {
		for (int i = mint[idx]; i <= maxt[idx]; i++) {
			tmp_sum += i;
			bk[idx] = i;
			solve(idx + 1, tmp_sum);
			tmp_sum -= i;
		}
	}
}
*/