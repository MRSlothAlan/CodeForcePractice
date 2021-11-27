#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
typedef long long int ll;
/*
bitwise XOR : ^.
*/
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		ll a, b; scanf("%lld %lld", &a, &b);
		// well,
		ll val = (a & b);
		ll res = (a ^ val) + (b ^ val);
		printf("%lld\n", res);
	}
	return 0;
}