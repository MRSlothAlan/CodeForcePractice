#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long int lld;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		lld in_val; scanf("%lld", &in_val);
		lld res = (lld)floor((in_val + 1) / 10);
		/*
		lld res;
		if (in_val < 9)
			res = 0;
		else {
			res = in_val / 10;
			if (res == 0)
				res = 1;
		}
		*/
		printf("%lld\n", res);
	}
	return 0;

/*
	S(322) = 7
	S(10) = 1

e.g. S(34)? only 3 cases:
	10 -> 9
	20 -> 19
	30 -> 29
	so, / 10 => 3.
interesting if S(x + 1) < S(x);
number of integers x, 1 <= x <= n, x is interesting?

Let's think: what properties do all interesting numbers have? Well, if a number x does not end with 9, we can say for sure that f(x+1)=f(x)+1, 
because the last digit will get increased. What if the number ends with 9? 
Then the last digit will become 0, so, no matter what happens to other digits, we can say that f(x+1) will surely be less than f(x).

So the problem asks us to count all numbers 1≤x≤n with the last digit equal to 9. It is not hard to see that the answer is equal to ⌊n+110⌋.

This concludes the solution, as we are now able to answer all testcases in O(1), resulting in total O(t) runtime.
*/

}