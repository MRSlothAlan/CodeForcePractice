#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <string>
typedef long long int lld;
const int MAX = 1500;
uint64_t peers[MAX];

int main() {
	// types of soldiers, from 0 to n - 1.
	int n, m, k; scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		scanf("%lld", &peers[i]);
	}
	// last one is Fedor
	scanf("%lld", &peers[m]);
	lld res_cnt = 0;
	for (int i = 0; i < m; i++) {
		lld diff = 0;
		bool f_a, f_b;
		for (int b = 0; b < n; b++) {
			if ((peers[i] >> b) & 1) { f_a = true; }
			else { f_a = false; }
			if ((peers[m] >> b) & 1) { f_b = true; }
			else { f_b = false; }
			if (f_a != f_b) {
				diff++;
			}
		}
		if (diff <= k) { res_cnt++; }
	}
	printf("%lld", res_cnt);
	return 0;
}

/*
type of soldiers, numbered from 0 to n - 1.
*/