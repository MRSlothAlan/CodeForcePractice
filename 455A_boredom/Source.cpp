#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define ll long long
const int MAX_ = 100050;
ll dp[MAX_];
// other's idea
ll rec[MAX_];
// ends

/*
To be fair, you can solve many problems,
dp is the major bottleneck. If you can overcome this, success is yours.
Else, nope.
Now read some books.
*/

ll opt() {
	dp[0] = 0;
	dp[1] = rec[1];
	ll res = dp[1];
	int i = 2;
	if (rec[2] == -1) {
		return dp[1];
	}
	int cur_max_val = 0;
	for (i = 2; i < MAX_ && rec[i] != -1; i++) {
		int cur_val = dp[i - 2] + i * rec[i];	// diff = 1, add to sum
		dp[i] = dp[i - 1] > cur_val ? dp[i - 1] : cur_val;
		cur_max_val = i;
	}
	return dp[cur_max_val];
}

ll opt_ver2() {
	// an interval of 2, can add together.
	// why? -1 or +1 excluded, 2 as period.
	ll max_0 = 0,
		max_1 = 0;
		// max_1 = 1;
	for (int i = 1; i < MAX_; i++) {
		ll tmp = max_0;
		max_0 = max(max_1, max_0);	// well.
		if (tmp + rec[i] * i > max_1) {
			max_1 = tmp + rec[i] * i;
		}
	}
	if (max_1 > max_0) {
		return max_1;
	}
	else {
		return max_0;
	}
}

int main() {
	ll n, i, a, back; 
	cin >> n;
	for (int i = 0; i < MAX_; i++) {
		rec[i] = 0;
		// dp[i] = 0;
	}
	// vector<ll> vec;
	// keep a max value count.
	for (i = 0; i < n; i++) {
		scanf("%lld", &a); 
		// other's method
		rec[a]++;	
		// vec.push_back(a); 
	}
	printf("%lld\n", opt_ver2());
	return 0;
}

// sort(vec.begin(), vec.end());
// vec index shifted.
/*
My method:
e.g. 112222233, do back-tracking
if cur - back == 1, keep going back, sum up values

Others:
1 : 2
2 : 5
3 : 2
remove backtrack, just multiply them.
*/
/*
ll max_val = 0;
for (i = 1; i <= n; i++) {
	for (back = i - 1; back - 1 >= 0
			&& vec[i - 1] - vec[back - 1] == 1;
		back--) {}
	dp[i] = vec[i - 1] + dp[back];
	max_val = max(max_val, dp[i]);
}*/
// printf("%lld\n", max_val);