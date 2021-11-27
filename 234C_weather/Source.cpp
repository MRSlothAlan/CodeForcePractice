#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#define MIN(a, b) a < b ? a : b
typedef long long int lld;
/*
least number of temperature to be changed for that.
there must be a positive int, such that t1 < 0,... tk < 0, tk+1 > 0, ... tn > 0.

see other problems la.

*/
const int MAX = 1000000;
int prev_pos_cnt[MAX], 
	after_neg_cnt[MAX], 
	rec[MAX];

int main() {
	lld n; scanf("%lld", &n);
	// memset(prev_pos_cnt, 0, sizeof(prev_pos_cnt));
	// memset(after_neg_cnt, 0, sizeof(after_neg_cnt));
	int tmp_pos_cnt = 0;
	for (int i = 0; i < n; i++) {
		lld t; scanf("%lld", &t);
		prev_pos_cnt[i] = tmp_pos_cnt;
		if (t > 0) { 
			rec[i] = 1;
			tmp_pos_cnt++;
		}
		else if (t < 0) { rec[i] = -1; }
		else { 
			rec[i] = 0; 
			tmp_pos_cnt++;
		}
	}
	int tmp_neg_cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		after_neg_cnt[i] = tmp_neg_cnt;
		if (rec[i] <= 0) {
			tmp_neg_cnt++;
		}
	}
	lld res_cnt = MAX, tmp_res_cnt = 0;
	// i = 0 case, tk must < 0
	if (rec[0] > -1) { tmp_res_cnt++; }
	tmp_res_cnt = after_neg_cnt[0];
	res_cnt = MIN(res_cnt, tmp_res_cnt); tmp_res_cnt = 0;
 	// i = n - 2 case, tn-1 must > 0
	if (rec[n - 1] < 1) { tmp_res_cnt++; }
	tmp_res_cnt = prev_pos_cnt[n - 1];
	res_cnt = MIN(res_cnt, tmp_res_cnt); tmp_res_cnt = 0;
	// general case.
	for (int i = 1; i < n - 1; i++) {
		tmp_res_cnt += prev_pos_cnt[i];
		if (rec[i] >= 0)
			tmp_res_cnt++;
		tmp_res_cnt += after_neg_cnt[i];
		res_cnt = MIN(res_cnt, tmp_res_cnt);
	}
	printf("%lld", res_cnt);
	return 0;
}
/*
I guess: 
if no consecutive positive number count > 0,
then just convert them to -1, last one to possitiv.

else, use that sequence as mid-point.
*/