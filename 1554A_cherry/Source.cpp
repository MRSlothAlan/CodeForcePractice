#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#define MAX(a, b) a > b ? a : b
typedef long long int lld;
const int MAX_ = 200000;
lld arr[MAX_];
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		lld n; scanf("%lld", &n);
		lld max_val = 0;
		scanf("%lld", &arr[0]);
		scanf("%lld", &arr[1]);
		max_val = arr[0] * arr[1];
		for (int i = 2; i < n; i++) {
			scanf("%lld", &arr[i]);
			max_val = MAX(max_val, arr[i] * arr[i - 1]);
		}
		printf("%lld\n", max_val);
	}
	return 0;
}
// find max min over all pairs of integers.


		/*
		lld max_val = 0;
		lld max_idx = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lld", &arr[i]);
			if (max_val < arr[i]) {
				max_val = arr[i]; max_idx = i;
			}
		}
		lld sec_max = 0;
		if (max_idx - 1 < 0) {
			sec_max = arr[max_idx + 1];
		}
		else if (max_idx + 1 >= n) {
			sec_max = arr[max_idx - 1];
		}
		else {
			sec_max = MAX(arr[max_idx - 1], arr[max_idx + 1]);
		}
		printf("%lld\n", max_val * sec_max);
		*/

/*
Do we really need to check all the subarrays?

Consider a subarray (ai,ai+1,…,aj). If we add a new element aj+1, 
when will the new subarray (ai,ai+1,…,aj,aj+1) give a better result? Pause and think.

The minimum of the new subarray can't get better(the minimum of a smaller subarray ≥ the minimum of a larger subarray). 
So only when aj+1 is greater than the previous maximum, then it will give a better result. 

But in that case, do we really need to check the whole subarray to get that result? 
Can we get the same or a better result from a smaller subarray? Think.

Here the maximum is aj+1. So if the minimum is not ai, then the subarray (ai+1,ai+2,…,aj+1) will give the same result. 
Otherwise, the minimum of (ai+1,ai+2,…,aj+1) will not be smaller which implies that (ai+1,ai+2,…,aj+1) will give a better result!

So if we add a new element, we don't have to check the whole subarray, checking (ai,ai+1,…,aj) and (ai+1,ai+2,…,aj+1) is enough.

What good this observation just brought to this world? Think.

Yes, we don't have to check subarrays with length >2, because according to the observation, (a1,a2,a3) won't give a better result than (a1,a2) and (a2,a3). And subarrays with length 4 won't give a better result than subarrays with length 3 and subarrays with length 3 won't give a better result than subarrays with length 2. You got the idea, right?

Another thing to notice here is that the product of maximum and minimum of two integers is just the product of two integers. 
So the answer to the problem is the maximum of the products of adjacent elements in a.

*/