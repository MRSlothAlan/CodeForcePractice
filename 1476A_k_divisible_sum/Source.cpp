#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <math.h>
using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		long long int n, k; scanf("%lld %lld", &n, &k);
		long long int res = 0;
		/*
		if (n > k) {
			res = (long long int)ceil((double)n / (double)k);
		}
		else {
			res = (long long int)ceil((double)k / (double)n);
		}*/
		// well.
		long long int cf = floor((double)(n + k - 1) / (double)k);
		res = floor((double)(cf * k + n - 1) / (double)n);
		printf("%lld\n", res);
	}
	return 0;
}
/*
array of n possitive long long integers,
such that the sum (a1 + a2 + a3 ... + an)
is divisible by k, and max in a is minimum possible.

Let's denote s as the sum of array a. From one side, since s should be divisible by k then we can say s=cf⋅k. From other side, since all ai are positive, then s≥n.

It's quite obvious that the smaller s — the smaller maximum ai so we need to find the smallest cf that cf⋅k≥n. Then cf=⌈nk⌉=⌊n+k−1k⌋.

Now we now that s=cf⋅k and we need to represent it as a1+⋯+an with maximum ai minimized. It's easy to prove by contradiction that maximum ai≥⌈sn⌉.

Moreover we can always construct such array a that its sum is equal to s and the maximum element is equal to ⌈sn⌉.

As a result, the answer is ⌈sn⌉=⌊cf⋅k+n−1n⌋, where cf=⌊n+k−1k⌋.
*/