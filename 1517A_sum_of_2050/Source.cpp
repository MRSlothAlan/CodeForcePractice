#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
typedef unsigned long long llu;
/*
proof:
any number, e.g. 5, 50, 500.
their sum must be divisible by 5.
*/
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		llu val; scanf("%llu", &val);
		if (val < 2050 || val % 2050 != 0) {
			printf("-1\n");
		}
		else {
			val /= 2050;
			llu sum = 0;
			while (val > 0) {
				sum += val % 10;
				val /= 10;
			}
			printf("%llu\n", sum);
		}
	}
	return 0;
}

/*
First, we need to check whether 
n is the multiple of 2050. If n is not the multiple of 2050, the answer is always −1.

Then we can divide n by 2050, 
the problem now is how to represent n as the 
sum of powers of 10. 

So the answer is the sum of its digits in decimal 
representation.
*/