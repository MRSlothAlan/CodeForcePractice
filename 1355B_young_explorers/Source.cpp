#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		int ans = 0, cur = 0;
		for (int i = 0; i < n; i++) {
			// 2 is like : 2 2 (pick) 2 2(pick) 2 (drop / join 3) 3
			if (++cur == a[i]) {	// cur = 1.
				ans++;
				cur = 0;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
const long int MAX = 400000;
long int cnt[MAX];
vector<long int> vec;
set<long int> S;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		vec.clear(); S.clear();
		int n; scanf("%d", &n);
		long int max_val = 0;
		for (int i = 0; i < n; i++) {
			long int ei; scanf("%ld", &ei);
			S.insert(ei);
			cnt[ei]++;
			max_val = max_val > ei ? max_val : ei;
		}
		for (long int s : S) {
			vec.push_back(s);
		}
		long int len = vec.size();
		sort(vec.begin(), vec.end());
		long int res_gp = 0;
		int cur_idx = 0;
		for (long int exp_ : vec) {
			if (cnt[exp_] >= exp_) {
				res_gp += (long int)(cnt[exp_] / exp_);
				cnt[exp_] %= exp_;
			}
			// get prev_cnt as well.
			long int tmp_pp = 0;
			int i = cur_idx;
			for (; i >= 0 && cnt[vec[i]] > 0; i--) {
				tmp_pp += cnt[vec[i]];
			}
			if (tmp_pp >= exp_) {
				res_gp++;
				for (int j = cur_idx; j >= 0 && j >= i; j--) {
					cnt[vec[i]] = 0;
				}
			}
			cur_idx++;
		}
		printf("%d\n", res_gp);
	}
	return 0;
}
*/

