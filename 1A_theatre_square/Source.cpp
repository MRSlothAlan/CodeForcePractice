#pragma warning (disable :4996)
#include <cstdio>
#include <cmath>

/*
Your logic is correct, but
-> use llu for getting values > 10^9, otherwise overflow
-> long long unsigned -> 64 bits of memory.
*/
int main() {
	__int64 n, m, a;	// overflow.
	scanf("%llu %llu %llu", &n, &m, &a);
	// let's try removing the double casting on a.
	__int64 w = (__int64)(ceil(n * 1.0 / a));
	__int64 h = (__int64)(ceil(m * 1.0 / a));
	printf("%llu\n", w * h);
	return 0;
}