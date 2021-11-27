#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
typedef unsigned long long int ll;
// triangluation, interesting.

int main() {
	int n; scanf("%d", &n);
	ll res = 6;	// init.
	for (int i = 4; i <= n; i++) {
		res += i * (i - 1);
	}
	printf("%u", res);
	return 0;
}