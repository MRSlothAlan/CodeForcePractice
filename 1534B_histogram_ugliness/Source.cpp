#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lld;

const int MAX = 500000;
lld a[MAX];

int main() {
	int t; scanf("%d", &t);

	while (t--) {
		int n; scanf("%d", &n);
		for (int i = 0; i < MAX; i++) {
			a[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		lld answer = 0;
		// optimized version? How it works much faster than mine:
		for (int i = 1; i <= n; i++) {
			lld should = min(a[i], max(a[i-1], a[i+1]));
			answer += a[i] - should + abs(should - a[i - 1]);
			a[i] = should;
		}
		printf("%lld\n", answer + a[n]);
	}
	return 0;
}

/*
This version got time limit exceeded

while (t--) {
		peak.clear();
		int n; scanf("%d", &n);
		for (int i = 0; i < MAX; i++) {
			a[i] = 0; edges[i] = 0;
		}
		lld sum_edges = 0;
		// init.
		scanf("%lld", &a[1]);
		edges[1] = abs(a[1] - a[0]);
		sum_edges += edges[1];
		for (int i = 2; i <= n; i++) {
			scanf("%lld", &a[i]);
			if (a[i - 2] < a[i - 1] && a[i - 1] > a[i]) {
				peak.push_back(i - 1);
			}
			edges[i] = abs(a[i] - a[i - 1]);
			sum_edges += edges[i];
		}
		edges[n + 1] = abs(a[n + 1] - a[n]);
		sum_edges += edges[n + 1];
		if (a[n - 1] < a[n] && a[n] > a[n + 1]) {
			peak.push_back(n);
		}

		int interval = 2;
		lld opt = 0;
		// time limit exceeded.
		for (int p : peak) {
			int cost = min(edges[p], edges[p + 1]);
			opt += cost;
			sum_edges -= cost * 2;
		}
		printf("%d\n", sum_edges + opt);
	}
*/