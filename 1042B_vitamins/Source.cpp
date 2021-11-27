#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;
const ll INF = 300000000;
char s[3];
vector<ll> vec[7];
// minimum total price of juices that Petya has to buy.
void vec_opt() {
	for (int i = 0; i < 7; i++) {
		sort(vec[i].begin(), vec[i].end());
	}
}
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		ll cost; scanf("%lld", &cost);
		scanf("%s", &s); int len = strlen(s);
		int a = 0, b = 0, c = 0;
		for (int i = 0; i < len; i++) {
			if (s[i] == 'A') a = 1;
			else if (s[i] == 'B') b = 1;
			else if (s[i] == 'C') c = 1;
		}
		if (a == 1 && b == 0 && c == 0) {
			vec[0].push_back(cost);
		}
		else if (a == 0 && b == 1 && c == 0) {
			vec[1].push_back(cost);
		}
		else if (a == 0 && b == 0 && c == 1) {
			vec[2].push_back(cost);
		}
		else if (a == 1 && b == 1 && c == 0) {
			vec[3].push_back(cost);
		}
		else if (a == 0 && b == 1 && c == 1) {
			vec[4].push_back(cost);
		}
		else if (a == 1 && b == 0 && c == 1) {
			vec[5].push_back(cost);
		}
		else if (a == 1 && b == 1 && c == 1) {
			vec[6].push_back(cost);
		}
	}
	vec_opt();
	ll res_c;
	if (vec[6].size() > 0) {
		res_c = vec[6][0];
	}
	else {
		res_c = INF;
	}
	if (vec[0].size() > 0 && vec[1].size() > 0 && vec[2].size()) {
		ll tmp = vec[0][0] + vec[1][0] + vec[2][0];
		if (tmp < res_c)
			res_c = tmp;
	}
	if (vec[0].size() > 0 && vec[4].size() > 0) {
		ll tmp = vec[0][0] + vec[4][0];
		if (tmp < res_c)
			res_c = tmp;
	}
	if (vec[1].size() > 0 && vec[5].size() > 0) {
		ll tmp = vec[1][0] + vec[5][0];
		if (tmp < res_c)
			res_c = tmp;
	}
	if (vec[2].size() > 0 && vec[3].size() > 0) {
		ll tmp = vec[2][0] + vec[3][0];
		if (tmp < res_c)
			res_c = tmp;
	}
	if (vec[3].size() > 0 && vec[4].size() > 0) {
		ll tmp = vec[3][0] + vec[4][0];
		if (tmp < res_c)
			res_c = tmp;
	}
	if (vec[3].size() > 0 && vec[5].size() > 0) {
		ll tmp = vec[3][0] + vec[5][0];
		if (tmp < res_c)
			res_c = tmp;
	}
	if (vec[4].size() > 0 && vec[5].size() > 0) {
		ll tmp = vec[4][0] + vec[5][0];
		if (tmp < res_c)
			res_c = tmp;
	}
	if (res_c == INF) {
		printf("-1");
	}
	else {
		printf("%lld", res_c);
	}
	return 0;
}

// number |= 1UL << n;

/*
Respect that, it should be a bitmask problem.
*/