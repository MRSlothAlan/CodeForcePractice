#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <set>
typedef long long int lld;
using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		bool valid = true;
		for (int i = 0; i < n; i++) {
			lld val; scanf("%lld", &val);
			if (val < 0) {
				valid = false;
			}
		}
		if (valid) {
			printf("YES\n101\n");
			for (int num = 0; num <= 100; num++) {
				printf("%d ", num);
			}
			printf("\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}

/*
We first claim that if any negative number exists in a, then no solution exists. 
Denote p as the smallest number in a and q as another arbitrary number in the array (as n≥2, q always exists). 
Clearly, |q−p|=q−p>0. However, because p is negative, q−p>q. As such, adding q−p to the output array would create the pair (q−p,p) 
with difference q−2p>q−p. We have the same problem as before; thus, it is impossible to create a nice array if there exists a negative number 
in a.

After we deal with this case, we now claim that b=[0,1,2,...,100] is a valid nice array 
for any a that contains no negative numbers. It is easy to verify that this is a valid nice array. 
And since in this case, every element of a is nonnegative and distinct, it is always possible to rearrange and add elements to a to obtain b.
*/
/*
nice array?
e.g. 3 6 9
3 - 6, 6 - 9, 9 - 6
4 2 0 6 9 -> not nice, 5 not in array
3 0 9, 
*/