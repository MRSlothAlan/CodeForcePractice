#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int cost[200], 
	cnt_one[200], cnt_zero[200];

int main() {
	int n, B; scanf("%d %d", &n, &B);
	int cum_one = 0, cum_zero = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &cost[i]);
		if ((cost[i] & 1) == 0) { cum_zero++; }
		else { cum_one++; }
		cnt_one[i] = cum_one;
		cnt_zero[i] = cum_zero;
	}
	vector<int> cut;
	for (int i = 0; i < n - 1; i++) {	// no cut in the last element.
		if (cnt_one[i] == cnt_zero[i] && 
			cnt_one[n - 1] - cnt_one[i] == cnt_zero[n - 1] - cnt_zero[i]) {
			// cal. cost.
			int c = abs(cost[i] - cost[i + 1]);
			cut.push_back(c);
		}
	}
	int res_cnt = 0;
	sort(cut.begin(), cut.end());
	for (int c : cut) {
		if (B >= c) {
			B -= c; res_cnt++;
		}
		else {
			break;
		}
	}
	printf("%d", res_cnt);
	return 0;
}