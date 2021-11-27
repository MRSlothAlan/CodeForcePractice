#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>

const int MAX = 1000000;
int arr[MAX];
// fence.
int main() {
	int n, k; scanf("%d %d", &n, &k);
	arr[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		// arr[i] += arr[i - 1];	// this approach sometimes fails since the diff can be small but the total magnitude can be huge.
	}
	int res_idx = 0;	
	int tmp_val = 0, min_val;
	for (int i = 1; i <= k; i++) {
		tmp_val += arr[i];
	}
	res_idx = 1; min_val = tmp_val;
	for (int i = k + 1; i <= n; i++) {
		tmp_val -= arr[i - k];
		tmp_val += arr[i];
		if (tmp_val < min_val) {
			min_val = tmp_val;
			res_idx = i - k + 1;
		}
	}
	printf("%d\n", res_idx);
	/*
	int min_diff = MAX;
	for (int i = 1; i <= n - k + 1; i++) {
		int j = i + k - 1;
		int diff = arr[j] - arr[i];
		if (diff < min_diff) {
			res_idx = i;
			min_diff = diff;
		}
	}
	*/
	return 0;
}
/*
Another easy problem. 
We need to calculate the sum of every consequtive segment of k planks. 
One way to do this is to calculate partial prefix sums: . 
Then the sum of heights of the planks i, i + 1, ..., i + k - 1 
is si + k - 1 - si - 1. 

The other approach is to calculate the sum of the first k planks: 
h1 + h2 + ... + hk. 
By subtracting h1 and adding hk + 1 we get sum of k planks starting from the second plank. 
Then, by subtracting h2 and adding hk + 2 we get sum of k planks starting from the third plank, and so on.
*/