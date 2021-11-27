#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int lld;
const int MAX = 200500;
lld arr[MAX];
vector<lld> pat_diff;

lld cal_needed(lld diff, lld x) {
	lld cur_needed = diff / x;
	if (diff % x == 0)
		cur_needed -= 1;
	return cur_needed;
}

int main() {
	int n;
	lld k, x;
	// can invite k students at any level.
	// x = max allowed level difference.
	// min. no of groups? 
	pat_diff.clear();
	scanf("%d %lld %lld", &n, &k, &x);
	for (lld i = 0; i < n; i++) {
		lld a; scanf("%lld", &a);
		arr[i] = a;
	}
	sort(arr, arr + n);
	int res_cnt = 1;
	lld prev_a = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] - prev_a > x) {
			pat_diff.push_back(cal_needed(arr[i] - prev_a, x));
			res_cnt++;
		}
		prev_a = arr[i];
	}
	sort(pat_diff.begin(), pat_diff.end());
	int idx = 0, len = pat_diff.size();
	while (k > 0 && idx < len) {
		if (res_cnt <= 1)
			break;
		k -= pat_diff[idx];
		if (k < 0)
			break;
		res_cnt--;
		idx++;
	}
	printf("%d", res_cnt);
	return 0;
}

/*

*/

/*
1 to n students
split the students to stable groups.
8 2 3
1 1 5 8 12 13 20 22
*/