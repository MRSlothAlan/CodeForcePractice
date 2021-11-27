#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define debug(n) cout << #n << " : " << n << endl;
#define mod 1000000007
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << endl;
#define name(x) cout << #x << " : ";
int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vector<ll> a(n), b(n), prefA(n + 1, 0), prefB(n + 1, 0);
		for (auto &i : a) {
			cin >> i;
		}
		for (auto &i : b) {
			cin >> i;
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for (ll i = 0; i < n; ++i) {
			prefA[i + 1] = prefA[i] + a[i];
			prefB[i + 1] = prefB[i] + b[i];
		}
		ll ans = 0;
		for (ll k = 0; k <= n; ++k) {
			ll total = n + k;
			ll minus = total / 4;
			ll j = total - minus;
			ll me = prefA[n] - prefA[minus] + (k * 100);
			ll opp = prefB[n] - prefB[max(n - j, 0LL)];
			if (me >= opp) {
				ans = k;
				break;
			}
		}
		cout << ans << endl;
	}
}
// study this later
/*
typedef long long int lld;
const int MAX = 100500;
lld rec[2][MAX];
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		lld llyaS = 0, AlanS = 0;
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lld", &rec[0][i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%lld", &rec[1][i]);
		}
		sort(rec[0], rec[0] + n);
		sort(rec[1], rec[1] + n);
		int cur_stage = n;
		// init.
		int needed = cur_stage - (int)floor(cur_stage / 4);
		int cur_needed = needed;
		rec[0][n] = 100;
		for (int i = cur_stage - needed; i < n; i++) {
			AlanS += rec[0][i];
			llyaS += rec[1][i];
		}
		int llyaS_ptr = cur_stage - needed - 1;
		int Alan_ptr = cur_stage - needed;
		while (AlanS < llyaS) {
			cur_stage++;
			rec[0][cur_stage] = 100;
			cur_needed = cur_stage - (int)floor(cur_stage / 4);
			int lower_ = cur_stage - cur_needed;
			AlanS -= rec[0][lower_];
			AlanS += 100;

if (cur_needed > needed) {
	int mag = cur_needed - needed;
	int tmp = mag;
	while (tmp > 0 && llyaS_ptr >= 0) {
		tmp--;
		llyaS += rec[1][llyaS_ptr--];
	}
	tmp = mag;
	while (tmp > 0 && lower_ >= 0) {
		tmp--;
		AlanS += rec[0][lower_--];
	}
}
needed = cur_needed;
		}
		printf("%d\n", cur_stage - n);
	}
	return 0;
}
*/

/*
for (int i = cur_stage - 1; i >= lower_; i--) {
	AlanS += rec[0][i];
}*/