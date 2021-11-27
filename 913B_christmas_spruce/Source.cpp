#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
vector<int> tree[1050];
bool valid;
// starting from the basics(bottom) now we're in.
void basic(int p) {
	if (tree[p].size() == 0 || !valid)
		return;
	int cnt_lf_child = 0;
	for (int c : tree[p]) {
		if (tree[c].size() > 0)
			basic(c);
		else
			cnt_lf_child++;
	}
	if (cnt_lf_child < 3)
		valid = false;
	return;
}

int main() {
	valid = true;
	int n; scanf("%d", &n);
	for (int ith = 2; ith <= n; ith++) {
		int i_p; scanf("%d", &i_p);
		tree[i_p].push_back(ith);
	}
	basic(1);
	printf("%s", valid ? "Yes" : "No");
	return 0;
}

/*
other people's method, study after lunch break
I feel like this is better.

#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;

const int MAXN = 1001;

int a[MAXN];
bool b[MAXN];
int p[MAXN];

int main() {
#ifdef PAUNSVOKNO
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cout.tie(nullptr); cin.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		cin >> p[i];
	}

	for (int i = n; i >= 1; --i) {
		b[p[i]] = true;

		if (b[i]) {
			if (a[i] < 3) {
				cout << "No\n";
				return 0;
			}
		} else {
			a[p[i]]++;
		}
	}

	cout << "Yes\n";
}
*/