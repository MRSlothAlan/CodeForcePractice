#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
typedef long long int lld;
const lld MAX = 200000;
lld arr[MAX];
// get the size of the number
lld size_cnt[40];	// max possible value : 29

unsigned getSize(uint64_t tmp) {
	unsigned b = 0;
	while (tmp >>= 1) { b++; }
	return b;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		lld n; scanf("%lld", &n);
		memset(size_cnt, 0, sizeof(size_cnt));
		for (int i = 0; i < n; i++) {
			scanf("%lld", &arr[i]); arr[i] = getSize(arr[i]);
			size_cnt[arr[i]]++;
		}
		// a better way is needed to find the values of bit,
		// which is demo. in the note.
		lld res_cnt = 0;
		for (int i = 0; i < 29; i++) {
			res_cnt += size_cnt[i] * (size_cnt[i] - 1) / 2;
			// do you really know what that means?
			/*
			e.g. 1 1 1 1 1, 5 numbers, 10 patterns
			= (5 * 4) / 2, the general form.
			*/
		}
		printf("%lld\n", res_cnt);
	}
	return 0;
}

/*

		// the logic, you know it
		// but the problem is there are two for-loops.
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (arr[i] == arr[j]) {
					res_cnt++;
				}
			}
		}
*/

/*
if ((arr[i] & arr[j]) >=
	(arr[i] ^ arr[j])) {
	res_cnt++;
}
*/

/*
Let's take a pair (ai,aj) and see in which case ai & aj≥ai⊕aj will hold. 
For this we will follow the bits ai and aj from highest to lowest. 
If we meet two zero bits, the values of ai & aj and ai⊕aj will match in this bit, so we move on. 
If we meet a zero bit in ai and in aj —one bit(or vice versa), then we get ai & aj<ai⊕aj, 
and we can immediately say that the required condition is false. 
And if we meet two one bits, then the required condition is fulfilled,  e. ai & aj>ai⊕aj, and then the bits can no longer be considered.

Now let's consider the highest one bit in the number of ai (let it stand at pi position) and 
the highest single bit in the number of aj (let it stand at pj position). (Here, we consider that the bits are numbered in order of lowest to highest.) 
Then, pi=pj must hold. If pi>pj, then there is zero in the aj position and one unit in the ai position. 
But then from the reasoning above we get that ai & aj<ai⊕aj. The case of pi<pj is treated in a similar way.

It is also easy to see that if pi=pj then we automatically get the condition ai & aj>ai⊕aj.

From here the problem is solved. For each number we find the position of the highest one bit pi. 
Then we need to calculate the number of pairs of numbers, for which pi=pj. 
You may notice that the answer is ∑ℓkℓ⋅(kℓ−1)2, where kℓ — the number of numbers for which pi=pj.

The complexity of the solution is O(n).

*/