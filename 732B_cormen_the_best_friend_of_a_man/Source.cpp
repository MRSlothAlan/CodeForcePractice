#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

/*
dog, needs k walks for any 2 con days.
e.g. k = 5, yesterday: walk 2 times
today : 3 times.
*/
int dis[600];

int main() {
	int n, k; scanf("%d %d", &n, &k);
	int prev, next;
	scanf("%d", &prev);
	dis[0] = prev;
	int res_steps = 0;
	for (int i = 1; i < n; i++) {
		scanf("%d", &next);
		if (prev + next < k) {
			res_steps += k - prev - next;
			next = k - prev;
		}
		dis[i] = next;
		prev = next;
	}
	printf("%d\n", res_steps);
	for (int i = 0; i < n; i++) {
		printf("%d ", dis[i]);
	}
	return 0;
}