#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
// define function not working for lld. Check that later tho.
using namespace std;
typedef long long int lld;
int main() {
	int k; scanf("%d", &k);
	while (k--) {
		lld n, x, t; scanf("%lld %lld %lld", &n, &x, &t);
		lld rem_num = t / x;	// the remaining number of people to think about
		lld res_sum = 0;
		lld tmp = 0;
		if (n - rem_num > 0)
			tmp = n - rem_num;
		res_sum += tmp * rem_num;
		// sum of 1 2 3 4 ... n, see whether n - 1 / t / x - 1 is smaller?
		tmp = n - 1;
		if (rem_num - 1 < tmp)
			tmp = rem_num - 1;
		res_sum += tmp * (tmp + 1) / 2;
		printf("%lld\n", res_sum);
	}
	return 0;
}
// n = number of participants.
// x = start interval.
// t = contest duration.
/*
people : first  : start at 0, finish at t, 
		 second : start at x, finish at t + x,
		 third  : start at 2x, finish at t + 2x;
when EACH of them finishes
dis = num. of people, started, haven't finish.
n = number of people.

Let's find which participants will disturb participant i. 
Those are participants with number between i+1 and i+min(t/x,n).
So each of first max(0,n−t/x) participants will get t/x dissatisfaction, 
and each next participant will get 1 dissatisfaction less, 
than previous. So the total answer is 
max(0,n−t/x)⋅t/x+min(n−1,t/x−1)⋅min(n,t/x)/2.

		if (n >= rem_num) {

		}
		else {
			res_sum += (n - res_sum) * res_sum;
		}
*/