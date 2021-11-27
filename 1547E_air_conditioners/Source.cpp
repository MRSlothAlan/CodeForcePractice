#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
/*
optimize the code by yourself.
*/
using namespace std;
typedef long long int lld;
const int MAX = 400000;
int pos[MAX];
lld temp;
lld result[MAX];

int main() {
	int q; scanf("%d", &q);
	while (q--) {
		int n, k; scanf("%d %d", &n, &k);
		for (int i = 0; i < k; i++) {
			scanf("%d", &pos[i]);
			pos[i]--;
		}
		int init_pos = pos[0];
		scanf("%lld", &temp);
		for (int i = 0; i < n; i++) {
			result[i] = temp + abs(i - init_pos);
		}
		for (int i = 1; i < k; i++) {
			scanf("%lld", &temp);
			init_pos = pos[i];
			for (int i = 0; i < n; i++) {
				result[i] = min(result[i], temp + abs(i - init_pos));
			}
		}
		for (int i = 0; i < n; i++) {
			printf("%lld ", result[i]);
		}
	}
	return 0;
}
