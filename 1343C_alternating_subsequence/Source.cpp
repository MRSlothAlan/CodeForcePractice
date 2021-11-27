#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 300000;
long long int arr[MAX];

bool isPos(long long int in_n) {
	return in_n > 0 ? true : false;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) { scanf("%lld", &arr[i]); }
		int ptr = 0;
		bool chk_pos = arr[0] < 0 ? false : true;
		long long int tmp_opt = 0;	// no value equals 0.
		long long int res_sum = 0;
		while (ptr < n) {
			if (chk_pos) {
				tmp_opt = tmp_opt != 0 ? max(tmp_opt, arr[ptr]) : arr[ptr];
			}
			else {
				tmp_opt = tmp_opt != 0 ? max(tmp_opt, arr[ptr]) : arr[ptr];
			}
			ptr++;
			if (ptr >= n) {
				res_sum += tmp_opt;
				break;
			}
			else if (isPos(arr[ptr]) != chk_pos) {
				chk_pos = !chk_pos;
				res_sum += tmp_opt;
				tmp_opt = 0;
			}
		}
		printf("%lld\n", res_sum);
	}
	return 0;
}

// Oic, need to choose the max len alt seq first
/*
Firstly, let's extract maximum by inclusion segments 
of the array that consists of the numbers with the same sign. 
For example, if the array is [1,1,2,−1,−5,2,1,−3] then these 
segments are [1,1,2], [−1,−5], [2,1] and [−3]. 
We can do it with any "two pointers"-like algorithm. 
The number of these segments is the maximum possible length of the 
alternating subsequence because we can take only one element from each block. 
And as we want to maximize the sum, 
we need to take the maximum element from each block.
*/