#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

const int len = 110000;
int dp[len];
int rec[len];
set<int> S;

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int in_i; scanf("%d", &in_i);
		S.insert(in_i); rec[in_i]++; dp[i] = in_i;
	}
	int cnt = S.size();
	for (int i = 0; i < n; i++) {
		int cur_val = dp[i];
		rec[cur_val]--;
		if (rec[cur_val] == 0) { cnt--; }
		dp[i] = cnt;
	}
	while (m--) {
		int l; scanf("%d", &l);
		l -= 2;
		if (l < 0)
			printf("%d\n", S.size());
		else 
			printf("%d\n", dp[l]);
	}
	return 0;
}