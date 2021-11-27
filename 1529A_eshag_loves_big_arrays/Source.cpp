#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		a.clear();
		int n; scanf("%d", &n);
		a = vector<int>(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a.begin(), a.end());
		int idx = a.size() - 1;
		int cnt = 0;
		while (true) {
			int cur_max = a[idx];
			int i = idx;
			for (; i >= 0 && a[i] >= cur_max; i--) {}
			if (i < 0) { break; }
			else {
				cnt += idx - i;
				idx = i;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}