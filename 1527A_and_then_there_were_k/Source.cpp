#pragma warning(disable : 4996)
/*
Let T= n & (n−1) & (n−2) & (n−3) & ... (k)

If there is at least one integer from K to N whose bit at the ith index is 0, 
then the value of the ith bit in T will also be 0. 

We can easily observe that the msb (Highest set bit in n) in N will become 0 for the first time when K=2msb−1. 
All the other bits will become zero when K=2msb.

Thus the answer is, K=2msb−1.
*/
#include <cstring>
#include <cstdio>
typedef long long int ll;
void solve()
{
	ll n;
	scanf("%lld", &n);
	ll cnt = 0;
	while (n != 0) {
		cnt++;
		n = n / 2;
	}
	ll res_val = (1 << (cnt - 1)) - 1;	// shift left by cnt bits -1, when perform bitwise &, guarentee that all = 0;
	printf("%lld\n", res_val);
}

int main() {
	int t; 
	scanf("%d", &t);
	while (t--) {
		solve();
	}
}