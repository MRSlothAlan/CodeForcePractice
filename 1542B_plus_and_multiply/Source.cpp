#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
typedef long long int lld;
lld n, a, b, m;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%lld %lld %lld", &n, &a, &b);
		if (a < 2)
			n = (n - 1) % b;	// reason: 1 * 1 * 1... + (x)b
		else
			for (m = 1; m <= n; m *= a) {
				if ((n - m) % b < 1)
					n = 0;
			}
		puts(n ? "No" : "Yes");
	}
	return 0;
}

/*
your method, time limit exceeded.
int t; scanf("%d", &t);
	while (t--) {
		lld n, a, b;
		scanf("%lld %lld %lld", &n, &a, &b);
		lld A = 1, tmp;
		bool valid = false;
		for (; A <= n && !valid; A *= a) {	// my logic
			tmp = n - A;
			if (tmp % b == 0) {
				valid = true;
				break;
			}
		}
		printf("%s\n", valid ? "Yes" : "No");
	}
*/


/*
1 is in the set
if x in this set, 
x * a and x + b both are in the set.

n in set?

First judge specially if b=1.

Let's consider when n is in S. 
The answer is when the smallest number 
	m in S that n mod b=m mod b 
is less than n. 

It's easy to see that a new case of x mod b can only appear when you use 
×a to generate a new element. So the smallest number m in S that m mod b=k must be a power of a.
Find all powers of a that is smaller than n. If there is one m=ak that n mod b=m mod b, the answer is yes. Otherwise it's no. Time complexity is O(logn).
*/