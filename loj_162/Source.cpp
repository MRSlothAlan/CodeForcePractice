#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
typedef long long int ll;
// quick mod.
/*
concept : use the binary representation of the power
to multiply the numbers.
*/

/*
1) To find the last 3 digits, use %1000 and fast exponentiation of POWER(n,k);
2) To find the first digits? . We can write n^k as 10 pow( klog10n ). Klog10n has an integer part i and a decimal part d.
Since n^k is pow(10,i)*pow(10,d) , pow(10,i) cannot give you the first 3 digits ( Why? ) . 
The first 3 digitsis the first 3 digits of pow(10,d)!
*/
/*
will work on more problems in a new project.
*/
ll p = 998244352;
// well?
ll binpow(ll a, ll b) {
	a %= p;
	ll res = 1;
	while (b > 0) {
		if (b & 1) 
			res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}

int main() {
	// warm-ups.
	ll x, n; 
	// experiment
	ll val = 1ll;
	scanf("%lld %lld", &x, &n);
	n--;
	while (n--) {
		ll a; scanf("%lld", &a);
		printf("%lld ", binpow(x, a));
	}
	ll a; scanf("%lld", &a);
	printf("%lld", binpow(x, a));
	return 0;
}

/*
#include <cstdio>
const int N = 31610, p = 998244352;
int x, i, a[N + 10], b[N + 10];
int main() {
	scanf("%d", &x), a[0] = b[0] = 1;

	for (i = 1; i <= N; ++i)
		a[i] = a[i - 1] * 1ll * x % p;

	for (i = 1; i <= N; ++i)
		b[i] = b[i - 1] * 1ll * a[N] % p;

	for (scanf("%d", &i); i--;)
		scanf("%d", &x), printf("%d ", 1ll * a[x % N]*b[x / N] % p);
}
*/