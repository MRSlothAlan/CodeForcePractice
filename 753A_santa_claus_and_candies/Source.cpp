#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
// maximal number of kids which can get candies.
/*
each kid, get distinctive number of candies.
wrong answer Ded Moroz must give all his candies, ok I see.
*/
int main() {
	int n; scanf("%d", &n);
	int sum = 0;
	int cnt = 0;
	int val = 1;
	while (sum <= n) {
		cnt++;
		sum += val;
		val++;
	}
	cnt--;
	printf("%d\n", cnt);
	int v = 1; sum = 0;
	for (; v < cnt; v++) {
		printf("%d ", v);
		sum += v;
	}
	printf("%d\n", n - sum);
	return 0;
}